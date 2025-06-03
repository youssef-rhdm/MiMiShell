/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:39:28 by yrhandou          #+#    #+#             */
/*   Updated: 2025/06/03 16:40:12 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree *create_tree_node(int cmd_count)
{
	t_tree *head;

	if(!cmd_count)
		return (NULL);
	head = ft_calloc(1, sizeof(t_tree));
	if (!head)
		return (NULL);
	head->cmd = ft_calloc(cmd_count,sizeof(char **));
	if(!head->cmd)
		return (free(head),NULL);
	head->redirs = NULL;
	head->argc = cmd_count;
	head->left = NULL;
	head->right = NULL;
	return (head);
}

t_token *ft_token_search(t_token **head, t_types type)
{
	t_token	*current;

	current = *head;
	while(current)
	{
		if(current->type == type)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_redir *redir_maker(t_token *data)
{
	t_redir *redir;

	redir = ft_calloc(1, sizeof(t_redir));
	if(!redir)
		return (NULL);
	redir->fd = -1;
	redir->flag = 0;
	redir->iofile= data->next->value;
	redir->id = 0;
	redir->type = data->type;
	redir->next = (NULL);
	return (redir);
}

void link_redir(t_redir **list,t_redir *new_redir)
{
	t_redir *tmp;

	tmp = *list;
	if (!*list)
	{
		*list = new_redir;
		new_redir->next = NULL;
		new_redir->id = 0;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_redir;
	new_redir->id = tmp->id + 1;
	new_redir->next = NULL;
}


t_redir *redir_list_maker(t_token **head)
{
	t_token *tmp;
	t_redir *redir_list;

	redir_list = NULL;
	tmp = *head;

	while (tmp)
	{
		if (tmp->type >= REDIR_LEFT && tmp->type <= REDIR_HEREDOC)
			link_redir(&redir_list, redir_maker(tmp));
		tmp = tmp->next;
	}
	return redir_list;
}
