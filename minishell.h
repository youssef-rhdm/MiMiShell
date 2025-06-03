/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:10:02 by yrhandou          #+#    #+#             */
/*   Updated: 2025/06/03 16:40:05 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef enum e_token_types
{
	WORD = 1,
	ARG,
	AND,
	OR,
	PIPE,
	REDIR_LEFT,
	REDIR_RIGHT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	INFILE,
	OUTFILE
} t_types;
typedef struct s_redir
{
	int				id;
	t_types			type;
	char			*iofile;
	int				fd;
	int				flag;
	struct s_redir	*next;
} t_redir;

typedef struct s_tree
{
	char			**cmd;
	size_t			argc;
	t_redir			*redirs;
	struct s_tree	*left;
	struct s_tree	*right;
} t_tree;


typedef struct s_token
{
	size_t			position;
	char			*value;
	t_types			type;
	struct s_token	*next;
	struct s_token	*prev;
} t_token;

typedef enum e_token_type
{
	TOKEN_PAREN_LEFT,
	TOKEN_PAREN_RIGHT,
	TOKEN_EOF,
	TOKEN_INVALID
} t_token_type;

// typedef enum e_redir_type
// {
// 	REDIR_IN,
// 	REDIR_OUT,
// 	REDIR_APPEND,
// 	REDIR_HEREDOC,
// 	REDIR_NONE
// } t_redir_type;

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_PARENTHS
} t_node_type;


// typedef struct s_tree
// {
// 	t_node_type type;
// 	char **cmd;
// 	t_redir *redirs;
// 	t_redir *redirs_before;
// 	t_redir *redirs_after;
// 	int is_ambiguous;
// } t_tree;

t_token *ft_token_search(t_token **head, t_types type);
void link_redir(t_redir **list, t_redir *new_redir);
int handle_quotes(char *str, char quote_type);
int ft_before_x(char *str, int (*f)(char *s));
int ft_syntax_err(char *str, t_token **head);
int lexer(t_token **head, char *line_read);
void advanced_token_lexer(t_token **head);
t_redir *redir_list_maker(t_token **head);
t_redir *redir_maker(t_token *data);
int ft_is_bonus_operator(char *str);
int ft_syntax_analyzer(char *str);
int handle_parentheses(char *str);
void print_tokens(t_token **head);
void free_tokens(t_token **head);
t_tree *create_tree_node(int cmd_count);
int ft_isparentheses(char *c);
int ft_is_operator(char *c);
int operator_len(char *str);
int token_lexer(char *str);
int parser(t_token **head);
int skip_spaces(char *str);
int count_chars(char *str);
int ft_is_redir(char *c);
char ft_isquote(char c);
#endif
