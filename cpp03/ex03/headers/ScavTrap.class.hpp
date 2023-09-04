/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:27:17 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/31 19:06:42 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"

class ScavTrap: public virtual ClapTrap
{
	protected:
		static const int	_defaultHP = 100;
		static const int	_defaultEP = 50;
		static const int	_defaultAD = 20;

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		ScavTrap& operator=(const ScavTrap& src);
		~ScavTrap(void);
		
		void		attack(const std::string& target);
		void		guardGate(void);
};

#endif
