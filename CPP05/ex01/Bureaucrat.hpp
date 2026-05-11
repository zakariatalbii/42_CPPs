/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:10 by zatalbi           #+#    #+#             */
/*   Updated: 2026/04/27 20:40:59 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat;

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &);
		Bureaucrat(const std::string &, int);
		~Bureaucrat();
		Bureaucrat			&operator=(const Bureaucrat &);
		const std::string	&getName()	const;
		int					getGrade()	const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &)	const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what()	const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what()	const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif