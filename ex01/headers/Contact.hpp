/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:36:11 by vgroux            #+#    #+#             */
/*   Updated: 2023/03/28 20:51:58 by vgroux           ###   ########.fr       */
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
	std::string	getFirstname(void);
	std::string	getLastname(void);
	std::string	getNickname(void);
	int			getPhone(void);
	std::string	getSecret(void);
	void		printInfo(void);
	void		printFull(void);
	bool		isNull(void);
};

#endif