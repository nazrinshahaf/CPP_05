/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:15:42 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/20 18:12:08 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

using	std::string;

class	Bureaucrat;

class	RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(string const target);
		RobotomyRequestForm(RobotomyRequestForm const &tocopy);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &tocopy);

		void					execute(Bureaucrat const &bureaucrat) const;

		const string			&getTarget(void) const;
		void					setTarget(string const target);

	private:
		string		_target;
};

#endif
