/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:34:15 by sawang            #+#    #+#             */
/*   Updated: 2023/11/29 21:45:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Database.hpp"

std::map<struct s_date, float> BitcoinExchange::_bitcoinExchangeDatabase = \
	Database::initDatabase("./database.csv");