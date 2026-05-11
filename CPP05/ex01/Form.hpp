/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:10 by zatalbi           #+#    #+#             */
/*   Updated: 2026/04/27 20:58:50 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Form;

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form();
		Form(const Form &);
		Form(const std::string &, int, int);
		~Form();
		Form				&operator=(const Form &);
		const std::string	&getName()	const;
		bool				isSigned()	const;
		int					getSignGrade()	const;
		int					getExecuteGrade()	const;
		void				beSigned(const Bureaucrat &);
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

std::ostream	&operator<<(std::ostream &out, const Form &b);

#endif