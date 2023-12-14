/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:06:53 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 14:38:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Parser.hpp"
#include <stack>
#include <ctype.h>
#include <limits>

bool	RPN::resultIsValid(float result)
{
	if (result > std::numeric_limits<int>::max() || \
		result < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

float	RPN::calcOperation(int lhs, int rhs, char op)
{
	std::string opArray= "+-*/";
	float result;

	int i = opArray.find(op);
	switch (i)
	{
		case 0:
			result = lhs + rhs;
			break;
		case 1:
			result = lhs - rhs;
			break;
		case 2:
			result = lhs * rhs;
			break;
		case 3:
			if (rhs == 0)
				throw RPN::CalculationUndefinedException();
			result = lhs / rhs;
			break;
		default:
			throw RPN::CalculationUndefinedException();
	}
	if (resultIsValid(result))
		return (result);
	else
		throw RPN::ResultOutOfRangeException();
}

void	RPN::calcRPN(std::string input)
{
	std::stack<int>	stack;
	long			result;

	std::string::iterator it = input.begin();
	while (it != input.end())
	{
		while (isspace(*it))
			it++;
		if (*it == '\0')
			break;
		if (isdigit(*it))
			stack.push(*it - '0');
		else if (Parser::isOperator(*it))
		{
			if (stack.size() < 2)
				throw Parser::ParserException();
			int rhs = stack.top();
			stack.pop();
			int lhs = stack.top();
			stack.pop();
			result = calcOperation(lhs, rhs, *it); //inside check if 0 and if valid
			stack.push(static_cast<int>(result));
		}
		else
			throw Parser::ParserException();
		if(isspace(*(++it)) || *it == '\0')
			continue;
		else
			throw Parser::ParserException();
	}
	if (stack.size() == 0)
		return ;
	if (stack.size() != 1)
		throw Parser::ParserException();
	std::cout << stack.top() << std::endl;
}

const char* RPN::ResultOutOfRangeException::what() const throw()
{
	return ("Error: Result is out of range");
}

const char* RPN::CalculationUndefinedException::what() const throw()
{
	return ("Error: Calculation is undefined");
}
