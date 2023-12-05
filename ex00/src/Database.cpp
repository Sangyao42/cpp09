/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:41:30 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 22:09:34 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include "Parser.hpp"
#include "Input.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

std::pair<bool, std::pair<time_t, float> >	Database::parseDataOneLine(std::string line)
{
	std::pair <time_t, float> data;
	std::string inputDate;
	std::string inputPrice;

	size_t pos = line.find(",");
	inputDate = line.substr(0, pos);
	inputPrice = line.substr(pos + 1);
	Parser::trimWhitespace(inputDate);
	Parser::trimWhitespace(inputPrice);

	std::pair<bool, time_t> date = Database::parseDate(inputDate);
	if (date.first == false)
	{
		data = std::make_pair(0, 0);
		// return (std::pair<bool, std::pair<time_t, float>>(false, std::pair<time_t, float>(0, 0)));
		return (std::make_pair(false, data));
	}
	std::pair<bool, float> price = Database::parsePrice(inputPrice);
	if (price.first == false)
	{
		data = std::make_pair(0, 0);
		// return (std::pair<bool, std::pair<time_t, float>>(false, std::pair<time_t, float>(0, 0)));
		return (std::make_pair(false, data));
	}
	data.first = date.second;
	data.second = price.second;
	return (std::make_pair(true, data));
}

std::pair<bool, time_t>	Database::parseDate(std::string inputDate)
{
	struct tm tmInfo;
	char *valid;

	if (inputDate.empty())
		return (std::make_pair(false, 0));
	valid = strptime(inputDate.c_str(), DATE_FORMAT, &tmInfo);
	if (valid == NULL)
		return (std::make_pair(false, 0));
	else if (*valid != '\0')
		return (std::make_pair(false, 0));
	else
	{
		if(Parser::dateIsValid(&tmInfo))
			return (std::make_pair(true, mktime(&tmInfo)));
		else
			return (std::make_pair(false, 0));
	}
}

std::pair<bool, float> 	Database::parsePrice(std::string inputPrice)
{
	double price;

	if (Parser::priceIsValid(inputPrice) == false)
		return (std::make_pair(false, 0));
	price = strtod(inputPrice.c_str(), NULL);
	if (price < 0 || price > std::numeric_limits<float>::max())
		return (std::make_pair(false, 0));
	return (std::make_pair(true, static_cast<float>(price)));
}

//in Data.csv
//skip empty lines
//skip lines with only whitespace
//if the line has only commam or comma with whitespaces, error
std::map<time_t, float> Database::initDatabase(std::string databaseFile)
{
	std::string line;
	std::map<time_t, float> database;
	std::ifstream ifs(databaseFile.c_str(), std::ifstream::in);

	//need to check ifs here?
	std::getline(ifs, line); //skip the first line
	if (ifs.bad())
	{
		database.clear();
		ifs.close();
		return (database);
	}
	while (std::getline(ifs, line))
	{
		size_t pos = 0;
		if (line.empty())
			continue ;
		else
		{
			pos = line.find(",");
			if (pos == std::string::npos)
			{
				Parser::trimWhitespace(line);
				if (line.empty())
					continue ;
				else	//error
				{
					database.clear();
					break ;
				}
			}
			else
			{
				std::pair<bool, std::pair<time_t, float> > DataLine = Database::parseDataOneLine(line);
				if (DataLine.first == false) //error
				{
					database.clear();
					break ;
				}
				else
					database.insert(std::pair<time_t, float>(DataLine.second.first, DataLine.second.second));
			}
		}
	}
	if (ifs.bad())
		database.clear();
	ifs.close();
	return (database);
}

// std::map<std::string, std::string> Database::initInput(std::ifstream ifs)
// {
// 	std::string line;
// 	std::map<std::string, std::string> input;
// 	// std::ifstream ifs(infile, std::ifstream::in);

// 	while (std::getline(ifs, line))
// 	{
// 		size_t pos = 0;
// 		std::string s1;
// 		std::string s2;
// 		if (line.empty())
// 			input.insert(std::pair<std::string, std::string>("", ""));
// 		else
// 		{
// 			pos = line.find("|");
// 			if (pos == std::string::npos)
// 			{
// 				Parser::trimWhitespace(line);
// 				input.insert(std::pair<std::string, std::string>(line, ""));
// 			}
// 			else
// 			{
// 				s1 = line.substr(0, pos);
// 				s2 = line.substr(pos + 1);
// 				Parser::trimWhitespace(s1);
// 				Parser::trimWhitespace(s2);
// 				input.insert(std::pair<std::string, std::string>(s1, s2));
// 			}
// 		}
// 	}
// 	if (ifs.bad())
// 		return (input);
// 	ifs.close();

// }

void	Database::errPrint(eErrCode err)
{
	std::cout << "Error: ";
	if (err == DATABASE_FILE_FAIL)
		std::cout << "Database file failed to open" << std::endl;
	else if (err == DATABASE_INVALID)
		std::cout << "Database file is invalid" << std::endl;
	else if (err == INPUT_FILE_FAIL)
		std::cout << "Input file failed to open" << std::endl;
	else
		std::cout << "Unknown error" << std::endl;
}

