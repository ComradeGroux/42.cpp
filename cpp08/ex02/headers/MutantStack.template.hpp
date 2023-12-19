/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:36:01 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/19 16:25:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	private:

	public:
		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T> &src);
		MutantStack<T>&	operator=(const MutantStack<T> &src);
		~MutantStack<T>(void);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void);
		iterator	end(void);
};
