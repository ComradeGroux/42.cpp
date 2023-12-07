/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:35 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 17:24:41 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"

int	main(void)
{
	Data	d;	
	d.name = "BOBER";

	std::cout << "Original Data value: " << d.name << std::endl;
	std::cout << "Original Data addr : " << &d << std::endl;

	uintptr_t	raw = Serializer::serialize(&d);
	std::cout << "Raw Data: " << raw << std::endl;

	Data*	deserialized = Serializer::deserialize(raw);
	std::cout << "Final Data value: " << deserialized->name << std::endl;
	std::cout << "Final Data addr : " << deserialized << std::endl;

	return 0;
}