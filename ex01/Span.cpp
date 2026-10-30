/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:27:29 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 16:12:50 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
	this->_numbers.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize),
	_numbers(other._numbers)
{
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(void)
{
}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= static_cast<std::size_t>(this->_maxSize))
		throw Span::SpanFullException();
	this->_numbers.push_back(number);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>			sorted;
	std::vector<int>::iterator	it;
	unsigned int				shortest;
	unsigned int				distance;

	if (this->_numbers.size() < 2)
		throw Span::NoSpanException();
	sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	shortest = static_cast<unsigned int>(sorted.back())
		- static_cast<unsigned int>(sorted.front());
	for (it = sorted.begin() + 1; it != sorted.end(); ++it)
	{
		distance = static_cast<unsigned int>(*it)
			- static_cast<unsigned int>(*(it - 1));
		if (distance < shortest)
			shortest = distance;
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	int	smallest;
	int	biggest;

	if (this->_numbers.size() < 2)
		throw Span::NoSpanException();
	smallest = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	biggest = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (static_cast<unsigned int>(biggest)
		- static_cast<unsigned int>(smallest));
}

unsigned int	Span::size(void) const
{
	return (static_cast<unsigned int>(this->_numbers.size()));
}

unsigned int	Span::maxSize(void) const
{
	return (this->_maxSize);
}

const char*	Span::SpanFullException::what(void) const throw()
{
	return ("Span: the span is already full");
}

const char*	Span::NoSpanException::what(void) const throw()
{
	return ("Span: at least two numbers are needed to find a span");
}
