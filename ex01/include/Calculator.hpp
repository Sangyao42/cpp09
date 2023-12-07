/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:07:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 17:14:35 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Parser.hpp"
#include <iostream>

namespace Calculator
{
	void	calcRPN(std::string input);
	int		calculate(int a, int b, char op);

	class ResultOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: Calculator failed");
			}
	};
	class ResultIsNotValidException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: Result is not valid");
			}
	};
};