/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:34:28 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 12:31:06 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_wp;

	public:
		HumanB(std::string);
		HumanB(const HumanB& src);
		~HumanB(void);
		HumanB& operator=(const HumanB& rhs);

		void		attack(void) const;
		std::string getName(void) const;
		void		setName(std::string name);
		Weapon		getWeapon(void) const;
		void		setWeapon(const Weapon& weapon);
};

#endif
