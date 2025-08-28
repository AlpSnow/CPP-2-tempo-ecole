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
    Zombie *zombie_heap_first;
    Zombie *zombie_heap_second;

    zombie_heap_first = newZombie("jean-marc");
    zombie_heap_second = newZombie("Foo");

    randomChump("julie");
    randomChump("Foo");
    randomChump("Nico");
    randomChump("Kiara");

    zombie_heap_first->announce();
    zombie_heap_second->announce();
    
    delete(zombie_heap_first);
    delete(zombie_heap_second);
    
    return (0);
}