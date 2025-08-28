/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:53:34 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/24 01:53:34 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string string;
    std::string *stringPTR;
    

    string = "HI THIS IS BRAIN";
    stringPTR = &string;

    std::string& stringREF = string;

    std::cout << "The memory address of the string variable: " << &string << "\n"
              << "The memory address held by stringPTR: " << stringPTR << "\n"
              << "The memory address held by stringREF: " << &stringREF << "\n"
              << std::endl;

    std::cout << "The value of the string variable: " << string << "\n" 
              << "The value pointed to by stringPTR: " << *stringPTR << "\n"
              << "The value pointed to by stringREF: " << stringREF << "\n"
              << std::flush;

    return (0);
}

// Une référence doit être initialisée au moment de sa déclaration, 
// elle ne peut pas être "réassignée" plus tard comme un pointeur.
// Il faut une valeur dès le départ, parce qu’il n’y a aucun mécanisme prévu pour changer ce lien après coup.

// Il est donc impossible de faire ceci :
    
// std::string& stringREF;
// stringREF = string; // ❌ trop tard, il fallait lier à la déclaration