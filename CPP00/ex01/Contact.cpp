/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:59:19 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 17:51:25 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	Contact::set(int i)
{
	if (!i && (!getLine(firstName) || emptyField(firstName)))
		return (false);
	else if (i == 1 && (!getLine(lastName) || emptyField(lastName)))
		return (false);
	else if (i == 2 && (!getLine(nickname) || emptyField(nickname)))
		return (false);
	else if (i == 3 && (!getLine(phoneNumber) || emptyField(phoneNumber)))
		return (false);
	else if (i == 4 && (!getLine(darkestSecret) || emptyField(darkestSecret)))
		return (false);

	return (true);
}

const std::string	&Contact::get(int i)	const
{
	if (!i)
		return (firstName);
	else if (i == 1)
		return (lastName);
	else if (i == 2)
		return (nickname);
	else if (i == 3)
		return (phoneNumber);

	return (darkestSecret);
}
