/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:12 by sawang            #+#    #+#             */
/*   Updated: 2023/11/25 21:58:38 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>

typedef struct s_date
{
	int		day;
	int		month;
	int		year;
}				t_date;

//singleton
class BitcoinExchange
{
	public:
		static	BitcoinExchange* getInstance();
		void	applyBitcoinExchange(std::string input);

	private:
		std::map<struct s_date, float> _bitcoinExchangeDatabase;

		//orthodox canonical form
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();
};