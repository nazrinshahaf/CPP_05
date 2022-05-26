/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:33:44 by nfernand          #+#    #+#             */
/*   Updated: 2022/05/26 13:08:13 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

using	std::string;

class	Intern
{
	public:
		Intern();
		Intern(Intern const &tocopy);
		~Intern();

		Intern		&operator=(Intern const &tocopy);

		Form		*makeForm(string const name, string const target);

	private:
};

#endif
