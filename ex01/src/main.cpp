/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:03:37 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 14:32:59 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN  <Reverse Polish Notion>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		RPN::calcRPN(argv[1]);
		return (EXIT_SUCCESS);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
}