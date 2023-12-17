/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:07:29 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/17 21:19:53 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <algorithm>
#include <limits>

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
		void	addNumber(std::vector<int>::iterator a, std::vector<int>::iterator b);

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		std::vector<int>	getContent(void) const;
		
		class TooMuchElementException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotEnoughElementException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
