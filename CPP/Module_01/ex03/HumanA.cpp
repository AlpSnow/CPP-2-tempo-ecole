/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 07:21:25 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/25 07:21:25 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    :name(name), weapon(weapon)
{

}

// ============================================================================
// Explication de :
//
//  HumanA::HumanA(std::string name, Weapon& weapon)
//  {
//      this->name = name;
//      this->weapon = weapon; // ⛔️
//  }
//
// Pourquoi c’est incorrect, et la forme correcte.
// ============================================================================

// ---------------------------------------------------------------------------
// 1) Ordre réel de construction d’un objet
// ---------------------------------------------------------------------------
//
// En C++, les membres d’une classe sont INITIALISÉS AVANT d’entrer dans
// le corps du constructeur (les accolades { ... }).
//
// La zone juste après les deux-points du constructeur s’appelle la
// "liste d’initialisation" :
//
//     HumanA::HumanA(std::string name, Weapon& weapon)
//         : name(name), weapon(weapon)   // ✅ initialisation des membres
//     {
//          Ici, les membres existent déjà et sont valides.
//     }
//
// Le corps du constructeur ne sert plus qu’à exécuter du code APRÈS
// l’initialisation (logique, vérifications, etc.).

// ---------------------------------------------------------------------------
// 2) Spécificité des références membres (Weapon&)
// ---------------------------------------------------------------------------
//
// Une référence doit être LIÉE au moment de la construction.
// Elle ne peut pas :
//   - être laissée "non initialisée",
//   - être "réassignée" plus tard vers un autre objet.
//
// Donc une référence membre DOIT apparaître dans la liste d’initialisation.
// Essayer de "l’affecter" dans le corps (this->weapon = weapon) ne la
// relie pas : c’est trop tard, et ce n’est pas le bon mécanisme.

// ---------------------------------------------------------------------------
// 3) Initialisation vs. Affectation
// ---------------------------------------------------------------------------
//
// Différence cruciale :
//   - Initialiser un membre  : se fait dans la liste d’initialisation.
//   - Affecter un membre     : se fait dans le corps du constructeur.
//
// Dans le code incorrect :
//     this->weapon = weapon;  // ⛔️
//
// Si la référence était déjà liée, cette écriture n’aurait JAMAIS pour effet
// de "re-lier" la référence. Elle déclencherait une AFFECTATION de l’objet
// référencé (appel à Weapon::operator=()), ce qui copie le contenu d’un
// Weapon dans l’autre — ce n’est pas une re-liaison de la référence.
//
// Ici, comme la référence n’a pas été liée avant d’entrer dans { ... },
// le code est tout simplement invalide (erreur de compilation).

// ---------------------------------------------------------------------------
// 4) La bonne forme (à retenir)
// ---------------------------------------------------------------------------
//
// Lier la référence DANS la liste d’initialisation :
//
//     HumanA::HumanA(std::string name, Weapon& weapon)
//         : name(name), weapon(weapon)   // ✅ la référence est liée ici
//     {
//          Tous les membres sont déjà construits et valides.
//     }
//
// Avantages : pas de copie inutile, garantie que HumanA référence exactement
// l’arme passée (et que les modifications sur l’arme d’origine sont visibles).
//
// ============================================================================
// TL;DR
// - Les membres sont initialisés AVANT le corps du constructeur.
// - Une référence membre (Weapon&) DOIT être initialisée dans la liste d’init.
// - "this->weapon = weapon;" n’initialise pas une référence : ça effectuerait
//   au mieux une affectation du contenu (operator=) si la référence était déjà
//   liée, mais ne peut pas "re-lier" la référence.
// - Toujours écrire : ": name(name), weapon(weapon)".
// ============================================================================



// ============================================================================
// Qu’est-ce que operator= ?
// ============================================================================
//
// En C++, l’opérateur "=" est surchargeable.
// Quand tu écris :
//
//     Contact a;
//     Contact b;
//     b = a;   // <--- déclenche Contact::operator=(const Contact&)
//
// Le compilateur remplace automatiquement cette opération par un appel à
// ta fonction operator= si elle existe.
//
// Donc :
//
//     Contact& Contact::operator=(const Contact& other);
//
// est une fonction spéciale appelée implicitement dès que tu fais :
//
//     objet1 = objet2;
//
// ---------------------------------------------------------------------------
// La règle (Rule of Three)
// ---------------------------------------------------------------------------
//
// Si ta classe définit UN de ces trois éléments, elle doit probablement
// définir les DEUX autres :
//
//   1) Destructeur
//      -> Libère la ressource (delete, close, etc.)
//
//   2) Constructeur de copie
//      -> Crée une copie profonde (ressource indépendante)
//
//   3) Opérateur d’affectation (operator=)
//      -> Libère l’ancienne ressource et copie la nouvelle
//         (avec un test : if (this != &other))
//
// ---------------------------------------------------------------------------
// Quand l’appliquer ?
// ---------------------------------------------------------------------------
//
// - Si ta classe n’alloue rien dynamiquement → pas besoin.
// - Si tu utilises "new" → prépare à écrire les 3.
//
// Pourquoi ?
// Pour éviter un shallow copy (copie membre par membre par défaut),
// qui peut causer :
//    - double delete
//    - fuites mémoire
// ============================================================================




HumanA::~HumanA()
{

}

void    HumanA::attack(void) const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
