/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:37:33 by sawang            #+#    #+#             */
/*   Updated: 2023/12/10 18:54:49 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

bool	Parser::isValid(char **arg)
{
	long int num;
	char *endptr;

	while (*arg)
	{
		num = strtol(*arg, &endptr, 10);
		if (num <= 0 || num > INT_MAX || *endptr != '\0')
		{
			std::cout << "Invalid argument" << std::endl;
			return (false);
		}
		arg++;
	}
	return (true);
}
