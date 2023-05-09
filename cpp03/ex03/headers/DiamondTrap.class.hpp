/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:43 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 16:34:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& src);
		DiamondTrap& operator=(const DiamondTrap& src);
		~DiamondTrap(void);
		
		
		void	whoAmI(void);
		// using	ScavTrap::attack;
		void	attack(const std::string& target);
};

#endif
