/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:34:28 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/03 12:30:29 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_wp;

	public:
		HumanA(std::string name, Weapon& weapon);
		HumanA(const HumanA& src);
		~HumanA(void);
		HumanA& operator=(const HumanA& rhs);
		void		attack(void) const;
		std::string getName(void) const;
		void		setName(std::string name);
		Weapon		getWeapon(void) const;
		void		setWeapon(const Weapon& weapon);
};

#endif
