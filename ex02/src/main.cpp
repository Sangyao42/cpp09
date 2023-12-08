/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:14:19 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 22:24:06 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "No arguments given" << std::endl;
		return (EXIT_FAILURE);
	}
	if (Parser::isValid(*(argv++)))
	{
		PMergeMe::sort(*(argv++));
	}
	return (0);
}