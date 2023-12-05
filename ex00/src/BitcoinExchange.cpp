/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 23:00:28 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include "Input.hpp"
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
	// std::map<std::string, std::string> input;
	std::pair<eInputErr, std::pair<std::string, float> > inputPair;
	eErrCode err = SUCCESS;
	struct tm tmInfo;
	time_t date;

	if (BitcoinExchange::_bitcoinExchangeDatabase.empty())
		return (DATABASE_FILE_FAIL);
	//check input file
	std::ifstream ifs(infile);
	std::getline(ifs, line); //skip the first line
	if (ifs.bad())
	{
		ifs.close();
		return (INPUT_FILE_FAIL);
	}
	while (std::getline(ifs, line))
	{
		inputPair = Input::parseInputOneLine(line);
		if (inputPair.first != INPUT_OK)
		{
			Input::errPrint(inputPair.first);
			err = INPUT_INVALID;
		}
		else
		{
			//calculate
			//print result
			strptime(inputPair.second.first.c_str(), DATE_FORMAT, &tmInfo);
			date = mktime(&tmInfo);
			if (date < BitcoinExchange::_bitcoinExchangeDatabase.begin()->first)
			{
				Input::errPrint(INPUT_DATE_TOO_EARLY);
				err = INPUT_INVALID;
			}
			else
			{
				BitcoinExchange::printExchange(date, inputPair.second.second);
				err = SUCCESS;
			}
		}
	}
	if (ifs.bad())
	{
		ifs.close();
		return (INPUT_FILE_FAIL);
	}
	return (err);
}