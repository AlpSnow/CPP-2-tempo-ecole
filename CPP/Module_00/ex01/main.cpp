/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 07:16:24 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/18 07:16:24 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "./include/PhoneBook.hpp"
#include "./include/Contact.hpp"

// Pour tester que les class sont bien indépendantes :
// c++ -Wall -Wextra -Werror -std=c++98 -c ./src/Contact.cpp

// Code : 
// 0 = run
// 1 = ctrl D 
// 2 = EXIT
// 3 = retour menu principal

int	ft_is_digits(const std::string& readline)
{
	long unsigned int	i;

	i = 0;
	while (i < readline.size())
	{
		if (readline[i] < '0' || readline[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	save_new_contact(PhoneBook& phonebook)
{
	Contact			contact;
	std::string		readline;
	int				i;
	const char*		info_contact[5] = {
        				"first name",
						"last name",
						"nickname",
						"phone number",
						"darkest secret"
					};

	i = 0;
	while (i < 5)
	{
		std::cout << "\033[36m" << "Enter your " << info_contact[i]
				  << "\033[0m"
			      << std::endl;
		
		std::cout << "> ";
		if (std::getline(std::cin, readline) == false)
		{
			std::cout << "\nInput closed (Ctrl-D). Return to menu, contact hasn't been saved." << std::endl;
			std::cin.clear();
			return(1);
		}
		if (readline.empty())
		{
			std::cout << "The field cannot be empty." << std::endl;
			continue ;
		}

		if (i == 0)
			contact.set_first_name(readline);
		else if (i == 1)
			contact.set_last_name(readline);
		else if (i == 2)
			contact.set_nickname(readline);
		else if (i == 3)
		{
			if (ft_is_digits(readline) == 0) 
			{
        		std::cout << "Phone number must contain digits only (0-9). Try again." << std::endl;
        		continue ;
			}
			contact.set_phone_number(readline);
		}
		else if (i == 4)
			contact.set_darkest_secret(readline);
		i++;
	}

	phonebook.add_contact(contact);
	std::cout << "Contact saved\n"
			  << "back to main menu\n"
			  << "Available commands: ADD, SEARCH, EXIT"
			  << std::endl;

	return (0);	
}

int	display_specific_contact(const PhoneBook& phonebook)
{
	const Contact	*contact;
	std::string		readline;
	int				index;

	while (true)
	{
        std::cout << "\033[36m"
                  << "Enter the index of a contact to display all of their information\n"
                  << "or type MENU to return to main menu."
                  << "\033[0m" 
				  << std::endl;
		
		std::cout << "> ";
		if (std::getline(std::cin, readline) == false)
		{
			std::cout << "\nInput closed (Ctrl-D). Return to menu." << std::endl;
			std::cin.clear();
			return(1);
		}

		if (readline == "MENU")
            return (3);

		if (readline.empty())
		{
			std::cout << "The field cannot be empty." << std::endl;
			continue ;
		}
		if (ft_is_digits(readline) == 0)
        {
            std::cout << "Please enter a valid number." << std::endl;
            continue;
        }
		index = std::atoi(readline.c_str());
        if (index <= 0 || index > phonebook.get_phonebook_size())
        {
            std::cout << "Index out of range. Please try again." << std::endl;
            continue;
        }

		contact = phonebook.get_entry(index - 1);
		std::cout << "first name     : " << contact->get_first_name()
				  << "\nlast name      : " << contact->get_last_name()
				  << "\nnickname       : " << contact->get_nickname()
				  << "\nphone number   : " << contact->get_phone_number()
				  << "\ndarkest secret : " << contact->get_darkest_secret()
				  << std::endl;
	}
	return (0);
}

void print_column(const std::string& str)
{
    if (str.size() > 10)
        std::cout << std::setw(10) << str.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << str;
}

void	display_all_contact(const PhoneBook& phonebook)
{
	const Contact	*contact;
	int				i;
	int				phonebook_size;

	i = 0;
	phonebook_size = phonebook.get_phonebook_size();
	if (phonebook_size == 0)
	{
		std::cout << "No contacts to display. Return to main menu.\n"
		          <<"Available commands: ADD, SEARCH, EXIT" 
				  << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << "\n";

	while (i < phonebook_size)
	{
		contact = phonebook.get_entry(i);
		std::cout << std::setw(10) << i + 1 << "|";
		print_column(contact->get_first_name());
		std::cout << "|";
		print_column(contact->get_last_name());
		std::cout << "|";
		print_column(contact->get_nickname());
		std::cout << std::endl;
		i++;
	}
	while (true)
	{
    	if (display_specific_contact(phonebook) == 3)
        	break;
	}
	std::cout << "back to main menu\n" 
			  << "Available commands: ADD, SEARCH, EXIT"
		      << std::endl;
}

int	phonebook_commands(PhoneBook& phonebook, const std::string& readline)
{
	if (readline == "EXIT")
	{
		std::cout << "Closing the program will result in permanent loss of contacts." << std::endl;
		return (2);
	}
	else if (readline == "ADD")
	{
		if (save_new_contact(phonebook) == 1)
			return (1);
	}
	else if (readline == "SEARCH")
	{
		display_all_contact(phonebook);
	}
	else 
	{
		std::cout << "command not found\n" 
				  << "Available commands: ADD, SEARCH, EXIT"
				  << std::endl;
	}
	return (0);
}

int	main()
{
	PhoneBook	phonebook;
	std::string	readline;
	int			status_command;

	std::cout << "\033[36m" << "Enter one of three commands :\n"
			  << "  ADD    - to add a new contact\n"
			  << "  SEARCH - to display saved contacts\n"
			  << "  EXIT   - to quit the program" << "\033[0m" 
			  << std::endl;
	while(true)
	{
		std::cout << "> ";
		if (std::getline(std::cin, readline) == false)
		{
			std::cout << "\nInput closed (Ctrl-D). All contacts will be lost." << std::endl;
			break ;
		}
		if (readline.empty())
			continue ;
		status_command = phonebook_commands(phonebook, readline);
		if (status_command == 2)
			break ;
		else 
			continue ;
	}
	return (0);
}