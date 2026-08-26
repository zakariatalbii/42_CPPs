/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:16 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:12:21 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name ("unknown"), _grade (150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name (other._name), _grade (other._grade)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name (name)
{
	if (grade < 1)
		throw GradeTooHighException ();
	else if (grade > 150)
		throw GradeTooLowException ();

	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;

	return (*this);
}

const std::string	&Bureaucrat::getName()	const
{
	return (_name);
}

int	Bureaucrat::getGrade()	const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException ();

	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException ();

	_grade++;
}

void	Bureaucrat::signForm(Form &f)	const
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << '\n';
	}
	catch(std::exception &e)
	{
		std::cout << _name << " couldn't sign "
			<< f.getName() << " because " << e.what() << "\n";
	}
}

const char	*Bureaucrat::GradeTooHighException::what()	const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what()	const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b)
{
	return (out << b.getName() << ", bureaucrat grade " << b.getGrade() << '\n');
}
