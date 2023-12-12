/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:18:33 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/12 17:10:52 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private:
		T*		_arr;
		size_t	_size;

	public:
		Array(void): _arr(NULL), _size(0)
		{
		};
		Array(unsigned int n): _arr(new T(n)), _size(n)
		{
		};
		Array(const Array& src)
		{
			*this = src;
		};
		Array&	operator=(const Array& src)
		{
			if (*this == src)
				return *this;
			else if (_size != src._size)
			{
				if (_size != 0)
					delete[] _arr;
				_arr = new T[src._size];
				_size = src._size;
			}
			for (size_t i = 0; i < _size; i++)
			{
				_arr[i] = src._arr[i];
			}
			return *this;
		};
		~Array(void)
		{
			if (_size != 0)
				delete[] _arr;
		};

		T&	operator[](size_t index) const
		{
			if (index > _size)
				throw Array::InvalidIndex();
			else
				return _arr[index];
		};

		int	size(void) const
		{
			return _size;
		};

		class InvalidIndex: public std::exception
		{
			public: virtual const char *what() const throw()
			{
				return "Invalid index";
			}
		};
};
