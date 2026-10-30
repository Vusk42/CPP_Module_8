/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:29:15 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 16:13:15 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstddef>
# include <exception>
# include <iterator>
# include <vector>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		explicit Span(unsigned int n);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span(void);

		void	addNumber(int number);
		template <typename Iterator>
		void	addNumbers(Iterator first, Iterator last);

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		unsigned int	size(void) const;
		unsigned int	maxSize(void) const;

		class SpanFullException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

template <typename Iterator>
void	Span::addNumbers(Iterator first, Iterator last)
{
	typename std::iterator_traits<Iterator>::difference_type	count;

	count = std::distance(first, last);
	if (count < 0 || this->_numbers.size() + static_cast<std::size_t>(count)
		> static_cast<std::size_t>(this->_maxSize))
		throw Span::SpanFullException();
	this->_numbers.insert(this->_numbers.end(), first, last);
}

#endif
