/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:14:34 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/30 17:06:54 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
static void	tryToFind(T& container, int value)
{
	try
	{
		typename T::iterator	it = easyfind(container, value);

		std::cout << "found " << *it << " at index "
			<< std::distance(container.begin(), it) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "could not find " << value << ": " << e.what()
			<< std::endl;
	}
}

static void	testVector(void)
{
	std::vector<int>	numbers;

	numbers.push_back(42);
	numbers.push_back(7);
	numbers.push_back(13);
	numbers.push_back(7);

	std::cout << "vector: [42, 7, 13, 7]" << std::endl;
	tryToFind(numbers, 42);
	tryToFind(numbers, 7);
	tryToFind(numbers, 13);
	tryToFind(numbers, 21);
}

static void	testList(void)
{
	std::list<int>	numbers;

	numbers.push_back(-1);
	numbers.push_back(0);
	numbers.push_back(1);

	std::cout << std::endl << "list: [-1, 0, 1]" << std::endl;
	tryToFind(numbers, 0);
	tryToFind(numbers, -1);
	tryToFind(numbers, 100);
}

static void	testDeque(void)
{
	std::deque<int>	numbers;

	numbers.push_back(10);
	numbers.push_front(5);

	std::cout << std::endl << "deque: [5, 10]" << std::endl;
	tryToFind(numbers, 5);
	tryToFind(numbers, 10);
}

static void	testEmptyContainer(void)
{
	std::vector<int>	empty;

	std::cout << std::endl << "empty vector: []" << std::endl;
	tryToFind(empty, 0);
}

static void	testConstContainer(void)
{
	std::vector<int>	source;

	source.push_back(1);
	source.push_back(2);
	source.push_back(3);

	const std::vector<int>&	numbers = source;

	std::cout << std::endl << "const vector: [1, 2, 3]" << std::endl;
	try
	{
		std::vector<int>::const_iterator	it = easyfind(numbers, 2);

		std::cout << "found " << *it << " at index "
			<< std::distance(numbers.begin(), it) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "could not find 2: " << e.what() << std::endl;
	}
}

static void	testWritingThroughIterator(void)
{
	std::vector<int>	numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	std::cout << std::endl << "the returned iterator is a real iterator"
		<< std::endl;
	*easyfind(numbers, 2) = 99;
	for (std::vector<int>::iterator it = numbers.begin();
		it != numbers.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main(void)
{
	testVector();
	testList();
	testDeque();
	testEmptyContainer();
	testConstContainer();
	testWritingThroughIterator();
	return (0);
}
