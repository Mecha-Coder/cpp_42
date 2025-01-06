/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:14:15 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/06 13:12:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
    name = n;
}

void HumanB::setWeapon(Weapon &w)
{
    weapon = &w;
}

void HumanB::attack(void)
{
    std::cout
        << name
        << " attacks with their "
        << weapon->getType()
        << std::endl; 
}