/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:14:19 by sawang            #+#    #+#             */
/*   Updated: 2023/12/10 20:48:41 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Parser.hpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "No arguments given" << std::endl;
		return (EXIT_FAILURE);
	}
	if (Parser::isValid(++argv) == false)
		return (EXIT_FAILURE);
	PmergeMe pmergeMe(argc - 1, argv);
	pmergeMe.printCompare();
	return (0);
}