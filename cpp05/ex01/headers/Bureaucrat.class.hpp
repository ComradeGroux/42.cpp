#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include "Form.class.hpp"
# include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		int					_validateGrade(const int grade);

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);
		Bureaucrat&	operator=(const Bureaucrat& rhs);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		promote(void);
		void		demote(void);
		void		signForm(Form &f) const;

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

std::ostream &operator<<(std::ostream &ostr, const Bureaucrat& rhs);

#endif
