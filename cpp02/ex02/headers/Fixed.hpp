/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:25:57 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/20 22:14:38 by vgroux           ###   ########.fr       */
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
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& src);
		Fixed&	operator=(const Fixed& rhs);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed&	min(Fixed& n1, Fixed& n2);
		static const Fixed&	min(const Fixed& n1, const Fixed& n2);
		static Fixed&	max(Fixed& n1, Fixed& n2);
		static const Fixed&	max(const Fixed& n1, const Fixed& n2);
		
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator>(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		friend std::ostream	&operator<<(std::ostream &ostr, const Fixed& rhs);

};

#endif