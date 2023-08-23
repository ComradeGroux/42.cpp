/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:00:22 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/23 15:13:34 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>
#include <string>

// Classe abstrait: Classe avec une methode/fonction() const = 0;
class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		virtual ~Animal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
