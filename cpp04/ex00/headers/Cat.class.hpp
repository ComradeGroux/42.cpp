/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:11:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:21:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.class.hpp"

class Cat: virtual public Animal
{
	private:

	public:
		Cat(void);
		Cat(const Cat& src);
		Cat& operator=(const Cat& src);
		~Cat(void);

		void	makeSound(void) const;
};

#endif
