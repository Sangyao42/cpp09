/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:07:58 by sawang            #+#    #+#             */
/*   Updated: 2023/12/05 22:22:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

enum eInputErr
{
	INPUT_OK,
	INPUT_LINE_EMPTY,
	INPUT_FORMAT_INVALID,
	INPUT_DATE_OK,
	INPUT_DATE_INVALID,
	INPUT_DATE_TOO_EARLY,
	INPUT_PRICE_OK,
	INPUT_PRICE_INVALID,
	INPUT_PRICE_NEGATIVE,
	INPUT_PRICE_TOO_LARGE,
};

namespace Input
{
	std::pair<eInputErr, std::pair<std::string, float> >	parseInputOneLine(std::string &inputLine);
	std::pair<eInputErr, std::string>	parseDate(std::string inputDate);
	std::pair<eInputErr, float>			parsePrice(std::string inputPrice);
	void	errPrint(eInputErr err);
}