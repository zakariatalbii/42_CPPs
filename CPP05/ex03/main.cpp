/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:15:17 by zatalbi           #+#    #+#             */
/*   Updated: 2026/05/06 20:12:19 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	AForm	*shrubbery;
	AForm	*robotomy;
	AForm	*pardon;
	AForm	*invalid;

	shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (shrubbery)
		std::cout << *shrubbery;

	robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	if (robotomy)
		std::cout << *robotomy;

	pardon = someRandomIntern.makeForm("presidential pardon", "Zaphod");
	if (pardon)
		std::cout << *pardon;

	invalid = someRandomIntern.makeForm("invalid", "target");
	if (invalid)
		std::cout << *invalid;

	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete invalid;

	return (0);
}
