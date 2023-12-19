/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:41 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/19 16:30:25 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.template.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
	*this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &src)
{
	*this = src;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}
