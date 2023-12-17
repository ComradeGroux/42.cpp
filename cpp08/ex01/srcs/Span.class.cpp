/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:34:09 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/17 21:06:42 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>

Span::Span(void)
{
}

Span::Span(unsigned int N): _size(N)
{
}

Span::Span(const Span& src)
{
	*this = src;
}

Span&	Span::operator=(const Span& src)
{
	_size = src._size;
	_content = src._content;
	return *this;
}

Span::~Span(void)
{
}

int	Span::min(int i, int j) const
{
	if (i < j)
		return i;
	else
		return j;
}

int	Span::max(int i, int j) const
{
	if (i < j)
		return j;
	else
		return i;
}

void	Span::addNumber(int n)
{
	if (_content.size() < _size)
		_content.push_back(n);
	else
		throw Span::TooMuchElementException();
}

unsigned int	Span::shortestSpan(void) const
{
	if (_content.size() < 2)
		throw Span::NotEnoughElementException();
	
	std::vector<int>	cp = _content;
	std::sort(cp.begin(), cp.end());

	// std::cout << cp[0] << "\t" << cp[1] << std::endl;
	long			minValue;
	long			maxValue;
	unsigned int	sspan = __UINT32_MAX__;
	for (unsigned int i = 0; i < cp.size() - 1; i++)
	{
		minValue = min(cp[i], cp[i + 1]);
		maxValue = max(cp[i], cp[i + 1]);
		if (maxValue - minValue < sspan)
			sspan = maxValue - minValue;
	}
	return sspan;
}

unsigned int	Span::longestSpan(void) const
{
	if (_content.size() < 2)
		throw Span::NotEnoughElementException();

	std::vector<int>	cp = _content;
	std::sort(cp.begin(), cp.end());

	long			minValue;
	long			maxValue;
	unsigned int	sspan = 0;
	for (unsigned int i = 0; i < cp.size(); i++)
	{
		minValue = min(cp[i], cp[i + 1]);
		maxValue = max(cp[i], cp[i + 1]);
		if (maxValue - minValue >	 sspan)
			sspan = maxValue - minValue;
	}
	return sspan;
}

const char *Span::TooMuchElementException::what() const throw()
{
	return "TooMuchElementException";
}

const char *Span::NotEnoughElementException::what() const throw()
{
	return "NotEnoughElementException";
}
