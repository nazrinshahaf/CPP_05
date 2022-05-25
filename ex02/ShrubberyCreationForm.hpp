/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:10:11 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 21:09:20 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

using	std::string;

class	Bureaucrat;

class	ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &tocopy);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &tocopy);

		void					execute(Bureaucrat const &bureaucrat) const;

		const string			&getTarget(void) const;
		void					setTarget(string const target);

	private:
		string		_target;
};

#endif
