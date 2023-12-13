#include <iostream>
#include <vector>
#include <exception>

size_t jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<int> generateJacobInsertionSequence(size_t size)
{
	// size_t size;
	size_t jcobstalIndex;
	std::vector<int> jacobSequence;
	int index;

	// size = this->pend.size();
	index = 3;

	// jacobSequence.push_back(1);
	// while ((jcobstalIndex = jacobsthal(index)) < size - 1)
	while ((jcobstalIndex = jacobsthal(index)) <= size)
	{
		jacobSequence.push_back(jcobstalIndex);
		index++;
	}
	return (jacobSequence);
}

std::vector<int> generatPositions(size_t size)
{
	// size_t val;
	// size_t pos;
	// size_t lastPos;
	// size_t i;
	std::vector<int> jacobSequence;
	std::vector<int> positions;

	if (size == 0)
		return (positions);
	jacobSequence = generateJacobInsertionSequence(size);
	std::cout << "jacobSequence: ";
	for (std::vector<int>::iterator it = jacobSequence.begin(); it != jacobSequence.end(); it++)
		std::cout << *it << " ";
	// lastPos = 1;
	// val = 1;
	// i = 0;
	// while (i < jacobSequence.size())
	// {
	// 	val = jacobSequence.at(i);

	// 	positions.push_back(val);

	// 	pos = val - 1;
	// 	while (pos > lastPos)
	// 	{
	// 		positions.push_back(pos);
	// 		pos--;
	// 	}
	// 	lastPos = val;
	// 	i++;
	// }
	// while (val++ < size)
	// 	positions.push_back(val);

	std::vector<int>::size_type i = 0;
	size_t indexToStart;
	size_t lastIndexToStart = 1;


	while (i < jacobSequence.size())
	{
		indexToStart = jacobSequence[i];
		// _posVec.push_back(indexToStart);
		// --indexToStart;
		while (indexToStart > lastIndexToStart)
		{
			std::cout << std::endl;
			positions.push_back(indexToStart);
			--indexToStart;
		}
		lastIndexToStart = jacobSequence[i];
		i++;
	}
	while (lastIndexToStart < size)
	{
		positions.push_back(++lastIndexToStart);
		// lastIndexToStart++;
	}
	return (positions);
}
int main(void)
{
	int size = 20;
	std::vector<int> positions;

	positions = generatPositions(size);

	std::cout << '\n' << "positions: ";
	for (std::vector<int>::iterator it = positions.begin(); it != positions.end(); it++)
		std::cout << *it << " ";

	return (0);

}