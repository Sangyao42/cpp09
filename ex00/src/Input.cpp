/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:09:36 by sawang            #+#    #+#             */
/*   Updated: 2023/12/06 16:24:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"
#include "Parser.hpp"
#include "Database.hpp"
#include "BitcoinExchange.hpp"

std::pair<eInputErr, std::pair<std::string, float> >	Input::parseInputOneLine(std::string &inputLine)
{
	size_t pos = 0;
	std::pair<eInputErr, std::string> date;
	std::pair<eInputErr, float> price;

	if (inputLine.empty())
		return (std::make_pair(INPUT_LINE_EMPTY, std::make_pair("", 0)));
	pos = inputLine.find("|");
	if (pos == std::string::npos)
	{
		Parser::trimWhitespace(inputLine);
		if (inputLine.empty())
			return (std::make_pair(INPUT_LINE_EMPTY, std::make_pair("", 0)));
		else
			return (std::make_pair(INPUT_FORMAT_INVALID, std::make_pair("", 0)));
	}
	else
	{
		std::string s1 = inputLine.substr(0, pos);
		std::string s2 = inputLine.substr(pos + 1);
		Parser::trimWhitespace(s1);
		Parser::trimWhitespace(s2);
		date = Input::parseDate(s1);
		if (date.first != INPUT_DATE_OK)
			return (std::make_pair(date.first, std::make_pair("", 0)));
		price = Input::parsePrice(s2);
		if (price.first != INPUT_PRICE_OK)
			return (std::make_pair(price.first, std::make_pair("", 0)));
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

std::pair<eInputErr, float>	Input::parsePrice(std::string inputPrice)
{
	double price;

	// if (inputPrice.empty())
	// 	return (std::make_pair(INPUT_PRICE_INVALID, 0));
	if (Parser::priceIsValid(inputPrice) == false)
		return (std::make_pair(INPUT_PRICE_INVALID, 0));
	price = strtod(inputPrice.c_str(), NULL);
	if (price < 0)
		return (std::make_pair(INPUT_PRICE_NEGATIVE, 0));
	if (price > 1000)
		return (std::make_pair(INPUT_PRICE_TOO_LARGE, 0));
	return (std::make_pair(INPUT_PRICE_OK, static_cast<float>(price)));
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
			std::cout << "Input date is invalid" << std::endl;
			break;
		case INPUT_DATE_TOO_EARLY:
			std::cout << "Input date is too early." << std::endl;
			break;
		case INPUT_PRICE_INVALID:
			std::cout << "Input price is invalid." << std::endl;
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