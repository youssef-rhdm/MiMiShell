/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:34:48 by yrhandou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/04/26 14:56:15 by yrhandou         ###   ########.fr       */
=======
/*   Updated: 2025/04/21 19:39:13 by yrhandou         ###   ########.fr       */
>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "coreutils/libft.h"

int ft_str_is_x(char *str, int(f)(int c))
{
<<<<<<< HEAD
	int i = 0;
	while (str[i] != '\0')
	{
		if (!f(str[i]))
			return 0;
		i++;
	}
	return 1;
}




int token_counter(char *s, char delimiter)
{
	int i;
	int j;
	int counter;
=======
	size_t i;
	size_t j;
	size_t counter;
	char * delimiters;

	delimiters = "";
	int *delimiters_counter;

	delimiters_counter = malloc(sizeof(int));
	if(delimiters)
		return 0;
>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4
	char *str;
	i = 0;
	j = 0;
	counter = 0;
	str = s;
	while (1)
	{
<<<<<<< HEAD
		str = ft_strchr(str, delimiter);
		if (!str)
			break;
=======

>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4
		counter++;
		str++;
	}
	free(delimiters);
	return counter;
}

<<<<<<< HEAD


int main(int argc, char *argv[])
{
	int i = 0;
	int token_count = token_counter(argv[1], '|');
	t_token **tokens = malloc(sizeof(t_token)* token_count);
	if(!tokens)
		return 1;
	char **sub_tokens = ft_split(argv[1],' ');
	if(!sub_tokens)
		return free_arr((void **)tokens), 0;
	while(tokens[i])
	{
		tokens[i]->command->argv = sub_tokens[i];
		tokens[i]->type = "sub_tokens";
		i++;
	}
	printf("%d",token_count);
	// while(i<5)
	// printf("%s\n", lexer(" ls -al| 4>  s ")[i++]);
	return 0;
=======
// int lexer(char *str)
// {
	// 	size_t i;
	// 	size_t j;
	// 	t_token *tokens;
// 	size_t token_count;
// 	token_count = 0;
	// tokens = malloc(sizeof(t_token));
	// if(!tokens)
	// 	return 0;
// 	i = 0;
// 	j = 0;
// 	char **sub_tokens = ft_split(str, ' ');
// 	if (!sub_tokens)
// 		return 0;
// 	while (sub_tokens[i][j])
// 	{
// 		while (sub_tokens[i][j])
// 		{
// 			if (ft_isalpha(sub_tokens[i][j]))
// 				j++;
// 			else if (sub_tokens[i][0] == '-')
// 			{
// 				if (ft_isalpha(sub_tokens[i][j]))
// 				j++
// 			}
// 		}
// 		i++;
// 	}
// 	i++;
// 	token_count++; 
// 	if (str[i] == '-')
// 	{
// 		while (ft_isalpha(str[i]))
// 			i++;
// 		token_count++;
// 	}
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return i;
// }

int main(void)
{
	char *str;

	printf("%zu\n", token_counter(" ls -al | grep '.' > txtfile"));
>>>>>>> a63dcefe0f7146106df1df0bc7e118cc4214ecf4
}
// char ** lexer(char *str)
// {
// 	int i;
// 	int j;
// 	t_token *tokens;
// 	int token_count;// 	token_count = 0;// 	// tokens = malloc(sizeof(t_token));
// 	// if(!tokens)
// 	// 	return 0;
// 	i = 0;
// 	j = 0;
// 	char **sub_tokens = ft_split(str, ' ');
// 	if (!sub_tokens)
// 		return NULL;
// 	while (sub_tokens[i][j])
// 	{
// 		while (sub_tokens[i][j])
// 		{
// 			if (ft_str_has_x)
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	// i++;
// 	// token_count++;
// 	// while (str[i])
// 	// {
// 	// 	i++;
// 	// }
// 	return sub_tokens;
// }
// t_token *create_token(t_cmd command, char *type)
// {
// 	t_token *tkn;
// 	tkn = malloc(sizeof(t_token));
// }
