/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:28:05 by sawang            #+#    #+#             */
/*   Updated: 2023/12/11 22:11:54 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int numC, char **arg) : _numC(numC), _input(arg) {}
// {
// 	int array[numC];
// 	for (int i = 0; i < numC; i++)
// 		array[i] = atoi(arg[i]);
// 	for (int i = 0; i < numC; i++)
// 		std::cout << array[i] << std::endl;
// }

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &){}

PmergeMe &PmergeMe::operator=(const PmergeMe &){
	return (*this);
}

PmergeMe::~PmergeMe() {}


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
	timeInterval = (double)(end - start) / CLOCKS_PER_SEC; //microseconds
	return (timeInterval);
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
	// std::cout << "_oddNum: " << _oddNum << std::endl;
	// std::vector <std::pair<int, int> >::iterator it = _pairVec.begin();
	// while (it != _pairVec.end())
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// 	it++;
	// }
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

void	PmergeMe::insertionSortVec()
{
	int pos;
	// _resultVec.insert(_resultVec.begin(), _pairVec[0].first);
	for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
	{
		pos = 0;
		for (pairvec::size_type j = 0; j < (2 * i); j++)
		{
			if (_pairVec[i].first > _resultVec[j])
				pos++;
		}
		_resultVec.insert(_resultVec.begin() + pos, _pairVec[i].first);
	}

	//for odd number
	if (_oddNum != 0)
	{
		pos = 0;
		for (pairvec::size_type j = 0; j < _resultVec.size(); j++)
		{
			if (_oddNum > _resultVec[j])
				pos++;
		}
		_resultVec.insert(_resultVec.begin() + pos, _oddNum);
	}
}

void	PmergeMe::mergeInsertionSortVec()
{
	mergeSortVec(_pairVec, 0, _pairVec.size() - 1);
	std::cout << "pairs: " << std::endl;
	for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
		std::cout << _pairVec[i].first << " ";
	std::cout << std::endl;
	for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
		std::cout << _pairVec[i].second << " ";
	std::cout << std::endl;
	for (pairvec::size_type i = 0; i < _pairVec.size(); i++)
		_resultVec.push_back(_pairVec[i].second);
	//insertion sort here
	insertionSortVec();
}

// static bool isSorted(std::vector<int> &vec)
// {
// 	for (std::vector<int>::size_type i = 0; i < vec.size() - 1; i++)
// 	{
// 		if (vec[i] > vec[i + 1])
// 			return (false);
// 	}
// 	return (true);
// }

static bool isSortedList(std::list<int> &list)
{
	for (std::list<int>::iterator it = list.begin(); it != --list.end();)
	{
		int num1 = *it;
		int num2 = *(++it);
		if (num1 > num2)
			return (false);
	}
	return (true);

}

void	PmergeMe::printCompare()
{
	//vector
	std::cout << "Before: ";
	for (int i = 0; i < _numC; i++)
		std::cout << atoi(_input[i]) << " ";
	std::cout << std::endl;

	double timeVec = sortVec();
	std::cout << "After: ";
	for (std::vector<int>::size_type i = 0; i < _resultVec.size(); i++)
		std::cout << _resultVec[i] << " ";
	std::cout << std::endl;

	//list
	std::cout << "Before: ";
	for (int i = 0; i < _numC; i++)
		std::cout << atoi(_input[i]) << " ";
	std::cout << std::endl;
	double timeList = sortList();
	std::cout << "After: ";
	for (std::list<int>::iterator it = _resultList.begin(); it != _resultList.end(); it++)
		std::cout << *it << " ";
	if (isSortedList(_resultList) == false)
		std::cout << "NOT SORTED" << std::endl;
	std::cout << "Time for vector: " << timeVec << std::endl;
	std::cout << "Time for list: " << timeList << std::endl;
}