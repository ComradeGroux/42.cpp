/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:55 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:32:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_CLASS_HPP
# define WRONGDOG_CLASS_HPP

#include "WrongAnimal.class.hpp"

class WrongDog: virtual public WrongAnimal
{
	private:

	public:
		WrongDog(void);
		WrongDog(const WrongDog& src);
		WrongDog& operator=(const WrongDog& src);
		~WrongDog(void);

		void	makeSound(void) const;
};

#endif
