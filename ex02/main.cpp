/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:07:41 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 20:58:07 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	cout << CYAN "[Trying To initialise ShrubberyCreationForm and sign with an insufficient bureaucrat grade]" RESET << endl;
	cout << CYAN "[Trying To initialise ShrubberyCreationForm exec without signing the form]" RESET << endl << endl;
	{
		Form		*shrubbery_form = new ShrubberyCreationForm("Eu-lee's_house");
		Bureaucrat	*bureaucrat = new Bureaucrat("Some Asshole", 150);
		Bureaucrat	*bureaucrat2 = new Bureaucrat("Bigger Asshole", 5);

		cout << endl << *shrubbery_form << endl;
		cout << *bureaucrat << endl;

		cout << CYAN "executing with insufficient grade..." RESET << endl;
		shrubbery_form->execute(*bureaucrat);
		cout << endl;

		cout << *bureaucrat2 << endl;
		cout << CYAN "executing without signing first..." RESET << endl;
		shrubbery_form->execute(*bureaucrat2);

		//cout << endl;
		//cout << CYAN "signing ShrubberyCreationForm..." RESET << endl;
		//bureaucrat2->signForm(*shrubbery_form);
		//cout << CYAN "executing ShrubberyCreationForm..." RESET << endl;
		//shrubbery_form->execute(*bureaucrat2);

		cout << endl;
		delete bureaucrat2;
		delete bureaucrat;
		delete shrubbery_form;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise ShrubberyCreationForm with signing and sufficient bureaucrat grade]" RESET << endl << endl;
	{
		Form		*shrubbery_form = new ShrubberyCreationForm("Not_Eu-Lee's_house");
		Bureaucrat	*bureaucrat2 = new Bureaucrat("Bigger Asshole", 5);

		cout << endl << *shrubbery_form << endl;
		cout << *bureaucrat2 << endl;

		cout << endl;
		cout << CYAN "signing ShrubberyCreationForm..." RESET << endl;
		bureaucrat2->signForm(*shrubbery_form);
		cout << CYAN "executing ShrubberyCreationForm..." RESET << endl;
		shrubbery_form->execute(*bureaucrat2);

		cout << endl;
		delete bureaucrat2;
		delete shrubbery_form;
	}
}
