/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:07:29 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/16 13:48:15 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_content;
		
		Span(void);
		
		int	min(int i, int j) const;
		int	max(int i, int j) const;

	public:
		Span(unsigned int N);
		Span(const Span& src);
		Span&	operator=(const Span& src);
		~Span(void);

		void	addNumber(int n);

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class TooMuchElementException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
