/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:15:17 by zatalbi           #+#    #+#             */
/*   Updated: 2026/05/06 10:54:01 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int	main(void)
{
	try
	{
		ShrubberyCreationForm	f ("Shrubbery");
		Bureaucrat				b ("b", 137);

		b.executeForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		ShrubberyCreationForm	f ("Shrubbery");
		Bureaucrat				b ("b", 137);

		f.beSigned(b);
		b.executeForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		RobotomyRequestForm	f ("Robotomy");
		Bureaucrat			b ("b", 69);

		f.beSigned(b);
		b.executeForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	srand(time(NULL));
	try
	{
		RobotomyRequestForm	f ("Robotomy");
		Bureaucrat			b ("b", 42);

		f.beSigned(b);
		b.executeForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		PresidentialPardonForm	f ("Presidential");
		Bureaucrat				b ("b", 1);

		f.beSigned(b);
		b.executeForm(f);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
