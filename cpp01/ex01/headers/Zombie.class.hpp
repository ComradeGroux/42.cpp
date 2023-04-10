/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:55:23 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/10 13:38:54 by vgroux           ###   ########.fr       */
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
		void		announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
