/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:16 by zatalbi           #+#    #+#             */
/*   Updated: 2026/05/06 20:14:26 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &)
{
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(const Intern &)
{
	return (*this);
}

AForm	*Intern::_makeShrubberyCreationForm(const std::string &formTarget)
{
	return (new ShrubberyCreationForm (formTarget));
}

AForm	*Intern::_makeRobotomyRequestForm(const std::string &formTarget)
{
	return (new RobotomyRequestForm (formTarget));
}

AForm	*Intern::_makePresidentialPardonForm(const std::string &formTarget)
{
	return (new PresidentialPardonForm (formTarget));
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	std::string	forms[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm	*(Intern::*make[])(const std::string &) =
	{
		&Intern::_makeShrubberyCreationForm,
		&Intern::_makeRobotomyRequestForm,
		&Intern::_makePresidentialPardonForm
	};

	for (size_t i (0); i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << "Intern creates " << formName << '\n';
			return ((this->*make[i])(formTarget));
		}
	}
	std::cout << formName << " form does not exist\n";
	return (NULL);
}
