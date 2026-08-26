/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:16 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:14:17 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name ("unknown"), _isSigned (false),
		_signGrade (150), _executeGrade (150)
{
}

AForm::AForm(const AForm &other)
	: _name (other._name), _isSigned (false),
		_signGrade (other._signGrade), _executeGrade (other._executeGrade)
{
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name (name), _isSigned (false),
		_signGrade (signGrade), _executeGrade (executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException ();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException ();
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;

	return (*this);
}

const std::string	&AForm::getName()	const
{
	return (_name);
}

bool	AForm::isSigned()	const
{
	return (_isSigned);
}

int	AForm::getSignGrade()	const
{
	return (_signGrade);
}

int	AForm::getExecuteGrade()	const
{
	return (_executeGrade);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException ();
}

void	AForm::execute(Bureaucrat const &executor)	const
{
	if (!_isSigned)
		throw std::logic_error ("Form is not signed");
	else if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException ();

	_executeAction();
}

const char	*AForm::GradeTooHighException::what()	const throw()
{
	return ("AForm::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what()	const throw()
{
	return ("AForm::GradeTooLowException");
}

std::ostream	&operator<<(std::ostream &out, const AForm &f)
{
	return (out << "formName: " << f.getName()
		<< ", isSigned: " << std::boolalpha << f.isSigned() << std::noboolalpha
		<< ", signGrade: " << f.getSignGrade()
		<< ", executeGrade: " << f.getExecuteGrade() << '\n');
}
