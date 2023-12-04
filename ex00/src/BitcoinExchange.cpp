/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/04 16:35:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include <fstream>

std::map<struct s_date, float> BitcoinExchange::_bitcoinExchangeDatabase = \
	Database::initDatabase("./database.csv");

std::map<std::string, std::string> BitcoinExchange::_bitcoinExchangeInput;

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	this->_bitcoinExchangeDatabase = cpy._bitcoinExchangeDatabase;
	this->_bitcoinExchangeInput = cpy._bitcoinExchangeInput;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_bitcoinExchangeDatabase = rhs._bitcoinExchangeDatabase;
		this->_bitcoinExchangeInput = rhs._bitcoinExchangeInput;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

Database::eErrCode	BitcoinExchange::applyBitcoinExchange(std::string infile)
{
	std::string line;
	if (BitcoinExchange::_bitcoinExchangeDatabase.empty())
		return (Database::eErrCode::DATABASE_FILE_FAIL);
	//check input file
	std::ifstream ifs(infile);
	// if (!ifs)
	// 	return (Database::fileErrCode::INPUT_FILE_FAIL);
	BitcoinExchange::_bitcoinExchangeInput = Database::initInput(ifs);
	if (BitcoinExchange::_bitcoinExchangeInput.empty())
		return (Database::eErrCode::INPUT_FILE_FAIL);
	//check if input is valid
	//if not return error code
	//if valid
	//calculate
	//return result
	return (Database::fileErrCode::DATABASE_OK);
}