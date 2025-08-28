/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 07:16:50 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/18 07:16:50 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact      entries_[8];
        int     phonebook_size_;
        int     next_index_add_contact_;


    public:
        PhoneBook();
        ~PhoneBook();
        PhoneBook(const PhoneBook& other);
    	PhoneBook& operator=(const PhoneBook& other);

        void add_contact(const Contact& contact);

        int get_phonebook_size() const;
        const Contact* get_entry(int index) const;
};

#endif