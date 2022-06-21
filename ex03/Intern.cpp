/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfernand <nfernand@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:32:29 by nfernand          #+#    #+#             */
/*   Updated: 2022/06/21 10:53:39 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Intern.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

Intern::Intern()
{
	cout << GREEN "Intern Default Constructor called" RESET << endl;
}

Intern::~Intern()
{
	cout << RED "Intern Destructor called" RESET << endl;
}

Intern::Intern(Intern const &tocopy)
{
	cout << GREEN "Intern Copy Constructor called" RESET << endl;
	(void)tocopy;
}

Intern		&Intern::operator=(Intern const &tocopy)
{
	cout << GREEN "Intern Copy Assignment Operator called" RESET << endl;
	(void)tocopy;
	return (*this);
}

Form		*makePresidentialPardonForm(string const target)
{
	Form	*form = new PresidentialPardonForm(target);

	return (form);
}

Form		*makeRobotomyRequestForm(string const target)
{
	Form	*form = new RobotomyRequestForm(target);

	return (form);
}

Form		*makeShrubberyCreationForm(string const target)
{
	Form	*form = new ShrubberyCreationForm(target);

	return (form);
}

Form		*Intern::makeForm(string const name, string const target)
{
	int			index = -1;
	string		list[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	Form*		(*array[3])(string) = {&makePresidentialPardonForm, &makeRobotomyRequestForm,
										&makeShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (name == list[i])
		{
			cout << "An unpaid intern has created a " MAGENTA "<" << list[i] + " form" << ">" RESET << endl;
			index = i;
		}
	}
	if (index == -1)
	{
		cout << "An unpaid intern has " RED "[failed] " RESET "to create "
			<< MAGENTA "<" << name + " form" << ">" RESET << endl;
		return (NULL);
	}
	return (array[index](target));
}
