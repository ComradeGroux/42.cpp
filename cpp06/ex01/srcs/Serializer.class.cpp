/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:32:59 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 17:24:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default Serialize's constructor called";
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
