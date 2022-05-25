/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:16:57 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 22:09:54 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>

#include "RobotomyRequestForm.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

RobotomyRequestForm::RobotomyRequestForm() : Form("_robotomyCretionForm", 72, 45)
{
	cout << GREEN "RobotomyRequestForm Default Constructor called" RESET << endl;
	this->_target = "";
}

RobotomyRequestForm::RobotomyRequestForm(string const target) : Form(target + "_robotomyCretionForm", 72, 45)
{
	cout << GREEN "RobotomyRequestForm Assignment Constructor called" RESET << endl;
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << RED "RobotomyRequestForm Destructor called" RESET << endl;
}

void			RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	srand(time(0));
	int	random_number = rand() % 100;

	if (this->checkExecutable(bureaucrat) == false)
		return ;

	cout << RED "* BRR KRRR BRR BRRRRRRRRRRRRBRRRRRRRRRRRBRRRRRRRRR *" RESET << endl;
	cout << MAGENTA "<" << bureaucrat.getName() << "> " RESET "is being a dumbass and making noise." << endl;

	if (random_number % 2 == 0)
		cout << MAGENTA "<" << this->_target << "> " RESET "has been successfully "
			"(r?)lobotomized." << endl;
	else
		cout << MAGENTA "<" << this->_target << "> " RESET "has been unsuccessfully "
			"(r?)lobotomized. You will not be missed." << endl;
}

const string	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void			RobotomyRequestForm::setTarget(string const target)
{
	this->_target = target;
}
