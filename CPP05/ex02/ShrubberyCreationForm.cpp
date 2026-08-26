/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:16 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:16:47 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm ("ShrubberyCreationForm", 145, 137), _target ("unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm (other), _target (other._target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm ("ShrubberyCreationForm", 145, 137), _target (target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}

	return (*this);
}

void	ShrubberyCreationForm::_executeAction()	const
{
	std::ofstream	fTree ((_target + "_shrubbery").data());

	if (!fTree.is_open())
		throw std::runtime_error ("Cannot open file");

	fTree << "               ,@@@@@@@,\n";
	fTree << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	fTree << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	fTree << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	fTree << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	fTree << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	fTree << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	fTree << "       |o|        | |         | |\n";
	fTree << "       |.|        | |         | |\n";
	fTree << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

	fTree.close();
}
