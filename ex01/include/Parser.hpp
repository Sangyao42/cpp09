/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:08:06 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 16:35:14 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace Parser
{
	bool	isOperator(char c);
	class ParserException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
