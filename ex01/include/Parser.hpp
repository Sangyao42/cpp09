/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:08:06 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 16:34:09 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define WHITE_SPACE " \t\n\v\f\r"

namespace Parser
{
	bool	isNumber(char c);
	bool	isOperator(char c);
	bool	parseRPN(std::string input);
};
