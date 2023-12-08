/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:03:27 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 16:05:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

bool	Parser::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

const char* Parser::ParserException::what() const throw()
{
	return ("Error: Parser failed");
}