/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:24:25 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/30 17:08:51 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <unistd.h>

struct RandomInt
{
	int	operator()(void) const
	{
		return (std::rand() - RAND_MAX / 2);
	}
};

static void	testSubject(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	testFullSpan(void)
{
	Span	sp(3);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	try
	{
		sp.addNumber(4);
		std::cout << "the fourth number was added, this is wrong" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	testNotEnoughNumbers(void)
{
	Span	empty(10);
	Span	alone(10);

	alone.addNumber(42);
	try
	{
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "empty span: " << e.what() << std::endl;
	}
	try
	{
		std::cout << alone.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "single number: " << e.what() << std::endl;
	}
}

static void	testRangeOfIterators(void)
{
	std::list<int>	source;
	Span			sp(6);

	source.push_back(4);
	source.push_back(8);
	source.push_back(15);
	source.push_back(16);
	source.push_back(23);
	source.push_back(42);

	sp.addNumbers(source.begin(), source.end());
	std::cout << "filled with " << sp.size() << " numbers in one call"
		<< std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest : " << sp.longestSpan() << std::endl;
}

static void	testRangeTooBig(void)
{
	std::vector<int>	source(10, 1);
	Span				sp(5);

	try
	{
		sp.addNumbers(source.begin(), source.end());
		std::cout << "the range was added, this is wrong" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "the span still holds " << sp.size() << " numbers"
		<< std::endl;
}

static void	testManyNumbers(unsigned int amount)
{
	std::vector<int>	source(amount);
	Span				sp(amount);

	std::generate(source.begin(), source.end(), RandomInt());
	sp.addNumbers(source.begin(), source.end());
	std::cout << amount << " numbers -> shortest: " << sp.shortestSpan()
		<< ", longest: " << sp.longestSpan() << std::endl;
}

static void	testExtremeValues(void)
{
	Span	sp(2);

	sp.addNumber(-2147483647 - 1);
	sp.addNumber(2147483647);
	std::cout << "span between INT_MIN and INT_MAX: " << sp.longestSpan()
		<< std::endl;
}

static void	testCanonicalForm(void)
{
	Span	original(4);
	Span	assigned;

	original.addNumber(1);
	original.addNumber(10);

	Span	copy(original);

	assigned = original;
	copy.addNumber(100);

	std::cout << "original: " << original.size() << " numbers, longest "
		<< original.longestSpan() << std::endl;
	std::cout << "copy    : " << copy.size() << " numbers, longest "
		<< copy.longestSpan() << std::endl;
	std::cout << "assigned: " << assigned.size() << " numbers, longest "
		<< assigned.longestSpan() << std::endl;
}

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL) ^ ::getpid()));

	std::cout << "=== Subject example ===" << std::endl;
	testSubject();

	std::cout << std::endl << "=== Adding one number too many ===" << std::endl;
	testFullSpan();

	std::cout << std::endl << "=== Not enough numbers to make a span ==="
		<< std::endl;
	testNotEnoughNumbers();

	std::cout << std::endl << "=== Filling with a range of iterators ==="
		<< std::endl;
	testRangeOfIterators();

	std::cout << std::endl << "=== Range bigger than the span ===" << std::endl;
	testRangeTooBig();

	std::cout << std::endl << "=== A lot of numbers ===" << std::endl;
	testManyNumbers(10000);
	testManyNumbers(100000);
	testManyNumbers(1000000);

	std::cout << std::endl << "=== Extreme values ===" << std::endl;
	testExtremeValues();

	std::cout << std::endl << "=== Orthodox canonical form ===" << std::endl;
	testCanonicalForm();
	return (0);
}
