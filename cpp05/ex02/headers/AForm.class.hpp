/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:20:58 by vgroux            #+#    #+#             */
/*   Updated: 2023/12/04 18:30:56 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
# include "Bureaucrat.class.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_gradeSign;
		int					_gradeExe;
		int					_validateGrade(int n);

	protected:
		bool				require(const Bureaucrat &b) const;
		
	public:
		AForm(std::string name, int gradeToSign, int gradeToExe);
		AForm(const AForm& src);
		~AForm(void);
		AForm &operator=(const AForm& rhs);

		const std::string	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		virtual bool		execute(Bureaucrat const & executor) const = 0;
		
		void				beSigned(const Bureaucrat &b);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &stream, const AForm& rhs);

#endif
