/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:20:45 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/23 11:20:45 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private :
        std::string name;

    public :
        Zombie();
        ~Zombie();

        void set_name(const std::string& str);
        void announce( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif