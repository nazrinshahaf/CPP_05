/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:27:17 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 18:23:56 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

#include "Form.hpp"

using	std::string;
using	std::ostream;

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat(string name, int grade);
		Bureaucrat(Bureaucrat const &tocopy);
		~Bureaucrat();

		Bureaucrat		&operator=(Bureaucrat const &tocopy);

		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form &form) const;

		const string	&getName(void) const;
		void			setName(string name);

		int				getGrade(void) const;
		void			setGrade(int grade);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	private:
		Bureaucrat();

		string		_name;
		int			_grade;
};

ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat);

#endif
