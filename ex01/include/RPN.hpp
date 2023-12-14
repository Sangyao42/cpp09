/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:07:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 14:38:27 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Parser.hpp"
#include <iostream>

namespace RPN
{
	void	calcRPN(std::string input);
	float	calcOperation(int a, int b, char op);
	bool	resultIsValid(float result);

	class ResultOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class CalculationUndefinedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};