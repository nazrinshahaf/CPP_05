/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:07:41 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/25 18:38:48 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Form.hpp"

#include "colours.h"

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	cout << BLUE "Form(form_name, grade_to_sign, grade_to_exec);" RESET << endl << endl;
	cout << CYAN "[Trying To initialise form with an invalid grade_to_sign of 0]" RESET << endl << endl;
	try
	{
		Form	*invalid_form = new Form("Invalid v1.00", 0, 0);

		cout << invalid_form->getName() << endl;

		delete invalid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise form with an invalid grade_to_sign of 151]" RESET << endl << endl;
	try
	{
		Form	*invalid_form = new Form("Invalid v1.01", 151, 0);

		cout << invalid_form->getName() << endl;

		delete invalid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise form with an invalid grade_to_exec of 0]" RESET << endl << endl;
	try
	{
		Form	*invalid_form = new Form("Invalid v1.02", 10, 0);

		cout << invalid_form->getName() << endl;

		delete invalid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To initialise form with an invalid grade_to_exec of 151]" RESET << endl << endl;
	try
	{
		Form	*invalid_form = new Form("Invalid v1.03", 10, 151);

		cout << invalid_form->getName() << endl;

		delete invalid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To sign a form with an insufficient bureaucrat grade of 11 and a grade_to_sign of 10]" RESET << endl << endl;
	try
	{
		Form			*valid_form = new Form("Invalid v1.04", 10, 10);
		Bureaucrat		*bureaucrat = new Bureaucrat("Bellend no4", 11);

		cout << "Bureaucrat grade: " << bureaucrat->getGrade() << endl;
		cout << "Form to sign grade: " << valid_form->getGradeToSign() << endl;

		try
		{
			valid_form->beSigned(*bureaucrat);
		}
		catch (Form::GradeTooLowException &exception)
		{
			cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
			<< "Can't sign form with requirement of: " << bureaucrat->getGrade()
			<< " in " BLUE "<" << exception.getWhichFunction() << "> " RESET << endl;
		}

		delete bureaucrat;
		delete valid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying To sign a form with a sufficient bureaucrat grade of 5 and a grade_to_sign of 10]" RESET << endl;
	cout << CYAN "[Operator overload >> for signed and unsigned form]" RESET << endl << endl;
	try
	{
		Form			*valid_form = new Form("Valid 1.05", 10, 10);
		Form			*valid_form2 = new Form("Valid 1.06", 10, 10);
		Bureaucrat		*bureaucrat = new Bureaucrat("Bellend no5", 5);

		cout << "Bureaucrat grade: " << bureaucrat->getGrade() << endl;
		cout << "Form to sign grade: " << valid_form->getGradeToSign() << endl;
		valid_form->beSigned(*bureaucrat);

		cout << endl << *valid_form << endl;
		cout << endl << *valid_form2 << endl;

		delete bureaucrat;
		delete valid_form2;
		delete valid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying to sign a form from bureaucrat]" RESET << endl;
	cout << CYAN "[Trying to sign an already signed form from bureaucrat]" RESET << endl;
	try
	{
		Form			*valid_form = new Form("Valid 1.07", 10, 10);
		Bureaucrat		*bureaucrat = new Bureaucrat("Bellend no6", 5);
		Bureaucrat		*bureaucrat2 = new Bureaucrat("Bellend no7", 5);

		cout << "Bureaucrat grade: " << bureaucrat->getGrade() << endl;
		cout << "Bureaucrat2 grade: " << bureaucrat2->getGrade() << endl;
		cout << "Form to sign grade: " << valid_form->getGradeToSign() << endl;

		bureaucrat->signForm(*valid_form);
		bureaucrat2->signForm(*valid_form);

		delete bureaucrat2;
		delete bureaucrat;
		delete valid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;

	cout << CYAN "[Trying to sign a form from bureaucrat with an insufficient grade]" RESET << endl << endl;
	try
	{
		Form			*valid_form = new Form("Valid 1.07", 10, 10);
		Bureaucrat		*bureaucrat = new Bureaucrat("Bellend no8", 15);

		cout << "Bureaucrat grade: " << bureaucrat->getGrade() << endl;
		cout << "Form to sign grade: " << valid_form->getGradeToSign() << endl;

		bureaucrat->signForm(*valid_form);

		delete bureaucrat;
		delete valid_form;
	}
	catch (Form::GradeTooHighException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		cout << "Exception caught: " RED "<" << exception.what() << ">." RESET << endl
		<< "Can't initialise " MAGENTA "<" << exception.getWhichGrade() << "> " RESET
		<< "in " BLUE "<" << exception.getWhichFunction() << "> " RESET
		<< "with a value of: " << exception.getInitGrade() << endl;
	}
	cout << endl;
}
