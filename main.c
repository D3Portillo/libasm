/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:05:32 by dcerrito          #+#    #+#             */
/*   Updated: 2022/10/05 14:06:49 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

static void	execute(void fn(void), int run_all, char *arg, char *fn_name)
{
	if (run_all || !strcmp(fn_name, arg))
		fn();
}

int	main(int argc, char **argv)
{
	char	*fn_name;
	int		run_all;

	run_all = argc == 1;
	fn_name = NULL;
	if (argc > 1)
		fn_name = argv[1];
	execute(ft_strcmp_test, run_all, "strcmp", fn_name);
	execute(ft_strcpy_test, run_all, "strcpy", fn_name);
	execute(ft_strlen_test, run_all, "strlen", fn_name);
	return (0);
}
