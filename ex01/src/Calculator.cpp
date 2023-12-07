/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:06:53 by sawang            #+#    #+#             */
/*   Updated: 2023/12/07 17:14:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Calculator.hpp"
#include "Parser.hpp"
#include <stack>


// peek
// char peek(std::string::iterator it)
// {
// 	return (*it);
// }

// advance

void	Calculator::calcRPN(std::string input)
{
	std::stack<int>	stack;

	std::string::iterator it = input.begin();
	while (it != input.end())
	{
		while (Parser::isWhiteSpace(*it))
			it++;
		if (Parser::isDigit(*it))
		{
			stack.push(*it);
		}
		else if (Parser::isOperator(*it))
		{
			if (stack.size() < 2)
				throw Parser::ParserException();
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			int result = calculate(a, b, *it); //inside check if 0 /
			if (resultIsValid(result))
				stack.push(result);
			else
				throw Calculator::ResultOutOfRangeException();
		}
		else
			throw Parser::ParserException();

		it++;
	}



}