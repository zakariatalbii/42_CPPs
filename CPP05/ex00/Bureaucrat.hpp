/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:10 by zatalbi           #+#    #+#             */
/*   Updated: 2026/04/26 19:46:55 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

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