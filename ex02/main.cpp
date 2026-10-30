/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 17:21:25 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 16:14:04 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

static void	subjectTestWithMutantStack(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
	(void)s;
}

static void	subjectTestWithList(void)
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator	it = mstack.begin();
	std::list<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void	testReverseAndConstIterators(void)
{
	MutantStack<int>	mstack;

	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);

	std::cout << "forward: ";
	for (MutantStack<int>::iterator it = mstack.begin();
		it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "reverse: ";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin();
		it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	const MutantStack<int>&	frozen = mstack;

	std::cout << "const  : ";
	for (MutantStack<int>::const_iterator it = frozen.begin();
		it != frozen.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	testWithAlgorithms(void)
{
	MutantStack<int>	mstack;

	mstack.push(42);
	mstack.push(7);
	mstack.push(19);
	mstack.push(7);

	std::cout << "smallest element: "
		<< *std::min_element(mstack.begin(), mstack.end()) << std::endl;
	std::cout << "biggest element : "
		<< *std::max_element(mstack.begin(), mstack.end()) << std::endl;
	std::cout << "number of 7s    : "
		<< std::count(mstack.begin(), mstack.end(), 7) << std::endl;

	std::vector<int>	copy(mstack.begin(), mstack.end());

	std::sort(copy.begin(), copy.end());
	std::cout << "sorted copy     : ";
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	testAnotherUnderlyingContainer(void)
{
	MutantStack<std::string, std::list<std::string> >	mstack;

	mstack.push("mutated");
	mstack.push("abomination");

	std::cout << "on top of a std::list: ";
	for (MutantStack<std::string, std::list<std::string> >::iterator
		it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	testCanonicalForm(void)
{
	MutantStack<int>	original;

	original.push(1);
	original.push(2);

	MutantStack<int>	copy(original);
	MutantStack<int>	assigned;

	assigned = original;
	copy.push(3);

	std::cout << "original: " << original.size() << " elements, top "
		<< original.top() << std::endl;
	std::cout << "copy    : " << copy.size() << " elements, top "
		<< copy.top() << std::endl;
	std::cout << "assigned: " << assigned.size() << " elements, top "
		<< assigned.top() << std::endl;
}

int	main(void)
{
	std::cout << "=== Subject test with MutantStack ===" << std::endl;
	subjectTestWithMutantStack();

	std::cout << std::endl << "=== Same test with a std::list ===" << std::endl;
	subjectTestWithList();

	std::cout << std::endl << "=== Reverse and const iterators ==="
		<< std::endl;
	testReverseAndConstIterators();

	std::cout << std::endl << "=== Standard algorithms on a stack ==="
		<< std::endl;
	testWithAlgorithms();

	std::cout << std::endl << "=== Another underlying container ==="
		<< std::endl;
	testAnotherUnderlyingContainer();

	std::cout << std::endl << "=== Orthodox canonical form ===" << std::endl;
	testCanonicalForm();
	return (0);
}
