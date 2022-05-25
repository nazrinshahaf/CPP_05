/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:29 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 21:09:14 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : Form("_shrubberyCreationForm", 145, 137)
{
	cout << GREEN "ShrubberyCreationForm Default Constructor called" RESET << endl;
	this->_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(string const target) : Form(target + "_shrubberyCreationForm", 145, 137)
{
	cout << GREEN "ShrubberyCreationForm Assignment Constructor called" RESET << endl;
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << RED "ShrubberyCreationForm Destructor called" RESET << endl;
}

void		ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	try
	{
		if (bureaucrat.getGrade() > this->getGradeToExec())
			throw Form::GradeTooLowException("Grade Too Low", "grade_to_exec", bureaucrat.getGrade(), "ShrubberyCreationForm");
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't execute " MAGENTA "<" << this->getName() << ">" RESET << endl
		<< "with execute requirement of: " << this->getGradeToExec() << endl
		<< "bureaucrat only has grade: " << bureaucrat.getGrade() << endl
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET << endl;
		return ;
	}
	try
	{
		if (this->getIsSigned() == false)
			throw Form::FormNotSigned("Form Not Signed", "ShrubberyCreationForm");
	}
	catch (Form::FormNotSigned &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
		cout << MAGENTA "<" << bureaucrat.getName() << "> " RESET
			<< "couldn't execute form because it has not been signed yet." << endl;
		return ;
	}
		std::ofstream	file(this->_target + "_shrubbery");

		cout << MAGENTA "<" << bureaucrat.getName() << "> " RESET
			<< "executing form " BLUE "<" << this->getName() << ">" RESET << endl;

		file << "⠀⠀⠀⠀⠀⠀⠀  ⠀⣰⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⡿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠐⢛⣿⡛⠁⣀⠉⠻⠦⠀⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣧⣰⣿⢿⣶⣤⠀⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⣽⣿⣿⣿⡿⠃⡀⠛⠉⠃⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⢾⣿⣿⣿⣇⠀⣼⣿⣆⠀⣀⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣼⣿⣧⠙⢷⣿⣷⣄⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣀⡀⠙⠉⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠴⢿⣿⣿⣿⠿⠟⠻⢿⣿⣿⢿⣿⡶⠛⠷⠆⠀⠀⠀" << endl;
		file << "⠀⠀⠀⢀⣾⣿⣿⣿⢀⣴⣶⣤⡈⠛⠀⣄⡉⠀⢰⡄⠀⠀⠀" << endl;
		file << "⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣿⣿⣿⣶⣿⡄⠀⠀" << endl;
		file << "⠀⠀⠉⠉⠀⠀⠿⠿⠛⠋⣿⣿⡟⠿⡿⠉⠛⠿⠿⠛⠋⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠛⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
		file.close();
}

const string	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void			ShrubberyCreationForm::setTarget(string const target)
{
	this->_target = target;
}
