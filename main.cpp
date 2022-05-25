/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazrinshahaf <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:53:47 by nazrinsha         #+#    #+#             */
/*   Updated: 2022/05/24 14:26:07 by nazrinsha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

using	std::string;
using	std::cout;
using	std::endl;

int	main()
{
	Bureaucrat	*invalidbur = new Bureaucrat("invalidbur", -1);
	Bureaucrat	*invalidbur2 = new Bureaucrat("invalidbur2", 160);

	delete invalidbur;
	delete invalidbur2;

	cout << endl << endl;

	Bureaucrat	*bur = new Bureaucrat("bur", 1);
	Bureaucrat	*bur2 = new Bureaucrat("bur2", 150);

	cout << endl << endl;

	cout << "bur grade before : " << bur->getGrade() << endl;
	bur->incrementGrade();
	cout << "bur grade after: " << bur->getGrade() << endl;

	cout << endl << endl;

	cout << "bur2 grade before : " << bur2->getGrade() << endl;
	bur2->decrementGrade();
	cout << "bur2 grade after : " << bur2->getGrade() << endl;
	
	cout << endl << endl;

	cout << *bur << endl;
	cout << *bur2 << endl;

	delete bur;
	delete bur2;
	return 0;
}
