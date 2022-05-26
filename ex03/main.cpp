/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:07:41 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/26 14:23:25 by nfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{

	cout << CYAN "[Trying To initialise an invalid form]" RESET << endl;
	cout << CYAN "==============================================================" RESET << endl;
	{
		Intern	*new_intern = new Intern();

		Form	*form;

		cout << endl;
		form = new_intern->makeForm("non-existant", "test target");
		if (form)
			cout << *form << endl;

		delete form;
		delete new_intern;
	}
	cout << CYAN "==============================================================" RESET << endl;
	cout << endl << endl << endl;

	cout << CYAN "[Trying To initialise a valid form and excuting]" RESET << endl;
	cout << CYAN "==============================================================" RESET << endl;
	{
		Intern		*new_intern = new Intern();
		Bureaucrat	*bureaucrat = new Bureaucrat("Some Asshole", 5);

		Form	*form;

		cout << endl;
		form = new_intern->makeForm("robotomy request", "Eu-lee");
		cout << endl;
		if (form)
		{
			cout << *form << endl;
			cout << *bureaucrat << endl;
			cout << MAGENTA "bureaucrat signing form..." << endl;
			bureaucrat->signForm(*form);
			cout << endl;
			cout << MAGENTA "bureaucrat executing form..." << endl;
			form->execute(*bureaucrat);
			cout << endl;
		}

		delete form;
		delete bureaucrat;
		delete new_intern;
	}
	cout << CYAN "==============================================================" RESET << endl;
}
