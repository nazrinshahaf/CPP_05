/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:53:47 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 18:53:06 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	cout << BLUE "Bureaucrat(name, grade);" RESET << endl << endl;
	cout << CYAN "[Trying To initialise Bureaucrat with an invalid grade of 0]" RESET << endl << endl;
	try
	{
		Bureaucrat	*bureaucrat = new Bureaucrat("Bellend no1", 0);

		cout << bureaucrat->getName() << endl;

		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise Bureaucrat with an invalid grade of 150]" RESET << endl << endl;
	try
	{
		Bureaucrat	*bureaucrat = new Bureaucrat("Bellend no2", 151);

		cout << bureaucrat->getName() << endl;

		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise Bureaucrat with an valid grade of 2 and incrementing grade till its invalid]" RESET << endl << endl;
	try
	{
		Bureaucrat	*bureaucrat = new Bureaucrat("Bellend no3", 2);

		cout << endl;
		cout << "Bureaucrat grade before incrementing: " << bureaucrat->getGrade() << endl;
		cout << BLUE "Incrementing grade..." RESET << endl;
		bureaucrat->incrementGrade();
		cout << "Bureaucrat grade after incrementing: " << bureaucrat->getGrade() << endl;
		cout << BLUE "Incrementing grade..." RESET << endl;
		bureaucrat->incrementGrade();
		cout << "Bureaucrat grade after incrementing: " << bureaucrat->getGrade() << endl;
		cout << BLUE "Incrementing grade..." RESET << endl;
		bureaucrat->incrementGrade();
		cout << "Bureaucrat grade after incrementing: " << bureaucrat->getGrade() << endl;
		cout << endl;

		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise Bureaucrat with an valid grade of 149 and decrementing grade till its invalid]" RESET << endl << endl;
	try
	{
		Bureaucrat	*bureaucrat = new Bureaucrat("Bellend no4", 149);

		cout << endl;
		cout << "Bureaucrat grade before incrementing: " << bureaucrat->getGrade() << endl;
		cout << BLUE "Decrementing grade..." RESET << endl;
		bureaucrat->decrementGrade();
		cout << "Bureaucrat grade after incrementing: " << bureaucrat->getGrade() << endl;
		cout << BLUE "Decrementing grade..." RESET << endl;
		bureaucrat->decrementGrade();
		cout << "Bureaucrat grade after incrementing: " << bureaucrat->getGrade() << endl;
		cout << BLUE "Decrementing grade..." RESET << endl;
		bureaucrat->decrementGrade();
		cout << "Bureaucrat grade after incrementing: " << bureaucrat->getGrade() << endl;
		cout << endl;

		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To Bureaucrat >> overload operator]" RESET << endl << endl;
	try
	{
		Bureaucrat	*bureaucrat = new Bureaucrat("Bellend no5", 149);

		cout << *bureaucrat << endl;

		delete bureaucrat;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl;
	}
	cout << endl;
}
