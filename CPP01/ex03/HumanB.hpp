/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 01:39:18 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:03:03 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;

	public:
		HumanB(const std::string &humanName);
		~HumanB();
		void	attack()	const;
		void	setWeapon(Weapon &humanWeapon);
};

#endif