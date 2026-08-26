/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 01:39:18 by zatalbi           #+#    #+#             */
/*   Updated: 2026/08/26 18:02:47 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
	std::string	name;
	Weapon		&weapon;

	public:
		HumanA(const std::string &humanName, Weapon &humanWeapon);
		~HumanA();
		void	attack()	const;
};

#endif