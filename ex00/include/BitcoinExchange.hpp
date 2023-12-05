/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:12 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 22:59:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Database.hpp"
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>

// typedef struct s_date
// {
// 	int		day;
// 	int		month;
// 	int		year;
// }				t_date;
//operator overload == for struct s_date

//singleton
class BitcoinExchange
{
	public:
		// static	BitcoinExchange* getInstance();
		static eErrCode	applyBitcoinExchange(std::string infile);
		static void		printExchange(time_t date, float price);

	private:
		// static std::map<struct s_date, float> _bitcoinExchangeDatabase;
		static std::map<time_t, float> _bitcoinExchangeDatabase;

		// static std::map<std::string, std::string> _bitcoinExchangeInput;

		//orthodox canonical form
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
};