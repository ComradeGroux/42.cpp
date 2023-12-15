/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:07:29 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/15 21:09:13 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Span
{
	private:
		unsigned int	_N;
		Span(void);

	public:
		Span(unsigned int N);
		Span(const Span& src);
		Span&	operator=(const Span& src);
		~Span(void);

		void	addNumber
};
