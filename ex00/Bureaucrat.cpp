/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:32:06 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/06/20 16:46:37 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;
using	std::exception;
using	std::ostream;

Bureaucrat::Bureaucrat()
{
	cout << GREEN "Bureaucrat Default Constructor called" RESET << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << RED "Bureaucrat Destructor called" RESET << endl;
}

Bureaucrat::Bureaucrat(string name, int grade)
{
	cout << GREEN "Bureaucrat Assignment Constructor called" RESET << endl;
	this->_grade = grade;
	this->_name = name;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &tocopy)
{
	cout << GREEN "Bureaucrat Copy Constructor called" RESET << endl;
	this->_name = (tocopy.getName());
	this->_grade = (tocopy.getGrade());
}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &tocopy)
{
	cout << GREEN "Bureaucrat Copy Assignment Operator called" RESET << endl;
	this->_name = (tocopy.getName());
	this->_grade = (tocopy.getGrade());
	return (*this);
}

void			Bureaucrat::incrementGrade(void)
{
	try
	{
		if ((this->_grade - 1 ) < 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch(exception &excep)
	{
		cout << "Exception caught: " RED "<" << excep.what() << ">" RESET << endl;
	}
}

void			Bureaucrat::decrementGrade(void)
{
	try
	{
		if ((this->_grade + 1 ) > 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch(exception &excep)
	{
		cout << "Exception caught: " RED "<" << excep.what() << ">" RESET << endl;
	}
}

const string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

void			Bureaucrat::setName(string name)
{
	this->_name = name;
}

int				Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void			Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

ostream& operator<<(ostream& os, const Bureaucrat& bureaucrat)
{
	os << BLUE "<" << bureaucrat.getName() << ">" RESET ", bureaucrat grade: "
		<< MAGENTA "<" << bureaucrat.getGrade() << ">" RESET << endl;
	return (os);
}
