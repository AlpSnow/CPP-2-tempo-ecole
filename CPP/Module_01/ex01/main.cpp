/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:20:35 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/23 11:20:35 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{

    Zombie  *zombie_horde;
    int     nb_zombie_horde;
    int     i;

    nb_zombie_horde = 100;

    zombie_horde = zombieHorde(nb_zombie_horde, "roger");
    if (zombie_horde == NULL)
    {
        return (1);
    }

    i = 0;
    while (i < nb_zombie_horde)
    {
        zombie_horde[i].announce();
        i++;
    }

    delete[] zombie_horde;
    return (0);
}