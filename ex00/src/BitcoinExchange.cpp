/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 17:27:39 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include <fstream>

std::map<time_t, float> BitcoinExchange::_bitcoinExchangeDatabase = \
	Database::initDatabase("data.csv");

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	this->_bitcoinExchangeDatabase = cpy._bitcoinExchangeDatabase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_bitcoinExchangeDatabase = rhs._bitcoinExchangeDatabase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

eErrCode	BitcoinExchange::applyBitcoinExchange(std::string infile)
{
	std::string line;
	if (BitcoinExchange::_bitcoinExchangeDatabase.empty())
		return (DATABASE_FILE_FAIL);
	//check input file
	std::ifstream ifs(infile);
	if (!ifs)
		return (INPUT_FILE_FAIL);
	//check if input is valid
	//if not return error code
	//if valid
	//calculate
	//return result
	return (DATABASE_OK);
}