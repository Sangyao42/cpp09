/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:18 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 17:14:44 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./bitcoin [input file]" << std::endl;
		return (1);
	}
	eErrCode err = BitcoinExchange::applyBitcoinExchange(argv[1]);
	if (err != DATABASE_OK)
		Database::errPrint(err);
	return (err);
}