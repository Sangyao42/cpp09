/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalSeq.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:39:21 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 16:03:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t	PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void	PmergeMe::genJacobSeqVec()
{
	int jacobsIdx = 3;
	int size = _pairVec.size();
	int indexToStart;

	while ((indexToStart = jacobsthal(jacobsIdx)) <= size)
	{
		_jacobSeqVec.push_back(indexToStart);
		jacobsIdx++;
	}
}

void	PmergeMe::genPosVec()
{
	size_t i = 0;
	size_t indexToStart;
	size_t lastIndexToStart = 1;

	genJacobSeqVec();
	while (i < _jacobSeqVec.size())
	{
		indexToStart = _jacobSeqVec[i];
		// _posVec.push_back(indexToStart);
		// --indexToStart;
		while (indexToStart > lastIndexToStart)
		{
			_posVec.push_back(indexToStart);
			--indexToStart;
		}
		lastIndexToStart = _jacobSeqVec[i];
		i++;
	}
	while (lastIndexToStart < _pairVec.size())
	{
		_posVec.push_back(++lastIndexToStart);
		// lastIndexToStart++;
	}
	std::cout << "posVec inside: ";
	for (size_t i = 0; i < _posVec.size(); i++)
		std::cout << _posVec[i] << " ";
}