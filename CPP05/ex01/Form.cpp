/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:16 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:13:15 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name ("unknown"), _isSigned (false),
		_signGrade (150), _executeGrade (150)
{
}

Form::Form(const Form &other)
	: _name (other._name), _isSigned (false),
		_signGrade (other._signGrade), _executeGrade (other._executeGrade)
{
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: _name (name), _isSigned (false),
		_signGrade (signGrade), _executeGrade (executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException ();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException ();
}

Form::~Form()
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;

	return (*this);
}

const std::string	&Form::getName()	const
{
	return (_name);
}

bool	Form::isSigned()	const
{
	return (_isSigned);
}

int	Form::getSignGrade()	const
{
	return (_signGrade);
}

int	Form::getExecuteGrade()	const
{
	return (_executeGrade);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException ();
}

const char	*Form::GradeTooHighException::what()	const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*Form::GradeTooLowException::what()	const throw()
{
	return ("Form::GradeTooLowException");
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	return (out << "formName: " << f.getName()
		<< ", isSigned: " << std::boolalpha << f.isSigned() << std::noboolalpha
		<< ", signGrade: " << f.getSignGrade()
		<< ", executeGrade: " << f.getExecuteGrade() << '\n');
}
