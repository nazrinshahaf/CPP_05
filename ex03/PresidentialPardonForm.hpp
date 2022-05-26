/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:06:57 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 22:07:40 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

using	std::string;

class	Bureaucrat;

class	PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(string const target);
		PresidentialPardonForm(PresidentialPardonForm const &tocopy);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &tocopy);

		void					execute(Bureaucrat const &bureaucrat) const;

		const string			&getTarget(void) const;
		void					setTarget(string const target);

	private:
		string		_target;
};

#endif
