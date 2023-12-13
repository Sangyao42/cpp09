/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:36:08 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 13:36:11 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//list
double PmergeMe::sortList()
{
	clock_t start, end;
	double timeInterval;
	start = clock();
	makePairList();
	if (_pairList.empty())
		_resultList.push_back(_oddNum);
	else
		mergeInsertionSortList();
	end = clock();
	timeInterval = (double)(end - start) / CLOCKS_PER_SEC; //microseconds
	return (timeInterval);
}

void	PmergeMe::makePairList()
{
	_oddNum = 0;
	if (_numC % 2 == 1)
		_oddNum = atoi(_input[_numC - 1]);
	int num1;
	int num2;
	for (int i = 0; i < _numC / 2; i++)
	{
		std::pair<int, int> pair;
		num1 = atoi(_input[i]);
		num2 = atoi(_input[_numC / 2 + i]);
		pair.first = std::min(num1, num2);
		pair.second = std::max(num1, num2);
		_pairList.push_back(pair);
	}
}

void	PmergeMe::mergeSortList(pairlist &_pairList)
{
	if (_pairList.size() <= 1)
		return ;
	pairlist leftList;
	pairlist rightList;
	int mid = _pairList.size() / 2;
	pairlist_it it = _pairList.begin();
	for (int i = 0; i < mid; i++, it++)
		leftList.push_back(*it);
	for (; it != _pairList.end(); it++)
		rightList.push_back(*it);

	mergeSortList(leftList);
	mergeSortList(rightList);

	//clear the original list and merge the sublists left and right back into it
	_pairList.clear();
	_pairList.merge(leftList);
	_pairList.merge(rightList);
}

void	PmergeMe::insertionSortList()
{
	return ;
}

void	PmergeMe::mergeInsertionSortList()
{
	mergeSortList(_pairList);
	//test printing
	std::cout << "pairs: " << std::endl;
	pairlist_it testIt = _pairList.begin();
	for (; testIt != _pairList.end(); testIt++)
		std::cout << testIt->first << " ";
	std::cout << std::endl;
	testIt = _pairList.begin();
	for (; testIt != _pairList.end(); testIt++)
		std::cout << testIt->second << " ";
	std::cout << std::endl;
	//end test printing
	pairlist_it it = _pairList.begin();
	while (it != _pairList.end())
	{
		_resultList.push_back(it->second);
		it++;
	}
	insertionSortList();
}