/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobTemplate.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:53:20 by sawang            #+#    #+#             */
/*   Updated: 2023/12/13 14:41:10 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

template <typename T>
class Jacobsthal
{
	public:
		size_t	jacobsthal(int n);
		void	generateJacobSequence(size_t size);
		// template <typename U>
		void	generatePositions(size_t size);

		Jacobsthal(size_t size);
		~Jacobsthal();

	//getters
		T getJacobSequence() const;
		T getPositions() const;

	private:
		const size_t _size;
		T _jacobSequence;
		T _positions;

		Jacobsthal();
		Jacobsthal(const Jacobsthal &);
		Jacobsthal &operator=(const Jacobsthal &);
};

template <typename T>
Jacobsthal<T>::Jacobsthal(size_t size) : _size(size) {};

template <typename T>
Jacobsthal<T>::~Jacobsthal() {};

template <typename T>
Jacobsthal<T>::Jacobsthal() {};

template <typename T>
Jacobsthal<T>::Jacobsthal(const Jacobsthal &) {};

template <typename T>
Jacobsthal<T> &Jacobsthal<T>::operator=(const Jacobsthal &) {
	return (*this);
};

//getters
template <typename T>
T Jacobsthal<T>::getJacobSequence() const {
	return (_jacobSequence);
};

template <typename T>
T Jacobsthal<T>::getPositions() const {
	return (_positions);
};

template <typename T>
size_t	Jacobsthal<T>::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

template <typename T>
void	Jacobsthal<T>::generateJacobSequence(size_t size)
{
	size_t jcobstalIndex;
	int index;

	index = 3;

	// _jacobSequence.push_back(1);
	while ((jcobstalIndex = jacobsthal(index)) < size - 1)
	{
		_jacobSequence.push_back(jcobstalIndex);
		index++;
	}
}

template <>
// template <>
void	Jacobsthal<std::vector<int> >::generatePositions(size_t size)
{
	size_t val;
	size_t pos;
	size_t lastPos;
	size_t i;

	if (size == 0)
		return ;
	generateJacobSequence(size);
	std::cout << "jacobSequenceVEC:  ";
	for (std::vector<int>::iterator it = _jacobSequence.begin(); it != _jacobSequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	lastPos = 1;
	val = 1;
	i = 0;
	while (i < _jacobSequence.size())
	{
		val = _jacobSequence.at(i);

		_positions.push_back(val);

		pos = val - 1;
		while (pos > lastPos)
		{
			_positions.push_back(pos);
			pos--;
		}
		lastPos = val;
		i++;
	}
	while (val++ < size)
		_positions.push_back(val);
}

template <>
// template <>
void	Jacobsthal<std::list<int> >::generatePositions(size_t size)
{
	size_t val;
	size_t pos;
	size_t lastPos;
	// size_t i;

	if (size == 0)
		return ;
	generateJacobSequence(size);
	std::cout << "jacobSequenceLIST: ";
	for (std::list<int>::iterator it = _jacobSequence.begin(); it != _jacobSequence.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	lastPos = 1;
	val = 1;
	// i = 0;
	std::list<int>::iterator it = _jacobSequence.begin();
	while (it != _jacobSequence.end())
	{
		val = *it;
		_positions.push_back(val);
		pos = val - 1;
		while (pos > lastPos)
		{
			_positions.push_back(pos);
			pos--;
		}
		lastPos = val;
		it++;
	}
	while (val++ < size)
		_positions.push_back(val);
}


int main(void)
{
	int size = 6;
	Jacobsthal<std::vector<int> > jacobVec(size);
	Jacobsthal<std::list<int> > jacobList(size);

	jacobVec.generatePositions(size);
	jacobList.generatePositions(size);

	std::cout << '\n' << "positionsVec: ";
	std::vector<int> vec = jacobVec.getPositions();
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << '\n' << "positionsList: ";
	std::list<int> list = jacobList.getPositions();
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
}