/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:07:46 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 22:20:19 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PresidentialPardonForm.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

PresidentialPardonForm::PresidentialPardonForm() : Form("_robotomyCretionForm", 25, 5)
{
	cout << GREEN "PresidentialPardonForm Default Constructor called" RESET << endl;
	this->_target = "";
}

PresidentialPardonForm::PresidentialPardonForm(string const target) : Form(target + "_robotomyCretionForm", 25, 5)
{
	cout << GREEN "PresidentialPardonForm Assignment Constructor called" RESET << endl;
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << RED "PresidentialPardonForm Destructor called" RESET << endl;
}

void			PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if (this->checkExecutable(bureaucrat) == false)
		return ;

	cout << MAGENTA "<" << this->_target << "> " RESET "has been pardoned by " RED "<Zaphod Beeblebrox>" RESET 
		<< " for any offences he may or may not have commited. (He definitely commited them)" << endl;
}

const string	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void			PresidentialPardonForm::setTarget(string const target)
{
	this->_target = target;
}
