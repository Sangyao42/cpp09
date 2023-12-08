/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:06:53 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 16:54:11 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Calculator.hpp"
#include "Parser.hpp"
#include <stack>
#include <ctype.h>
#include <limits>

bool	Calculator::resultIsValid(float result)
{
	if (result > std::numeric_limits<int>::max() || \
		result < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

float	Calculator::calcOperation(int lhs, int rhs, char op)
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
				throw Calculator::CalculationUndefinedException();
			result = lhs / rhs;
			break;
		default:
			throw Calculator::CalculationUndefinedException();
	}
	if (resultIsValid(result))
		return (result);
	else
		throw Calculator::ResultOutOfRangeException();
}

void	Calculator::calcRPN(std::string input)
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

const char* Calculator::ResultOutOfRangeException::what() const throw()
{
	return ("Error: Result is out of range");
}

const char* Calculator::CalculationUndefinedException::what() const throw()
{
	return ("Error: Calculation is undefined");
}

const char* Calculator::ResultIsNotValidException::what() const throw()
{
	return ("Error: Result is not valid");
}