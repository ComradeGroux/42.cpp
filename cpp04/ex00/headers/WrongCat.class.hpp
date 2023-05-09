/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:11:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:21:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.class.hpp"

class WrongCat: virtual public WrongAnimal
{
	private:

	public:
		WrongCat(void);
		WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat& src);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
