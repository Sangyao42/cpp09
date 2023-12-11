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
// void	PmergeMe::mergeList(pairlist &_pairList, const pairlist_it left, const pairlist_it mid, const pairlist_it end)
// {
// 	pairlist_it leftEnd = mid;
// 	++leftEnd;
// 	pairlist_it rightEnd = end;
// 	++rightEnd;
// 	pairlist leftList(left, leftEnd);
// 	pairlist rightList(leftEnd, rightEnd);

// 	pairlist_it leftIt = leftList.begin();
// 	pairlist_it rightIt = rightList.begin();
// 	// pairlist_it resultIt = left;
// 	pairlist_it resultIt = leftList.begin();
// 	while (leftIt != leftList.end() && rightIt != rightList.end())
// 	{
// 		if (leftIt->second <= rightIt->second)
// 		{
// 			*resultIt = *leftIt;
// 			leftIt++;
// 		}
// 		else
// 		{
// 			*resultIt = *rightIt;
// 			rightIt++;
// 		}
// 		resultIt++;
// 	}
// 	while (leftIt != leftList.end())
// 	{
// 		*resultIt = *leftIt;
// 		leftIt++;
// 		resultIt++;
// 	}
// 	while (leftIt != leftList.end())
// 	{
// 		*resultIt = *rightIt;
// 		rightIt++;
// 		resultIt++;
// 	}
// }

// void	PmergeMe::mergeSortList(pairlist &_pairList, const pairlist_it begin, const pairlist_it end)
// {
// 	if (begin == end)
// 		return ;
// 	pairlist_it mid = begin;
// 	std::advance(mid, std::distance(begin, end) / 2); //calculate mid
// 	mergeSortList(_pairList, begin, mid);
// 	pairlist_it mid2 = mid;
// 	std::advance(mid2, 1); //get next element after mid
// 	mergeSortList(_pairList, mid2, end);
// 	mergeList(_pairList, begin, mid, end);
// }

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