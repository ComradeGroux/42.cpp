/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:25:57 by vgroux            #+#    #+#             */
/*   Updated: 2023/04/17 21:54:26 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
		void			debug(void);
		void			info(void);
		void			warning(void);
		void			error(void);
		typedef	void	(Harl::*f)();

	public:
		Harl(void);
		Harl(const Harl& src);
		~Harl(void);
		Harl&	operator=(const Harl& rhs);
		void	complain(std::string level);
};

#endif