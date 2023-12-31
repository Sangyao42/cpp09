/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortVec.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:41:39 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 13:59:16 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//vector
double	PmergeMe::sortVec()
{
	clock_t start, end;
	double timeInterval;
	start = clock();
	makePairVec();
	if (_pairVec.empty())
		_resultVec.push_back(_oddNum);
	else
		mergeInsertionSortVec();
	end = clock();
	timeInterval = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000; //milliseconds
	return (timeInterval);
}

void	PmergeMe::mergeInsertionSortVec()
{
	mergeSortVec(_pairVec, 0, _pairVec.size() - 1);
	// std::cout << "pairs: " << std::endl;
	// for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
	// 	std::cout << _pairVec[i].first << " ";
	// std::cout << std::endl;
	// for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
	// 	std::cout << _pairVec[i].second << " ";
	// std::cout << std::endl;
	for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
		_resultVec.push_back(_pairVec[i].second);
	insertionSortVec();
}

void	PmergeMe::makePairVec()
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
		_pairVec.push_back(pair);
	}
}

static void	pairVecEqual(std::pair<int, int> &pair1, std::pair<int, int> &pair2)
{
	pair1.first = pair2.first;
	pair1.second = pair2.second;
}

void	PmergeMe::mergeVec(pairvec &_pairVec, const int left, const int mid, const int right)
{
	const int leftSize = mid - left + 1;
	const int rightSize = right - mid;

	pairvec leftVec;
	pairvec rightVec;
	for (int i = 0; i < leftSize; i++)
		leftVec.push_back(_pairVec[left + i]);
	for (int j = 0; j < rightSize; j++)
		rightVec.push_back(_pairVec[mid + 1 + j]);
	int indexLeft = 0;
	int indexRight = 0;
	int indexMerged = left;
	while (indexLeft < leftSize && indexRight < rightSize)
	{
		if (leftVec[indexLeft].second <= rightVec[indexRight].second)
		{
			pairVecEqual(_pairVec[indexMerged], leftVec[indexLeft]);
			indexLeft++;
		}
		else
		{
			pairVecEqual(_pairVec[indexMerged], rightVec[indexRight]);
			indexRight++;
		}
		indexMerged++;
	}
	while (indexLeft < leftSize)
	{
		pairVecEqual(_pairVec[indexMerged], leftVec[indexLeft]);
		indexLeft++;
		indexMerged++;
	}
	while (indexRight < rightSize)
	{
		pairVecEqual(_pairVec[indexMerged], rightVec[indexRight]);
		indexRight++;
		indexMerged++;
	}
}

void	PmergeMe::mergeSortVec(pairvec &_pairVec, const int begin, const int end)
{
	if (begin >= end)
		return ;
	int mid = begin + (end - begin) / 2;
	mergeSortVec(_pairVec, begin, mid);
	mergeSortVec(_pairVec, mid + 1, end);
	mergeVec(_pairVec, begin, mid, end);
}

int	PmergeMe::binarySearchVec(int value, size_t endPos)
{
	int start = 0;
	int end = endPos;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (value > _resultVec[mid])
			start = mid + 1;
		else if (value < _resultVec[mid])
			end = mid - 1;
		else
			return mid;
	}
	if (value > _resultVec[mid])
		return (mid + 1);
	else
		return (mid);
	return (-1);
}

void	PmergeMe::insertionSortVec()
{
	int pos;

	genPosVec();
	_resultVec.insert(_resultVec.begin(), _pairVec[0].first);
	int addedCount = 0;
	int value;
	size_t	endIdx;
	for (std::vector<int>::iterator it = _posVec.begin(); it != _posVec.end(); it++)
	{
		value = _pairVec[*it - 1].first;
		endIdx = *it + addedCount;
		pos = binarySearchVec(value, endIdx);
		_resultVec.insert(_resultVec.begin() + pos, value);
		addedCount++;
	}
	//for odd number
	if (_oddNum != 0)
	{
		pos = binarySearchVec(_oddNum, _resultVec.size() - 1);
		_resultVec.insert(_resultVec.begin() + pos, _oddNum);
	}
}
