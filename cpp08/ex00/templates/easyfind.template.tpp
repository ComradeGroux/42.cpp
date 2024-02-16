/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.template.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:31:31 by vgroux            #+#    #+#             */
/*   Updated: 2024/02/16 16:13:25 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.template.hpp"

template <typename T>
typename T::value_type easyfind(T& cont, int toFind)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), toFind);
	
	if (it != cont.end())
		return *it;
	else
		throw std::runtime_error("NotFoundException");
}
