/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:00:59 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/21 21:27:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class PmergeMe
{
	private:
		
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& src);
		PmergeMe&	operator=(const PmergeMe& src);
		~PmergeMe(void);

};
