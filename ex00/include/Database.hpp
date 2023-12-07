/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:27 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 13:47:25 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <time.h>
#include <ctime>

#define DATE_FORMAT "%Y-%m-%d"

enum eErrCode
{
	SUCCESS,
	DATABASE_FILE_FAIL,
	DATABASE_FILE_EMPTY,
	DATABASE_INVALID,
	INPUT_FILE_FAIL,
	INPUT_FILE_EMPTY,
	INPUT_INVALID,
};

namespace Database
{
	//with time_t
	std::map<time_t, float>	initDatabase(const std::string databaseFile);
	std::pair<bool, std::pair<time_t, float> >	parseDataOneLine(std::string line);
	std::pair<bool, time_t>	parseDate(std::string inputDate);
	std::pair<bool, float> 	parsePrice(std::string inputPrice);
	void	errPrint(eErrCode err);
}
