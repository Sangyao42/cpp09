/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:58:09 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 13:08:39 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <iostream>

void	Parser::trimWhitespace(std::string &input)
{
	size_t start = input.find_first_not_of(WHITE_SPACE);
	size_t end = input.find_last_not_of(WHITE_SPACE);

	if (start == std::string::npos)
	{
		input.clear();
		return ;
	}
	input = input.substr(start, end - start + 1);
}

bool	Parser::dateIsValid(struct tm *tmInfo)
{
	int year = tmInfo->tm_year + 1900;
	if (year < 0)
		return (false);
	if (tmInfo->tm_mon < 0 || tmInfo->tm_mon > 11)
		return (false);
	int dateInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		dateInMonth[1] = 29;
	if (tmInfo->tm_mday < 1 || tmInfo->tm_mday > dateInMonth[tmInfo->tm_mon])
		return (false);
	return (true);
}

bool	Parser::isInt(std::string input)
{
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i])
		return (false);
	return (true);
}

bool	Parser::isFloat(std::string input)
{
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (isdigit(input[i]))
		i++;
	if (input[i] != '.')
		return (false);
	else
		i++;
	if (!isdigit(input[i]))
		return (false);
	while (isdigit(input[i]))
		i++;
	if (input[i])
		return (false);
	return (true);
}

bool	Parser::priceIsValid(std::string inputPrice)
{
	if (inputPrice.empty())
		return (false);
	if(Parser::isInt(inputPrice) == false && Parser::isFloat(inputPrice) == false)
		return (false);
	return (true);
}