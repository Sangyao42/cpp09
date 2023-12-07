/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 13:36:37 by sawang           ###   ########.fr       */
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
	std::pair<eInputErr, std::pair<std::string, std::string> > inputPair;
	eErrCode err = SUCCESS;
	eInputErr inputErr = INPUT_OK;

	if (BitcoinExchange::_bitcoinExchangeDatabase.empty())
		return (DATABASE_INVALID);
	std::ifstream ifs(infile.c_str(), std::ifstream::in);
	if (!ifs.is_open())
		return (INPUT_FILE_FAIL);
	std::getline(ifs, line); //skip the first line
	if (ifs.bad())
	{
		ifs.close();
		return (INPUT_FILE_FAIL);
	}
	if (ifs.eof())
	{
		ifs.close();
		return (INPUT_FILE_EMPTY);
	}
	while (std::getline(ifs, line))
	{
		inputPair = Input::parseInputOneLine(line);
		if (inputPair.first != INPUT_OK)
		{
			Input::errPrint(inputPair.first, line);
			err = std::max(INPUT_INVALID, err);
		}
		else
		{
			inputErr = BitcoinExchange::calculateExchange(inputPair.second);
			if (inputErr != INPUT_OK)
			{
				Input::errPrint(inputErr, line);
				err = std::max(INPUT_INVALID, err);
			}
			else
				err = std::max(SUCCESS, err);
		}
	}
	if (ifs.bad())
	{
		ifs.close();
		return (INPUT_FILE_FAIL);
	}
	return (err);
}

eInputErr	BitcoinExchange::calculateExchange(std::pair<std::string, std::string> inputPair)
{
	struct tm tmInfo;
	time_t date;
	float priceAfterExchange;

	memset(&tmInfo, 0, sizeof(struct tm));
	strptime(inputPair.first.c_str(), DATE_FORMAT, &tmInfo);
	date = mktime(&tmInfo);
	if (date < BitcoinExchange::_bitcoinExchangeDatabase.begin()->first)
		return (INPUT_DATE_TOO_EARLY);
	std::map<time_t, float>::iterator it = BitcoinExchange::_bitcoinExchangeDatabase.begin();
	while (it != BitcoinExchange::_bitcoinExchangeDatabase.end() && it->first <= date)
	{
		it++;
	}
	--it;
	priceAfterExchange = static_cast<float>(strtod(inputPair.second.c_str(), NULL)) * it->second;
	BitcoinExchange::printExchange(inputPair, priceAfterExchange);
	return (INPUT_OK);
}

void	BitcoinExchange::printExchange(std::pair<std::string, std::string> inputPair, float priceAfterExchange)
{
	std::cout << inputPair.first << " => ";
	std::cout << inputPair.second << " = ";
	std::cout << std::fixed << std::setprecision(2) << priceAfterExchange << std::endl;
}
