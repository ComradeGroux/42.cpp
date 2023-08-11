/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:11:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/11 15:42:04 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.class.hpp"
#include "Brain.class.hpp"

class Cat: virtual public Animal
{
	private:
		Brain*	brain;
		
	public:
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& src);
		~Cat(void);

		void	makeSound(void) const;
};

#endif
