/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:34:36 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/31 11:34:33 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.class.hpp"
#include <cctype>

class PhoneBook
{
	private:
		Contact		_contacts[8];
		std::string	_addStr(std::string str) const;
		std::string _addPhone(std::string str) const;
		bool		_isPhoneNumberValid(std::string str) const;
		std::string	_removeWhitespace(std::string str) const;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		int		numberContacts(void) const;
		void	displayTable(void) const;
};

#endif