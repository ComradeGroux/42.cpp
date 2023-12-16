/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:34:09 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/16 13:48:31 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

Span::Span(void)
{
};

Span::Span(unsigned int N): _size(N)
{
};

Span::Span(const Span& src)
{
	*this = src;
};

Span&	Span::operator=(const Span& src)
{
	_size = src._size;
	_content = src._content;
	return *this;
};

Span::~Span(void)
{
};

void	Span::addNumber(int n)
{
	if (_content.size() < _size)
		_content.push_back(n);
	else
		throw Span::TooMuchElementException();
};

unsigned int	Span::shortestSpan(void) const
{
	if (_size <= 2)
		throw Span::TooMuchElementException();
	
	std::vector<int>	cp = _content;
	std::sort(cp.begin(), cp.end());

	long	minValue;
	long	maxValue;
	for (unsigned int i = 0; i < cp.size(); i++)
	{
		minValue = min(cp[i], cp[i + 1]);
		maxValue = min(cp[i], cp[i + 1]);
	}
};

unsigned int	Span::longestSpan(void) const
{
	if (_size <= 2)
		throw Span::TooMuchElementException();
};
