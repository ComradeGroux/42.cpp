/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:34:18 by vgroux            #+#    #+#             */
/*   Updated: 2023/09/19 14:32:22 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"

class FragTrap: public ClapTrap
{
	private:
		FragTrap(void);
		
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap& src);
		~FragTrap(void);

		void	highFivesGuys(void);
};

#endif
