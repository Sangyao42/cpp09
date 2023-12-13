/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:36:08 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 22:59:35 by sawang           ###   ########.fr       */
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
		pair.first = std::max(num1, num2);
		pair.second = std::min(num1, num2);
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

int	PmergeMe::binarySearchList(int value, size_t endPos)
{
	int start = 0;
	int end = endPos;
	int mid;
	int numToCompare;
	std::list<int>::iterator it;
	while (start <= end)
	{
		mid = (start + end) / 2;
		it = _resultList.begin();
		std::advance(it, mid);
		numToCompare = *it;
		if (value > numToCompare)
			start = mid + 1;
		else if (value < numToCompare)
			end = mid - 1;
		else
			return mid;
	}
	it = _resultList.begin();
	std::advance(it, mid);
	numToCompare = *it;
	if (value > numToCompare)
		return (mid + 1);
	else
		return (mid);
	return (-1);
}
void	PmergeMe::insertionSortList()
{
	int pos;

	genPosList();
	_resultList.insert(_resultList.begin(), _pairList.front().second);
	int value;
	int addedCount = 0;
	size_t endIdx;
	for (std::list<int>::iterator it = _posList.begin(); it != _posList.end(); it++)
	{
		pairlist_it pairIt = _pairList.begin();
		std::advance(pairIt, *it - 1);
		value = pairIt->second;
		endIdx = *it + addedCount;
		pos = binarySearchList(value, endIdx);
		std::list<int>::iterator resultIt = _resultList.begin();
		std::advance(resultIt, pos);
		_resultList.insert(resultIt, value);
		addedCount++;
	}
	if (_oddNum != 0)
	{
		pos = binarySearchList(_oddNum, _resultList.size() - 1);
		std::list<int>::iterator resultIt = _resultList.begin();
		std::advance(resultIt, pos);
		_resultList.insert(resultIt, _oddNum);
	}
}

void	PmergeMe::mergeInsertionSortList()
{
	mergeSortList(_pairList);
	//test printing
	// std::cout << "pairs: " << std::endl;
	// for (pairlist_it testIt = _pairList.begin() ; testIt != _pairList.end(); testIt++)
	// 	std::cout << testIt->second << " ";
	// std::cout << std::endl;
	// for (pairlist_it testIt = _pairList.begin(); testIt != _pairList.end(); testIt++)
	// 	std::cout << testIt->first << " ";
	// std::cout << std::endl;
	//end test printing
	pairlist_it it = _pairList.begin();
	while (it != _pairList.end())
	{
		_resultList.push_back(it->first);
		it++;
	}
	insertionSortList();
}
