/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:00:22 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/11 17:41:45 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
