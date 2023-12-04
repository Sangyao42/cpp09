/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:27 by sawang            #+#    #+#             */
/*   Updated: 2023/12/04 17:19:52 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>

#define WHITE_SPACE " \t\n\v\f\r"

// namespace Database
// {
// 	std::map<struct s_date, float>	initDatabase(const std::string infile);
// 	bool	parseDataOneLine(std::string input, std::map<struct s_data, float> &database);
// 	void	trimWhitespace(std::string &input);
// 	bool 	parseDate(std::string input, struct s_data &date);

// 	bool 	parsePrice(std::string input, float &price);
// }


namespace Database
{
	enum eErrCode
	{
		DATABASE_OK,
		DATABASE_FILE_FAIL,
		// DATABASE_FILE_EMPTY,
		DATABASE_INVALID,
		INPUT_FILE_FAIL,
		// INPUT_FILE_EMPTY,
	};
	std::map<struct s_date, float>	initDatabase(const std::string databaseFile);
	std::map<std::string, std::string> initInput(std::ifstream ifs);
	std::pair<bool, std::pair<struct s_date, float>>	parseDataOneLine(std::string line);
	void	trimWhitespace(std::string &input);
	std::pair<bool, struct s_date>	parseDate(std::string input);
	std::pair<bool, float> 	parsePrice(std::string input);
}


// std::pair<bool, std::pair<struct s_date, float>> f();

// std::pair<bool, float> f();

// std::pair<bool, float> a = f();
// a.first
// a.second

// class pair
// {
// 	public:
// 		pair(T first, U second) : first_(first), second_(second) {}
// 		~pair() {}
// 		T first() const { return first_; }
// 		U second() const { return second_; }
// 	private:
// 		T first_;
// 		U second_;
// }

// make_pair


0 5 9 3
1 4 6 10

    4 6 3
0 1 5 9 10

    4 6 3
0 1 5 9 10


15 5 9
4  1 8


1 8 4
5 9 15