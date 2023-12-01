/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:41:30 by sawang            #+#    #+#             */
/*   Updated: 2023/12/01 19:43:46 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>

void	Database::trimWhitespace(std::string &input)
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

std::pair<bool, std::pair<struct s_date, float>>	Database::parseDataOneLine(std::string line)
{
	std::pair <struct s_date, float> data;
	std::string date;
	std::string price;

	size_t pos = line.find(",");
	date = line.substr(0, pos);
	price = line.substr(pos + 1);
	Database::trimWhitespace(date);
	Database::trimWhitespace(price);

	date = Database::parseDate(date);
	if

}
std::map<struct s_date, float> Database::initDatabase(const std::string databaseFile)
{
	std::string line;
	std::map<struct s_date, float> database;
	std::ifstream ifs(databaseFile);

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
				trimWhitespace(line);
				if (line.empty())
					continue ;
				else  //error
				{
					database.clear();
					// ifs.close();
					// return (database);
					break ;
				}
			}
			else
			{
				std::pair<bool, std::pair<struct s_date, float>> DataLine = Database::parseDataOneLine(line);
				if (DataLine.first == false) //error
				{
					database.clear();
					// ifs.close();
					// return (database);
					break ;
				}
				else
					database.insert(std::pair<struct s_date, float>(DataLine.second.first, DataLine.second.second));
			}
		}
	}
	if (ifs.bad())
		return ;
	ifs.close();
	return (database);
}

std::map<std::string, std::string> Database::initInput(std::ifstream ifs)
{
	std::string line;
	std::map<std::string, std::string> input;
	// std::ifstream ifs(infile, std::ifstream::in);

	while (std::getline(ifs, line))
	{
		size_t pos = 0;
		std::string s1;
		std::string s2;
		if (line.empty())
			input.insert(std::pair<std::string, std::string>("", ""));
		else
		{
			pos = line.find("|");
			if (pos == std::string::npos)
			{
				Database::trimWhitespace(line);
				input.insert(std::pair<std::string, std::string>(line, ""));
			}
			else
			{
				s1 = line.substr(0, pos);
				s2 = line.substr(pos + 1);
				Database::trimWhitespace(s1);
				Database::trimWhitespace(s2);
				input.insert(std::pair<std::string, std::string>(s1, s2));
			}
		}
	}
	if (ifs.bad())
		return (input);
	ifs.close();

}
