/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:50:58 by yrhandou          #+#    #+#             */
/*   Updated: 2025/06/03 11:57:33 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_syntax_err(char *str, t_token **head)
{
	ft_putstr_fd("DeepShell: syntax error near unexpected token `", 2);
	ft_putchar_fd(str[0], 2);
	ft_putendl_fd("'", 2);
	free_tokens(head);
	return 0;
}
// void free_tokens(t_token **head)
// {
// 	t_token *tmp;
// 	t_token *next;
// 	// ft_printf(MAG "Freeing Tokens !-------\n"RESET);
// 	tmp = *head;
// 	while (tmp)
// 	{
// 		next = tmp->next;
// 		free(tmp->value);
// 		free(tmp);
// 		(tmp) = next;
// 	}
// }

void free_tokens(t_token **head)
{
	t_token *tmp;
	// ft_printf(MAG "Freeing Tokens !-------\n"RESET);
	while ((*head))
	{
		tmp = (*head);
		free(tmp->value);
		free(tmp);
		(*head) = (*head)->next;
	}
}

void print_tokens(t_token **head)
{
	t_token *tmp;
	char * tiipe;
	t_token *test;

	test = ft_token_search(head, OR);
	tmp = *head;
	while (tmp)
	{
		if (tmp->type == OR )
			tiipe = "OR";
		else if (tmp->type == AND )
			tiipe = "AND";
		else if (tmp->type == REDIR_HEREDOC )
			tiipe = "REDIR_HEREDOC";
		else if (tmp->type == REDIR_APPEND )
			tiipe = "REDIR_APPEND";
		else if (tmp->type == PIPE )
			tiipe = "PIPE";
		else if (tmp->type == REDIR_LEFT )
			tiipe = "REDIR_LEFT";
		else if (tmp->type == REDIR_RIGHT)
			tiipe = "REDIR_RIGHT";
		else if (tmp->type == INFILE)
			tiipe = "INFILE";
		else if (tmp->type == OUTFILE)
			tiipe = "OUTFILE";
		else if (tmp->type == ARG)
			tiipe = "ARG";
		else
			tiipe = "WORD";

		ft_printf(GRN"value : {%s}, type? : {%s}->{%d} , position : <%d>\n" RESET, (tmp)->value, tiipe , (tmp)->type, tmp->position);
		// if(tmp->prev != NULL && tmp->prev->value)
		// ft_printf("the one before the element %s, is %s", tmp->value , ÷tmp->prev->value);
		tmp = (tmp)->next;
	}
}
