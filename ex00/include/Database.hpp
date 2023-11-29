/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:14:27 by sawang            #+#    #+#             */
/*   Updated: 2023/11/29 16:18:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>

namespace Database
{
	std::map<struct s_data, float>	initDatabase(const std::string input);
	std::map<struct s_data, float>	parseDatabase(std::string input);
}