/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:27 by sawang            #+#    #+#             */
/*   Updated: 2023/11/29 21:38:28 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>

#define WHITE_SPACE " \t\n\v\f\r"

namespace Database
{
	std::map<struct s_date, float>	initDatabase(const std::string infile);
	bool	parseDataOneLine(std::string input, std::map<struct s_data, float> &database);
	void	trimWhitespace(std::string &input);
	bool 	parseDate(std::string input, struct s_data &date);

	bool 	parsePrice(std::string input, float &price);
}


std::pair<bool, std::pair<struct s_data, float>> f();

std::pair<bool, float> f();

std::pair<bool, float> a = f();
a.first
a.second

class pair
{
	public:
		pair(T first, U second) : first_(first), second_(second) {}
		~pair() {}
		T first() const { return first_; }
		U second() const { return second_; }
	private:
		T first_;
		U second_;
}

make_pair