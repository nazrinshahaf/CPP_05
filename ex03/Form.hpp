/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:40:49 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 21:58:48 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CPP
# define FORM_CPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

using	std::string;
using	std::exception;
using	std::ostream;

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(string const name, int grade_to_sign, int grade_to_exec);
		Form(Form const &tocopy);
		virtual ~Form();

		Form			&operator=(Form const &tocopy);

		virtual void	execute(Bureaucrat const &bureaucrat) const = 0;
		virtual bool	checkExecutable(Bureaucrat const &bureaucrat) const;

		void			beSigned(Bureaucrat const &bureaucrat);

		const string	&getName(void) const;
		void			setName(string const name);

		int				getGradeToSign(void) const;
		void			setGradeToSign(int grade);

		int				getGradeToExec(void) const;
		void			setGradeToExec(int grade);

		const string	&getWhoSigned(void) const;
		void			setWhoSigned(string const who_signed);

		bool			getIsSigned(void) const;
		void			setIsSigned(bool is_signed);

		class	GradeTooHighException : public exception
		{
			public:
				GradeTooHighException(string err_msg, string which_grade, int init_grade, string which_function);
				~GradeTooHighException() _NOEXCEPT;
				
				virtual const char	*what(void) const throw();
				string	getWhichGrade() const;
				string	getWhichFunction() const;
				int		getInitGrade() const;

			private:
				string	_err_msg;
				string	_which_grade;
				int		_init_grade;
				string	_which_function;
		};

		class	GradeTooLowException : public exception
		{
			public:
				GradeTooLowException(string err_msg, string which_grade, int init_grade, string which_function);
				~GradeTooLowException() _NOEXCEPT;

				virtual const char	*what(void) const throw();
				string	getWhichGrade() const;
				int		getInitGrade() const;
				string	getWhichFunction() const;

			private:
				string	_err_msg;
				string	_which_grade;
				int		_init_grade;
				string	_which_function;
		};

		class	FormNotSigned : public exception
		{
			public:
				FormNotSigned(string err_msg, string which_function);
				~FormNotSigned() _NOEXCEPT;

				virtual const char	*what(void) const throw();
				string	getWhichFunction() const;

			private:
				string	_err_msg;
				string	_which_function;
		};

	private:
		string	_name;
		string	_who_signed;
		int		_grade_to_sign;
		int		_grade_to_exec;
		bool	_is_signed;

};

ostream& operator<<(ostream& os, const Form& form);

#endif
