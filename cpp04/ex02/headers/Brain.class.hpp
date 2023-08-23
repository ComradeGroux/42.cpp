/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:41:16 by vgroux            #+#    #+#             */
/*   Updated: 2023/08/14 15:51:17 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <string>
# include <time.h>
# include <iostream>
# include <stdlib.h>
# include <sstream>

# define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class Brain
{
	private:

	public:
		std::string ideas[100];
		Brain(void);
		Brain(const Brain& src);
		Brain& operator=(const Brain& src);
		~Brain(void);

		std::string	getIdea(int i) const;
};

#endif
