/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:02:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 13:52:10 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Parser.hpp"
// #include "Jacobsthal.hpp"
#include <iostream>
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

		// namespace Parser;

		//member functions
		double	sortVec(); //deal time here, call merge-insertion sort inside
		void	makePairVec();
		void	mergeInsertionSortVec();
		void	mergeSortVec(pairvec &_pairVec, const int begin, const int end);
		void	mergeVec(pairvec &_pairVec, const int left, const int mid, const int right);
		void	insertionSortVec();

		double	sortList();
		void	makePairList();
		void	mergeInsertionSortList();
		void	mergeSortList(pairlist &_pairList);
		void	insertionSortList();

		void	printCompare();

		// jacobSequence and positions
		size_t	jacobsthal(int n);

		//jacobsthal && position vector
		void	genJacobSeqVec();
		void	genPosVec();

		//jacobsthal && position list
		void	genJacobSeqList();
		void	genPosList();

		// jacobsthal getters
		// std::vector<int>	getJacobSeqVec() const;

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
		// Jacobsthal<std::vector<int> > _jacobVec;
		std::vector<int>	_jacobSeqVec;
		std::vector<int>	_posVec;

		//list
		pairlist			_pairList;
		std::list<int>		_resultList;
		// Jacobsthal<std::list<int> > _jacobList;
		std::list<int>		_jacobSeqList;
		std::list<int>		_posList;
};

//list class

// #include "../src/Jacob.tpp"