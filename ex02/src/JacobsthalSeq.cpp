/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalSeq.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:39:21 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 23:00:09 by sawang           ###   ########.fr       */
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

//vector
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
		while (indexToStart > lastIndexToStart)
		{
			_posVec.push_back(indexToStart);
			--indexToStart;
		}
		lastIndexToStart = _jacobSeqVec[i];
		i++;
	}
	while (lastIndexToStart < _pairVec.size())
		_posVec.push_back(++lastIndexToStart);
}

//list
void	PmergeMe::genJacobSeqList()
{
	int jacobsIdx = 3;
	int size = _pairList.size();
	int indexToStart;

	while ((indexToStart = jacobsthal(jacobsIdx)) <= size)
	{
		_jacobSeqList.push_back(indexToStart);
		jacobsIdx++;
	}
}

void	PmergeMe::genPosList()
{
	size_t indexToStart;
	size_t lastIndexToStart = 1;

	genJacobSeqList();
	for (std::list<int>::iterator it = _jacobSeqList.begin(); it != _jacobSeqList.end(); it++)
	{
		indexToStart = *it;
		while (indexToStart > lastIndexToStart)
		{
			_posList.push_back(indexToStart);
			--indexToStart;
		}
		lastIndexToStart = *it;
	}
	while (lastIndexToStart < _pairList.size())
		_posList.push_back(++lastIndexToStart);
}



