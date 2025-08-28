/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:46:12 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/18 23:46:12 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact()
{

}

// Contact::Contact(const std::string& str)
// {
//     this->nickname_ = "surnom non autoriser";
//     this->first_name_ = str;
// }

Contact::~Contact()
{

}

Contact::Contact(const Contact& other)
{
    this->first_name_ = other.first_name_;
    this->last_name_ = other.last_name_;
    this->nickname_ = other.nickname_;
    this->phone_number_ = other.phone_number_;
    this->darkest_secret_ = other.darkest_secret_;
}

Contact& Contact::operator=(const Contact& other)
{
    if (this != &other)
    {
        this->first_name_ = other.first_name_;
        this->last_name_ = other.last_name_;
        this->nickname_ = other.nickname_;
        this->phone_number_ = other.phone_number_;
        this->darkest_secret_ = other.darkest_secret_;
    }
    return (*(this));
}



void Contact::set_first_name(const std::string& str)
{
    this->first_name_ = str;
}

void Contact::set_last_name(const std::string& str)
{
    this->last_name_ = str;
}

void Contact::set_nickname(const std::string& str)
{
    this->nickname_ = str;
}

void Contact::set_phone_number(const std::string& str)
{
    this->phone_number_ = str;
}

void Contact::set_darkest_secret(const std::string& str)
{
    this->darkest_secret_ = str;
}



const std::string&	Contact::get_first_name() const
{
    return (this->first_name_);
}

const std::string&	Contact::get_last_name() const
{
    return (this->last_name_);
}

const std::string&	Contact::get_nickname() const
{
    return (this->nickname_);
}

const std::string&	Contact::get_phone_number() const
{
    return (this->phone_number_);
}

const std::string&	Contact::get_darkest_secret() const
{
    return (this->darkest_secret_);
}






// ============================================================================
// Explication de :
//
// Contact& Contact::operator=(const Contact& other)
// {
//     if (this != &other)
// ============================================================================

// ---------------------------------------------------------------------------
// this est un pointeur
// ---------------------------------------------------------------------------
//
// En C++, chaque méthode non statique reçoit en secret un paramètre caché : this.
// Donc notre opérateur est en réalité (schématiquement) :
//
//     Contact* operator=(Contact* this, const Contact& other);
//
// Le compilateur cache ce paramètre.
// C’est pour ça qu’à l’intérieur d’une méthode on doit écrire this->first_name.
// this est un pointeur vers l’objet courant.
//
// ---------------------------------------------------------------------------
// Pourquoi const Contact& other ?
// ---------------------------------------------------------------------------
//
// Ici on passe other par référence constante pour éviter une copie
// et interdire toute modification.
//
// Une référence (Contact&) n’est pas la même chose qu’un pointeur :
// c’est un alias obligatoire (non nul, non réassignable).
//
// ---------------------------------------------------------------------------
// Référence vs pointeur
// ---------------------------------------------------------------------------
//
// La référence fonctionne un peu comme passer un pointeur
// (car c’est ce qu’elle fait en secret), mais nous on a directement
// la variable avec laquelle on travaille.
//
// Si on la compare avec un pointeur (ici this), comme this est de type
// pointeur vers la classe en cours, il nous faut l’adresse de la référence,
// d’où le & devant other.
// ============================================================================
