/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 07:34:10 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/22 07:34:10 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(void)
{

}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts; // donne un index au moment de la construction, l'index commence a 0
    this->_amount = initial_deposit;   // initialise le solde du compte de l'utilisateur (objet) avec la valeur passée
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}


int	Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}


void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}


void	Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;

    this->_amount += deposit;
    this->_nbDeposits += 1;

    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}


bool	Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";

    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;

    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;

    std::cout << withdrawal
          << ";amount:" << this->_amount
          << ";nb_withdrawals:" << this->_nbWithdrawals
          << std::endl;

    return (true);
}

int		Account::checkAmount(void) const
{
    return (this->_amount);
}

void	Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}



void	Account::_displayTimestamp(void)
{
    std::time_t now;
    std::tm     *local_time;
    char        str[32];

    now = std::time(NULL);
    local_time = std::localtime(&now);

    if (local_time != NULL && std::strftime(str, sizeof(str), "%Y%m%d_%H%M%S", local_time) > 0)
        std::cout << "[" << str << "] ";
    else
        std::cout << "[00000000_000000] ";
}


// strftime ajoute automatiquement un caractère nul '\0'

// -----------------------------------------------------------------------------
// Retour de std::localtime()
// -----------------------------------------------------------------------------
// Un pointeur vers une structure tm, qui contient l'heure décomposée :
//
// struct tm {
//     int tm_sec;    // secondes (0-60)
//     int tm_min;    // minutes (0-59)
//     int tm_hour;   // heures (0-23)
//     int tm_mday;   // jour du mois (1-31)
//     int tm_mon;    // mois (0-11)
//     int tm_year;   // années depuis 1900
//     ...
// };
//
// Si la conversion échoue, la fonction renvoie NULL.

// -----------------------------------------------------------------------------
// std::time_t et son rôle
// -----------------------------------------------------------------------------
// - std::time_t est un type représentant le nombre de secondes écoulées depuis 
//   le 1er janvier 1970 (UTC).
// - On crée une variable now pour stocker ce timestamp brut (valeur entière).

// Exemple : 
// std::time_t now = std::time(NULL); // récupère l'heure actuelle en secondes

// -----------------------------------------------------------------------------
// Préparer un buffer pour strftime()
// -----------------------------------------------------------------------------
// - On crée un tableau de char (par exemple 32 cases) : char str[32];
// - Pourquoi ? Parce que strftime écrit directement dans ce tableau.
// - On ne peut pas utiliser std::string avec strftime, qui attend un buffer C.

// -----------------------------------------------------------------------------
// Conversion en heure locale
// -----------------------------------------------------------------------------
// - std::localtime(&now) convertit le timestamp brut en heure locale 
//   (découpée en année, mois, jour, heure, minute, seconde).
// - Retourne un pointeur vers une structure tm si OK, NULL si échec.

// -----------------------------------------------------------------------------
// Formattage avec strftime()
// -----------------------------------------------------------------------------
// - strftime(str, sizeof(str), "%Y%m%d_%H%M%S", local_time);
// - Remplit str avec une date formatée : "YYYYMMDD_HHMMSS"
//   - %Y : année complète
//   - %m : mois (01-12)
//   - %d : jour (01-31)
//   - %H : heure (00-23)
//   - %M : minute (00-59)
//   - %S : seconde (00-59)
// - Retourne le nombre de caractères écrits (0 si échec).

// -----------------------------------------------------------------------------
// Vérification et affichage
// -----------------------------------------------------------------------------
// if (local_time && std::strftime(str, sizeof(str), "%Y%m%d_%H%M%S", local_time))
//     std::cout << "[" << str << "] ";  // Affiche la date entre crochets
// else
//     std::cout << "[00000000_000000] "; // Valeur par défaut si échec

















// -----------------------------------------------------------------------------
// Attribut static dans une class : 
// (membre statique de classe)
// -----------------------------------------------------------------------------

// class Account {
//     static int _nbAccounts;   // partagé par TOUS les objets Account
//     int _amount;              // propre à CHAQUE objet
// };

// Il n’existe qu’UNE seule copie par classe, partagée par toutes les instances.
// Par contre, _amount existe dans chaque objet séparément.

// Quand on déclare static dans une classe, ça veut dire :
// Il n’y a qu’UNE seule copie de cette variable pour TOUTE la classe,
// partagée par tous les objets créés.

// -----------------------------------------------------------------------------
// Les fonctions statiques dans une classe suivent la même logique que
// les variables statiques : elles appartiennent à la classe, pas aux objets.
// -----------------------------------------------------------------------------

// Pourquoi on en a besoin ?

// Une méthode statique est utile quand :
// - Elle agit sur des données statiques de la classe (par ex. _nbAccounts).
// - Elle ne dépend d’aucune instance (pas besoin de this).

// Il est donc possible de faire ceci (donc pas besoin de créer un objet) :
// Account::ma_super_fonction(123);

// -----------------------------------------------------------------------------
// Quand utiliser une méthode statique ?
// -----------------------------------------------------------------------------
// Cas 1 : On veut exécuter une fonction liée à la classe sans avoir besoin d'un objet.
// Cas 2 : La fonction travaille uniquement avec des attributs statiques (partagés par tous les objets).
// Cas 3 : La logique n'a pas de sens “par objet” (ex. afficher un état global, calculer quelque chose indépendant d'une instance).

// -----------------------------------------------------------------------------
// Important :
// -----------------------------------------------------------------------------
// - Une méthode statique ne peut pas accéder à this (puisqu’il n’y a pas d’objet).
// - Elle peut accéder aux variables statiques de la classe directement :

// Exemple :
// void Account::displayAccountsInfos()
// {
//     std::cout << _nbAccounts; // OK
// }
