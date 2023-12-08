/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergMe.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:28:05 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 22:30:11 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

void	PMergeMe::sort(std::string input)
{
	time_t start, end;
	time(&start);
	sortVec(input);
	time(&end);
	time_t timeDiffVec = difftime(end, start);

	time(&start);
	sortList(input);
	time(&end);
	time_t timeDiffList = difftime(end, start);


	// printResult();
}