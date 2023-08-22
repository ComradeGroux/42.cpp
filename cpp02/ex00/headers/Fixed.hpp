/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:25:57 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/22 19:44:47 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_nbBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& src);
		~Fixed(void);
		Fixed&	operator=(const Fixed& rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
