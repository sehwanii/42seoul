/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:53:57 by taerakim          #+#    #+#             */
/*   Updated: 2024/05/30 16:15:46 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_BONUS_H
# define EXPAND_BONUS_H

# include "tokenizer_bonus.h"
# include "syntax_tree_bonus.h"
# include "envlist_bonus.h"

/* ******************************** TYPEDEF ********************************* */
typedef enum e_ex_status
{
	keep_going,
	not_more,
	finish,
	find
}	t_ex_status;

typedef enum e_quote
{
	q_not,
	q_single,
	q_double
}	t_quote;

typedef struct s_wildcard
{
	t_quote	quote;
	int		keepflag;
}			t_wildcard;

/* ******************************* FUNCTIONS ******************************** */
int		expand(t_syntax_tree *command, t_env *env);
t_list	*expand_one_word(char *str, t_env *env);
void	expand_variable(t_token *token, t_env *env);
void	_remove_quote(t_token *token);
int		more_split(t_list *token);

#endif