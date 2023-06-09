/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:21:14 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:22:21 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include "Animal.class.hpp"

class Dog: virtual public Animal
{
	private:

	public:
		Dog(void);
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		~Dog(void);

		void	makeSound(void) const;
};

#endif
