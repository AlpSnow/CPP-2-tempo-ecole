/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:44:05 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/24 00:44:05 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *zombie_horde;
    int     i;

    if (N <= 0)
    {
        std::cout << "Your horde must contain at least one zombie" << std::endl;
        return (NULL);
    }
    else if (N > 100000)
    {
        std::cout << "Humans are infusifansant to create your horde" << std::endl;
        return (NULL);
    }

    zombie_horde = new Zombie[N];
    i = 0;

    while (i < N)
    {   
        zombie_horde[i].set_name(name);
        i++;
    }

    return (zombie_horde);
}