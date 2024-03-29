/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:30:25 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/22 19:54:50 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _value(0)
{
	return ;
}

Fixed::Fixed(const int n)
{
	_value = n << _nbBits;
	return ;
}

Fixed::Fixed(const float n)
{
	_value = roundf(n * (1 << _nbBits));
	return ;
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
	return ;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	return ;
}

int	Fixed::getRawBits(void) const
{
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / (1 << _nbBits);
}

int		Fixed::toInt(void) const
{
	return (_value >> _nbBits);
}

Fixed&	Fixed::min(Fixed& n1, Fixed& n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

const Fixed&	Fixed::min(const Fixed& n1, const Fixed& n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed&	Fixed::max(Fixed& n1, Fixed& n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed&	Fixed::max(const Fixed& n1, const Fixed& n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return res;
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return res;
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	res(this->toFloat() * rhs.toFloat());
	return res;
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	res(this->toFloat() / rhs.toFloat());
	return res;
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

Fixed&	Fixed::operator++(void)
{
	++(this->_value);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	cp(*this);
	
	++(this->_value);
	return cp;
}

Fixed&	Fixed::operator--(void)
{
	--(this->_value);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	cp(*this);

	--(this->_value);
	return cp;
}

std::ostream	&operator<<(std::ostream &stream, const Fixed& rhs)
{
	stream << rhs.toFloat();
	return stream;
}
