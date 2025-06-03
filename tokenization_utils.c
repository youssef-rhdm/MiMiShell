/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:19:50 by yrhandou          #+#    #+#             */
/*   Updated: 2025/06/02 22:49:57 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_lexer(char *str)
{
	int	operator_length;

	operator_length = ft_is_operator(str);
	if (operator_length == 2)
	{
		if (str[0] == '|')
			return ((OR));
		if (str[0] == '&')
			return ((AND));
		if (str[0] == '<')
			return ((REDIR_HEREDOC));
		if (str[0] == '>')
			return ((REDIR_APPEND));
	}
	else if (operator_length == 1)
	{
		if (str[0] == '|')
			return ((PIPE));
		if (str[0] == '<')
			return ((REDIR_LEFT));
		if (str[0] == '>')
			return ((REDIR_RIGHT));
	}
	return ((WORD));
}

int	ft_special_case(char *str, int type)
{
	int	new_type;

	new_type = token_lexer(&str[skip_spaces(str)]);
	if ((type < REDIR_LEFT || type > REDIR_HEREDOC) && ( new_type >= REDIR_LEFT  && new_type <= REDIR_HEREDOC  )) // todo fix later range of enums
		return (1);
	return (0);
}
int	operator_len(char *str)
{
	int		i;
	int		len;
	int		type;

	i = 0;
	len = ft_is_operator(&str[i]);
	if(!len)
		return (0);
	type = token_lexer(&str[i]);
	i += len; // if(!str[i]) 	return 0;
	len = i;
	while(str[len])
	{
		if((ft_special_case(&str[len],type)))
			break;
		else if (ft_before_x(&str[len], ft_is_operator))
			return 0;
		else if (!ft_isspace(str[len]))
			break;
		len++;
	}
	return (i);
}

void	link_token(t_token **head, t_token *node)
{
	t_token	*tmp;

	tmp = *head;
	if (!*head)
	{
		*head = node;
		node->next = NULL;
		node->prev = NULL;
		node->position = 0;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->position = tmp->position + 1;
	node->next = NULL;
	node->prev = tmp;
}

t_token	*new_token(char *value, int type)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	token->prev = NULL;
	token->position = -1;
	return (token);
}

int	lexer(t_token **head, char *line_read)
{
	int	i;
	int	token_len;
	int	position;

	i = 0;
	token_len = 0;
	while (line_read[i])
	{
		i += skip_spaces(&line_read[i]);
		position = i;
		token_len = count_chars(&line_read[i]);
		if (!token_len)
			token_len = operator_len((char *)&line_read[i]);
		if (!token_len)
			return (ft_syntax_err(&line_read[i], head));
		link_token(head, new_token(ft_substr(line_read, position, token_len), \
		token_lexer(&line_read[position])));
		i += token_len;
		position = i;
		if (ft_str_isspace(&line_read[i]))
			break ;
	}
	return (1);
}
