/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:40:32 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 20:52:41 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;
using	std::exception;

Form::Form()
{
	cout << GREEN "Form Default Constructor called" RESET << endl;
}

Form::~Form()
{
	cout << RED "Form Destructor called" RESET << endl;
}

Form::Form(string const name, int grade_to_sign, int grade_to_exec)
{
	cout << GREEN "Form Assignment Constructor called" RESET << endl;
	this->_name = name;
	this->_who_signed = "";
	this->_grade_to_sign = grade_to_sign;
	this->_grade_to_exec = grade_to_exec;
	this->_is_signed = false;
	if (grade_to_sign < 1)
		throw GradeTooHighException("Grade Too High", "grade_to_sign", _grade_to_sign, "Form Constructor");
	else if (grade_to_sign > 150)
		throw GradeTooLowException("Grade Too Low", "grade_to_sign", _grade_to_sign, "Form Constructor");
	if (grade_to_exec < 1)	
		throw GradeTooHighException("Grade Too High", "grade_to_exec", _grade_to_exec, "Form Constructor");
	else if (grade_to_exec > 150)
		throw GradeTooLowException("Grade Too Low", "grade_to_exec", _grade_to_exec, "Form Constructor");
}

Form::Form(Form const &tocopy)
{
	cout << BLUE "Form Copy Constructor called" RESET << endl;
	this->_name = tocopy.getName();
	this->_who_signed = tocopy.getWhoSigned();
	this->_grade_to_sign = tocopy.getGradeToSign();
	this->_grade_to_exec = tocopy.getGradeToExec();
	this->_is_signed = tocopy.getIsSigned();
}

Form				&Form::operator=(Form const &tocopy)
{
	cout << BLUE "Form Copy Assignment called" RESET << endl;
	this->_name = tocopy.getName();
	this->_who_signed = tocopy.getWhoSigned();
	this->_grade_to_sign = tocopy.getGradeToSign();
	this->_grade_to_exec = tocopy.getGradeToExec();
	this->_is_signed = tocopy.getIsSigned();
	return (*this);
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_is_signed == false)
	{
		if (bureaucrat.getGrade() <= this->_grade_to_sign)
		{
			this->_is_signed = true;
			this->_who_signed = bureaucrat.getName();
		}
		else
			throw GradeTooLowException("Grade Too Low", "grade_to_sign", _grade_to_sign, "beSigned Member Function");
	}
	else
		cout << "Form has already been signed by: " MAGENTA "<" << this->_who_signed << ">." RESET << endl;
}

const string		&Form::getName(void) const
{
	return (this->_name);
}

void				Form::setName(string const name)
{
	this->_name = name;
}

int					Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

void				Form::setGradeToSign(int grade)
{
	this->_grade_to_sign = grade;
}

int					Form::getGradeToExec(void) const
{
	return (this->_grade_to_exec);
}

void				Form::setGradeToExec(int grade)
{
	this->_grade_to_sign = grade;
}

const string		&Form::getWhoSigned(void) const
{
	return (this->_who_signed);
}

void				Form::setWhoSigned(string const who_signed)
{
	this->_who_signed = who_signed;
}

bool				Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

void				Form::setIsSigned(bool is_signed)
{
	this->_is_signed = is_signed;
}

ostream& operator<<(ostream& os, const Form& form)
{
	os << MAGENTA "=========================" RESET << endl
		<< MAGENTA "<" << form.getName() << ">" RESET << endl
		<< "grade_to_sign of: " << form.getGradeToSign() << endl
		<< "grade_to_exec of: " << form.getGradeToExec() << endl;
	if (form.getIsSigned() == true)
		os << "signed by: " BLUE "<" << form.getWhoSigned() << ">." RESET;
	else
		os << "is not signed.";
	os << endl << MAGENTA "=========================" RESET << endl;
	return (os);
}

/*
 * Form::GradeTooHighException class
 * */

Form::GradeTooHighException::GradeTooHighException(string err_msg, string which_grade, int init_grade, string which_function) :
	_err_msg(err_msg),
	_which_grade(which_grade),
	_init_grade(init_grade),
	_which_function(which_function) {}

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT {}

const char			*Form::GradeTooHighException::what(void) const throw()
{
	return (this->_err_msg.c_str());
}

string	Form::GradeTooHighException::getWhichGrade() const
{ 
	return this->_which_grade; 
}

string	Form::GradeTooHighException::getWhichFunction() const
{ 
	return this->_which_function; 
}

int		Form::GradeTooHighException::getInitGrade() const 
{
	return this->_init_grade;
}

/*
 * Form::GradeTooLowException class
 * */

Form::GradeTooLowException::GradeTooLowException(string err_msg, string which_grade, int init_grade, string which_function) :
	_err_msg(err_msg),
	_which_grade(which_grade),
	_init_grade(init_grade),
	_which_function(which_function) {}

Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT {}

const char			*Form::GradeTooLowException::what(void) const throw()
{
	return (this->_err_msg.c_str());
}

string	Form::GradeTooLowException::getWhichGrade() const
{ 
	return this->_which_grade; 
}

string	Form::GradeTooLowException::getWhichFunction() const
{ 
	return this->_which_function; 
}

int		Form::GradeTooLowException::getInitGrade() const 
{
	return this->_init_grade;
}

/*
 * Form::NotSigned class
 * */

Form::FormNotSigned::FormNotSigned(string err_msg, string which_function) :
	_err_msg(err_msg),
	_which_function(which_function) {}

Form::FormNotSigned::~FormNotSigned() _NOEXCEPT {}

const char	*Form::FormNotSigned::what(void) const throw()
{
	return (this->_err_msg.c_str());
}

string	Form::FormNotSigned::getWhichFunction() const
{ 
	return this->_which_function; 
}
