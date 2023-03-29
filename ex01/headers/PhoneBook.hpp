/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:34:36 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 21:54:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];
		std::string	addStr(std::string str);
		int			addInt(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		int		numberContact(void);
		void	displayTable(void);
};

#endif