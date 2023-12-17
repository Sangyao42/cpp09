/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:12 by sawang            #+#    #+#             */
/*   Updated: 2023/12/17 17:56:19 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Database.hpp"
#include "Input.hpp"
#include <map>
#include <iostream>
#include <ctime>
#include <time.h>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

//singleton
class BitcoinExchange
{
	public:
		// static	BitcoinExchange* getInstance();
		static eErrCode		applyBitcoinExchange(std::string infile);
		static eInputErr	calculateExchange(std::pair<std::string, std::string> inputPair);
		static void			printExchange(std::pair<std::string, std::string> inputPair, float priceAfterExchange);

	private:
		static std::map<time_t, float> _bitcoinExchangeDatabase;

		//orthodox canonical form
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
};