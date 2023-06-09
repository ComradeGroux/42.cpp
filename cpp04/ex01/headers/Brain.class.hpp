/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:41:16 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/09 17:43:10 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

class Brain
{
	private:
		std::string idea[100];

	public:
		Brain(void);
		Brain(const Brain& src);
		Brain& operator=(cosnt Brain& src);
		~Brain(void);
}

#endif
