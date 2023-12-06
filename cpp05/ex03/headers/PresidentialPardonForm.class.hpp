/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:07 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/06 15:56:25 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.class.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm(void);

		std::string	getTarget(void) const;

		void		execute(Bureaucrat const & executor) const;
		
};
