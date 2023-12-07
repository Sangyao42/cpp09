/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:09:36 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 13:55:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include "Parser.hpp"
#include "Database.hpp"
#include "BitcoinExchange.hpp"
#include <cstring>
#include <cstdlib>


std::pair<eInputErr, std::pair<std::string, std::string> >	Input::parseInputOneLine(std::string &inputLine)
{
	size_t pos = 0;
	std::pair<eInputErr, std::string> date;
	std::pair<eInputErr, std::string> price;

	if (inputLine.empty())
		return (std::make_pair(INPUT_LINE_EMPTY, std::make_pair("", "")));
	pos = inputLine.find("|");
	if (pos == std::string::npos)
	{
		Parser::trimWhitespace(inputLine);
		if (inputLine.empty())
			return (std::make_pair(INPUT_LINE_EMPTY, std::make_pair("", "")));
		else
			return (std::make_pair(INPUT_FORMAT_INVALID, std::make_pair("", "")));
	}
	else
	{
		std::string s1 = inputLine.substr(0, pos);
		std::string s2 = inputLine.substr(pos + 1);
		Parser::trimWhitespace(s1);
		Parser::trimWhitespace(s2);
		date = Input::parseDate(s1);
		if (date.first != INPUT_DATE_OK)
			return (std::make_pair(date.first, std::make_pair("", "")));
		price = Input::parsePrice(s2);
		if (price.first != INPUT_PRICE_OK)
			return (std::make_pair(price.first, std::make_pair("", "")));
		return (std::make_pair(INPUT_OK, std::make_pair(date.second, price.second)));
	}
}

std::pair<eInputErr, std::string>	Input::parseDate(std::string inputDate)
{
	struct tm tmInfo;
	char *valid;

	memset(&tmInfo, 0, sizeof(struct tm));
	if (inputDate.empty())
		return (std::make_pair(INPUT_DATE_INVALID, ""));
	valid = strptime(inputDate.c_str(), DATE_FORMAT, &tmInfo);
	if (valid == NULL || *valid != '\0')
		return (std::make_pair(INPUT_DATE_INVALID, ""));
	if (Parser::dateIsValid(&tmInfo) == false)
		return (std::make_pair(INPUT_DATE_INVALID, ""));
	return (std::make_pair(INPUT_DATE_OK, inputDate));
}

std::pair<eInputErr, std::string>	Input::parsePrice(std::string inputPrice)
{
	double price;
	
	if (Parser::priceIsValid(inputPrice) == false)
		return (std::make_pair(INPUT_PRICE_INVALID, ""));
	price = strtod(inputPrice.c_str(), NULL);
	if (price < 0)
		return (std::make_pair(INPUT_PRICE_NEGATIVE, ""));
	if (price > 1000)
		return (std::make_pair(INPUT_PRICE_TOO_LARGE, ""));
	return (std::make_pair(INPUT_PRICE_OK, inputPrice));
}

void	Input::errPrint(eInputErr inputErr, std::string line)
{
	std::cout << "Error: ";
	switch (inputErr)
	{
		case INPUT_LINE_EMPTY:
			std::cout << "Input line is empty" << std::endl;
			break;
		case INPUT_FORMAT_INVALID:
			std::cout << "Bad Input => " << line << std::endl;
			break;
		case INPUT_DATE_INVALID:
			std::cout << "Bad Input => " << line << std::endl;
			break;
		case INPUT_DATE_TOO_EARLY:
			std::cout << "Input date is too early." << std::endl;
			break;
		case INPUT_PRICE_INVALID:
			std::cout << "Bad Input => " << line << std::endl;
			break;
		case INPUT_PRICE_NEGATIVE:
			std::cout << "not a positive number." << std::endl;
			break;
		case INPUT_PRICE_TOO_LARGE:
			std::cout << "too large a number." << std::endl;
			break;
		default:
			break;
	}
}