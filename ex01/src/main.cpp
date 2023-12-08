/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:03:37 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 16:55:36 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Calculator.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN  <Reverse Polish Notion>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		Calculator::calcRPN(argv[1]);
		return (EXIT_SUCCESS);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
}