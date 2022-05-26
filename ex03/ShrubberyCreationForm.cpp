/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:19:29 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 22:05:17 by nazrinsha        ###   ########.fr       */
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
	if (this->checkExecutable(bureaucrat) == false)
		return ;

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
