/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:02:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/14 13:58:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Parser.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>

class PmergeMe
{


	public:
		typedef std::vector<std::pair<int, int> > pairvec;
		typedef std::list<std::pair<int, int> > pairlist;
		typedef std::list<std::pair<int, int> >::iterator pairlist_it;

		//orthodox canonial form
		PmergeMe(int numC, char **arg);
		~PmergeMe();

		//member functions
		double	sortVec(); //deal time here, call merge-insertion sort inside
		void	makePairVec();
		void	mergeInsertionSortVec();
		void	mergeSortVec(pairvec &_pairVec, const int begin, const int end);
		void	mergeVec(pairvec &_pairVec, const int left, const int mid, const int right);
		int		binarySearchVec(int value, size_t endPos);
		void	insertionSortVec();

		double	sortList();
		void	makePairList();
		void	mergeInsertionSortList();
		void	mergeSortList(pairlist &_pairList);
		int		binarySearchList(int value, size_t endPos);
		void	insertionSortList();

		void	printCompare();

		// jacobsthal numbers
		size_t	jacobsthal(int n);

		//jacobsthal && position vector
		void	genJacobSeqVec();
		void	genPosVec();

		//jacobsthal && position list
		void	genJacobSeqList();
		void	genPosList();

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);


		int					_numC;
		char 				**_input;
		int 				_oddNum;
		//vector
		pairvec				_pairVec;
		std::vector<int>	_resultVec;
		std::vector<int>	_jacobSeqVec;
		std::vector<int>	_posVec;

		//list
		pairlist			_pairList;
		std::list<int>		_resultList;
		std::list<int>		_jacobSeqList;
		std::list<int>		_posList;
};