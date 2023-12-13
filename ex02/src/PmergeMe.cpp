/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:28:05 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 23:00:25 by sawang           ###   ########.fr       */
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

static bool isSorted(std::vector<int> &vec)
{
	for (std::vector<int>::size_type i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] > vec[i + 1])
			return (false);
	}
	return (true);
}

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
	if (isSorted(_resultVec) == false)
		std::cout << "Vec NOT SORTED" << std::endl;
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
		std::cout << "List NOT SORTED" << std::endl;
	std::cout << "Time for vector: " << timeVec << std::endl;
	std::cout << "Time for list: " << timeList << std::endl;
}
