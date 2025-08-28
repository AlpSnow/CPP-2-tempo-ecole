/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 06:55:30 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/19 06:55:30 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->phonebook_size_ = 0;
    this->next_index_add_contact_ = 0;
}

PhoneBook::~PhoneBook()
{

}

PhoneBook::PhoneBook(const PhoneBook& other)
{
    int i;

    i = 0;
    while (i < 8)
    {
        this->entries_[i] = other.entries_[i];
        i++;
    }
    this->phonebook_size_ = other.phonebook_size_;
    this->next_index_add_contact_ = other.next_index_add_contact_;
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
    int i;

    if (this != &other)
    {
        i = 0;
        while (i < 8)
        {
            this->entries_[i] = other.entries_[i];
            i++;
        }
    this->phonebook_size_ = other.phonebook_size_;
    this->next_index_add_contact_ = other.next_index_add_contact_;
    }
    return (*(this));
}

void PhoneBook::add_contact(const Contact& contact)
{
    this->entries_[next_index_add_contact_] = contact;

    this->next_index_add_contact_ = (this->next_index_add_contact_ + 1) % 8;
    if (this->phonebook_size_ < 8)
    {
        this->phonebook_size_++;
    }
}

int PhoneBook::get_phonebook_size() const
{
    return (this->phonebook_size_);
}

const Contact* PhoneBook::get_entry(int index) const
{
    if (index < 0 || index >= this->phonebook_size_)
        return (NULL);

    return (&this->entries_[index]);
}
