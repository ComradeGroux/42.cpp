/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:25:57 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 12:03:35 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_nbBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed(void);
		Fixed&				operator=(const Fixed& rhs);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
};

std::ostream	&operator<<(std::ostream &ostr, const Fixed& rhs);

#endif
