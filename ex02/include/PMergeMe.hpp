/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:02:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/11 21:09:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <list>

// #define PairVec std::vector<std::pair<int, int> >
// namespace PMergeMe
// {

// 	void sort(std::string input);
// 	void sortVec(std::string input);
// 	void sortList(std::string input);
// 	time_t timeToProces();
// }

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

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		PmergeMe &operator=(const PmergeMe &);


		int					_numC;
		char 				**_input;
		int 				_oddNum;
		// //vector
		pairvec				_pairVec;
		std::vector<int>	_resultVec;
		// //list
		pairlist			_pairList;
		std::list<int>		_resultList;
};

//list class