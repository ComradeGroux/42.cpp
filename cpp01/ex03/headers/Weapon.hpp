/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:22:29 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/10 16:33:26 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(std::string str);
		Weapon(const Weapon& src);
		~Weapon(void);
		std::string	getType(void) const;
		void		setType(std::string str);
};

#endif
