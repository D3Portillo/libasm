/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:05:32 by dcerrito          #+#    #+#             */
/*   Updated: 2022/10/05 16:12:38 by dcerrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

static void	runif(char *fn_name, char *fn_arg, void fn(void), char **status)
{
	if (fn_arg == NULL)
		return (fn());
	if (strcmp(fn_name, fn_arg) == 0)
		return ((*status = SUCCESS), fn());
	if (*status != SUCCESS)
		*status = NO_FUNCTION_FOUND;
}

int	main(int argc, char **argv)
{
	char	*fn_arg;
	char	*status;

	fn_arg = ((status = NULL));
	if (argc > 1)
		fn_arg = argv[1];
	runif("strcmp", fn_arg, ft_strcmp_test, &status);
	runif("strcpy", fn_arg, ft_strcpy_test, &status);
	runif("strlen", fn_arg, ft_strlen_test, &status);
	if (status != SUCCESS)
		printf("%s\n", status);
	return (0);
}
