/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:00:10 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 19:23:07 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm	*_makeShrubberyCreationForm(const std::string &);
		AForm	*_makeRobotomyRequestForm(const std::string &);
		AForm	*_makePresidentialPardonForm(const std::string &);

	public:
		Intern();
		Intern(const Intern &);
		~Intern();
		Intern	&operator=(const Intern &);
		AForm	*makeForm(const std::string &, const std::string &);
};

#endif