/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 07:21:21 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/25 07:21:21 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{

}

void Weapon::setType(const std::string& type)
{
    this->type = type;
}

const std::string& Weapon::getType(void) const
{
    return (this->type);
}
