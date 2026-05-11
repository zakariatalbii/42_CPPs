/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:10 by zatalbi           #+#    #+#             */
/*   Updated: 2026/05/06 19:16:19 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP

class AForm;

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;
		virtual void		_executeAction()	const = 0;
	public:
		AForm();
		AForm(const AForm &);
		AForm(const std::string &, int, int);
		virtual	~AForm();
		AForm				&operator=(const AForm &);
		const std::string	&getName()	const;
		bool				isSigned()	const;
		int					getSignGrade()	const;
		int					getExecuteGrade()	const;
		void				beSigned(const Bureaucrat &);
		void				execute(Bureaucrat const &)	const;
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

std::ostream	&operator<<(std::ostream &out, const AForm &b);

#endif