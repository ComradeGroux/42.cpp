/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:28 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 17:08:19 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdint.h>
# include <iostream>
# include "data.hpp"

class Serializer
{
	private:
		Serializer(void);
		
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};
