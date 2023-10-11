/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:00:22 by vgroux            #+#    #+#             */
/*   Updated: 2023/10/11 13:57:19 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP

#include <iostream>
#include <string>

// Classe abstrait: Classe avec une methode/fonction() const = 0;
class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal& src);
		AAnimal& operator=(const AAnimal& src);
		virtual ~AAnimal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
