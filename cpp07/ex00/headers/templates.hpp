/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:58:24 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/07 18:06:34 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void	swap(T& a, T& b)
{
	T	c = a;
	a = b;
	b = c;
}

template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
