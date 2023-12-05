/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:55:50 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 18:41:39 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <time.h>

#define WHITE_SPACE " \t\n\v\f\r"

namespace Parser
{
	void	trimWhitespace(std::string &input);
	bool	dateIsValid(struct tm *tmInfo);
	bool 	isInt(std::string input);
	bool	isFloat(std::string input);
	bool	priceIsValid(std::string inputPrice);
}
