/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:55:23 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/04 11:17:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie(void);
		Zombie(std::string name);
		Zombie(const Zombie& src);
		Zombie& operator=(const Zombie& rhs);
		std::string	getName(void) const;
		void		setName(std::string newName);
		void		announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif