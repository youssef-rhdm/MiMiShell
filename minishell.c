/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:11:48 by yrhandou          #+#    #+#             */
/*   Updated: 2025/06/03 17:35:06 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void quote_expander_v0(t_token **head)
{
	t_token *current;
	int position;
	int i;
	char quote;
	int count;
	char *expanded_token;
	// char *tmp;

	i = 0;
	current = *head;

	while (current && current->value[i])
	{
		quote = ft_isquote(current->value[i]);
		if (quote)
		{
			position = i;
			count = 0;
		}
		ft_printf("char count in %s is %d\n", current->value, count);
		expanded_token = ft_calloc(ft_strlen(current->value) - count,  sizeof(char));
		if (!expanded_token)
			return free_tokens(head), ft_putendl_fd("MALLOC FAILURE", 2);
		count = 0;
		while (current->value[position] && current->value[position] != quote)
			expanded_token[count++] = current->value[position++];
		// current->value= expanded_token;
		free(expanded_token);
		i = position; // ? calculate the len of the string minus the commanding quote count then skip the commanding quotes and extract the content
		ft_printf(BHBLU "Result : <%s>\n", expanded_token);
	}
	current = current->next;
}
void quote_expander(t_token **head)
{
	t_token *current;
	int position;
	int i;
	char quote;
	char *expanded_token;

	i = 0;
	position = 0;
	current = *head;
	while (current)
	{
		if (ft_strchr(current->value, '\"') == NULL && ft_strchr(current->value, '\'') == NULL)
		{
			current = current->next;
			continue;
		}
		expanded_token = ft_calloc(ft_strlen(current->value) + 1 , sizeof(char));
		if (!expanded_token)
			return free_tokens(head), ft_putendl_fd("MALLOC FAILURE", 2);
		while(current->value[i])
		{

		quote = ft_isquote(current->value[i]);
		if (quote != '\0')
		{
			i++;
			while (current->value[i] && current->value[i] != quote)
				expanded_token[position++] = current->value[i++];
			if (current->value[i] == quote)
				i++;
		}
		else
			expanded_token[position++] = current->value[i++];
		}
		if(expanded_token)
		{
			free(current->value);
			current->value = expanded_token;
		}
		current = current->next;
	}
}
void advanced_token_lexer(t_token **head)
{
	t_token *current;

	current = *head;
	while (current && current->next)
	{
		if(current->type == REDIR_HEREDOC || current->type == REDIR_LEFT)
			current->next->type = INFILE;
		if (current->type== REDIR_RIGHT || current->type == REDIR_APPEND)
			current->next->type = OUTFILE;
		if ((current->type == WORD || current->type == ARG || current->type == INFILE || current->type == OUTFILE) && current->next->type == WORD)
			current->next->type = ARG;
		current = current->next;
	}
}
int parser(t_token **head)
{
	t_token *current;

	current = *head;
	if (!current)
		return 0;
	if (ft_is_bonus_operator(current->value) || (current->type == PIPE))
		return ft_syntax_err(current->value, head);
	while (current)
	{
		if (ft_is_operator(current->value) && !current->next)
			return ft_syntax_err(current->value, head);
		if (ft_is_redir(current->value) && ft_isparentheses(current->next->value))
			return ft_syntax_err(current->value, head);
		current = current->next;
	}
	advanced_token_lexer(head);
	// quote_expander(head);
	return 1;
}
void token_iterate(t_token **head, void(f)(t_token *str))
{
	t_token *current;
	// int		status;

	current = *head;
	while (current)
	{
		f(current);
		current = current->next;
	}
}
char **command_linker(t_token **head, int count)
{
	char **cmd;
	int i;
	t_token *current;

	i = 0;
	if (!count)
		return NULL;
	cmd = ft_calloc(count,  sizeof(char *));
	if (!cmd)
		return 0;
	current = *head;
	while (i < count)
	{
		cmd[i] = ft_strdup(current->value);
		current = current->next;
		i++;
	}
	return (cmd);
}

int block_arg_counter(t_token **head)
{
	t_token	*current;
	int		count;

	count = 0;
	current = *head;
	while (current)
	{
		if (current->type == AND || current->type == PIPE || current->type == OR)
			break;
		else if(current->type >= REDIR_LEFT)
		{
			current = current->next;
			continue;
		}
		count++;
		current = current->next;
	}
	return count;
}
void f(){system("leaks -q minishell");}
void print_tree(t_tree *tree, int arg_count)
{
	int i;

	i = 0;
	if (!tree)
		return;
	printf("Command is : ");
	while (i < arg_count)
		printf(BHGRN "<%s> " RESET, tree->cmd[i++]);
	printf("\n");
	printf("Argc : %zu\n", tree->argc);

	if (tree->redirs)
	{
		printf(BLU "Redirs :");
		while (tree->redirs)
		{
			printf("{%d}[%d][%s] , ",tree->redirs->id, tree->redirs->type, tree->redirs->iofile);
			tree->redirs = tree->redirs->next;
		}
		printf(RESET "}\n");
	}
}
t_tree *create_block(t_token **head, int count)
{
	t_tree *tree;
	int i;
	t_token *current;

	i = 0;
	tree = create_tree_node(count);
	if(!tree)
		return NULL;
	tree->redirs = redir_list_maker(head);
	if(!tree->redirs)
		printf("NO REDIRECTIONS FOR YOU MY BOY\n");
	current = *head;
	while (current && i < count)
	{
		if (current->type < REDIR_LEFT)
			tree->cmd[i++] = ft_strdup(current->value);
		current = current->next;
	}
	return (tree);
}





int main()
{
	t_tree	*tree;
	int count;
	char *line;
	t_token *head;

	head = NULL;
	while (1)
	{
		line = readline(BHBLU"DeepShell$>"RESET);
		// line = ft_strdup("ls -al > file pwd | pops");
		if (!line || !lexer(&head, line) || !parser(&head))
		{
			add_history(line);
			continue;
		}
		count = block_arg_counter(&head);
		tree = create_block(&head,count);
		print_tree(tree, count);
		print_tokens(&head);
		add_history(line);
		free_tokens(&head);
		// if(ft_strnstr(line, "check_leaks", ft_strlen(line)))
		// 	{break;
		// free(line);}
		free(line);
	}
	return 0;
}
