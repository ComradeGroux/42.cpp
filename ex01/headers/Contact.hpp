/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:36:11 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/29 14:18:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

class Contact
{
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	int			phone;
	std::string	secret;

public:
	Contact(void);
	Contact(std::string firstname,
			std::string lastname,
			std::string nickname,
			int phone,
			std::string secret);
	~Contact(void);
	std::string	getFirstname(void) const;
	std::string	getLastname(void) const;
	std::string	getNickname(void) const;
	int			getPhone(void) const;
	std::string	getSecret(void) const;
	void		printInfo(void) const;
	void		printFull(void) const;
	bool		isNull(void) const;
};

#endif