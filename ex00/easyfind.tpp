/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:13:27 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 16:12:17 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("easyfind: value not found in the container");
	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T& container, int value)
{
	typename T::const_iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("easyfind: value not found in the container");
	return (it);
}

#endif
