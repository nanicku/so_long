/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:35:10 by mshad             #+#    #+#             */
/*   Updated: 2021/12/09 11:20:08 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *message)
{
	ft_putstr_fd("\033[91mError\n", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

void	win_exit(void)
{
	ft_putstr_fd("\033[92mСongratulations! You win!\n", 1);
	exit(0);
}

void	die_exit(void)
{
	ft_putstr_fd("\033[91mСongratulations! You died!\n", 1);
	exit(0);
}
