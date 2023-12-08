/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:02:15 by sawang            #+#    #+#             */
/*   Updated: 2023/12/08 22:25:44 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>

//parser
//isdigit
//check overflow with atol
//turn into int array
//error when parsing


//do I parse and insert to the conterainer at the same time?
//do i need both of them?
//
std::vector<int> input;
std::list<int> input;

//after step 1, having vector of pairs
std::vector<std::pair<int, int> > vec;
std::list<std::pair<int, int> >	list;

std::pair <int,int> pair;
pair.first = input[i];
pair.second = input[i + 1];

//step 2, modify the pairs and compare the first and second and swap them when needed
std::vector<std::pair<int, int> > vec;
std::list<std::pair<int, int> >	list;

//apply merge sort on the pair.second and save the result back into the pair vector
std::vector<std::pair<int, int> > vec;
std::list<std::pair<int, int> >	list; //sorted

//copy the pair.second and insertto the result vector

//copy the pair.first of the smallest pair.second and insert to the result vector

//apply insertion sort on every pair.first and insert to the result vector, if we dont care about the efficiency


//for holding the result
std::vector<int> resultVec;
std::list<int> resultList;


namespace PMergeMe
{
	void sort(std::string input);
	void sortVec(std::string input);
	void sortList(std::string input);
	time_t timeToProces();
}