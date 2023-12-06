/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:18 by sawang            #+#    #+#             */
/*   Updated: 2023/12/06 14:41:30 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (INPUT_FILE_FAIL);
	}
	eErrCode err = BitcoinExchange::applyBitcoinExchange(argv[1]);
	if (err != SUCCESS && err != INPUT_INVALID)
		Database::errPrint(err);
	return (err);
}