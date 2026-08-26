/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 01:39:18 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:03:40 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(const std::string &weaponType);
		~Weapon();
		const std::string	&getType()	const;
		void				setType(const std::string &weaponType);
};

#endif