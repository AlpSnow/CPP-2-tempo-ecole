/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 07:16:48 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/18 07:16:48 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	// Attribut :

	private :
		std::string	first_name_;
		std::string	last_name_;
		std::string nickname_;
		std::string	phone_number_;
		std::string	darkest_secret_;

	// public : (aucun ici)


	// Methodes :

	// private : (aucun ici)

	public : 

		// Orthodox Canonical Form (OCF)
    	Contact();                                // constructeur par défaut
    	~Contact();                               // destructeur
    	Contact(const Contact& other);            // constructeur de copie
    	Contact& operator=(const Contact& other); // opérateur d'affectation


		void set_first_name(const std::string& str);
		void set_last_name(const std::string& str);
		void set_nickname(const std::string& str);
		void set_phone_number(const std::string& str);
		void set_darkest_secret(const std::string& str);

		const std::string&	get_first_name() const;
		const std::string&	get_last_name() const;
		const std::string&	get_nickname() const;
		const std::string&	get_phone_number() const;
		const std::string&	get_darkest_secret() const;
};

#endif





// ============================================================================
// Référent ou référence en C++
// ============================================================================
//
// C’est un alias, un autre nom pour une variable déjà existante.
//
// Contrairement à un pointeur en C :
//   - Pas besoin de * ou -> pour accéder.
//   - Pas de NULL → une référence doit toujours être reliée à quelque chose.
//   - Pas de réaffectation → une fois qu’une référence est liée à une variable,
//     elle reste liée à celle-ci pour toujours.
//
// -----------------------------------------------------------------------------
// Exemples simples
// -----------------------------------------------------------------------------
/*
    int a = 42;
    int& ref = a;        // ref est un alias de a
    ref = 10;            // modifie a (a == 10)

    const int& cref = a; // cref est une référence constante (lecture seule)
    cref = 20;           // ❌ interdit
*/

// ma_super_variable&       = modifiable, comme si on avait passé un pointeur
//                            mais sans la lourdeur.
//
// const_ma_super_variable& = non modifiable,
//                            comme si on avait passer directement la variable 
// 							  car elle serait copier uniquement au sein de la fonction 
//                            (sauf qu'il serait possible de la modifier au sein de la fonction)
// 							  ou simplement équivalent à passer une variable en const
//
// ============================================================================
// Référence = pointeur caché
// ============================================================================
//
// Une référence est en fait un pointeur caché → même puissance, même performance,
// mais avec la sécurité et la simplicité en plus.
//
//
// Techniquement, une référence est traduite par le compilateur en :
//   "pointeur constant, toujours non nul".
//
// On n’a plus besoin d’écrire * ou ->. On l’utilise comme une variable normale.
//
// -----------------------------------------------------------------------------
// Performance
// -----------------------------------------------------------------------------
//
// Passer un Contact* → coût = une adresse (8 octets sur machine 64 bits).
// Passer un Contact& → coût = une adresse (8 octets aussi).
//
// -> Zéro différence de performance.
// + Une référence a des règles plus strictes → le compilateur peut optimiser mieux.
//
// -----------------------------------------------------------------------------
// Mais alors, pourquoi préférer une référence ?
// -----------------------------------------------------------------------------
//
// ✅ Lisibilité (appréciée dans le monde pro) :
//
//   void f(Contact* c);   // pointeur   → c->get_name();
//   void f(Contact& c);   // référence → c.get_name();
//
// ✅ Sécurité :
//   - Pointeur  → peut être NULL, ou pointer vers n’importe où.
//   - Référence → garantie toujours valide, jamais NULL.
//
// ✅ Intentions claires :
//   - Pointeur  → l’objet peut être absent (NULL) ou optionnel.
//   - Référence → l’objet est obligatoire, pas besoin de if(ptr).
//
//
// ============================================================================
// Quand utiliser quoi ?
// ============================================================================
//
// 🔹 Référence (&)
// ----------------
// 	par défaut, on préfère toujours une référence, 
// 	sauf quand il faut gérer des cas spéciaux (nullptr, tableaux, new/delete, redirection)”
//
// - Quand on veut éviter une copie mais que l’objet est obligatoire.
//   void print_contact(const Contact& c);
// - Rendre API lisible (pas de * ou ->).
// - Pour les getters → const & (évite la copie, interdit la modif).
// - Pour les setters → paramètre en const & (évite la copie inutile).
// - Pour le passage de gros objets (std::string, classes, etc.) sans overhead.
// - Pour le retour d’un objet interne (éviter de recopier une string, vector, …).
//
// 👉 Référence = Notre objet est là, valide, et on veut juste y accéder efficacement.
//
//
// 🔹 Pointeur (*)
// ---------------
// - Quand l’objet peut être optionnel / absent (nullptr).
// - Quand on doit gérer la mémoire manuellement (new/delete).
// - Quand on manipule des tableaux bruts hérités du C.
// - Quand on veut que notre pointeur change de cible (pouvoir le réassigner).
//
//   int a, b;
//   int* p = &a;
//   p = &b; // ✅ possible
//
//   int& r = a;
//   r = b;  // ❌ impossible, ça modifie `a` au lieu de rediriger la ref.
//
// 👉 Pointeur = plus bas niveau, plus flexible, mais plus dangereux.
//
// -----------------------------------------------------------------------------
// Résumé ultra-court
// -----------------------------------------------------------------------------
//
// Référence (&) → objet obligatoire, lisible, sûr, sans copie.
// Pointeur (*) → objet optionnel, mémoire manuelle, tableaux bruts, redirection.
//
// ============================================================================
// Exemple avec méthode const
// ============================================================================
//
// const std::string& get_darkest_secret() const;
//
// - const std::string& → type de retour : une référence constante sur la string
//                        interne (pas de copie, lecture seule).
//
// - get_darkest_secret() → le nom de la fonction.
//
// - const final → garantit que la méthode NE MODIFIE PAS l’objet (this).
//









// ============================================================================
// Forme canonique d'une classe (OCF - Orthodox Canonical Form)
// ============================================================================
//
// 1) Contact() — constructeur par défaut
//
// Ce qu’il fait : crée un objet sans argument. À toi d’initialiser tes attributs
// (souvent vides) dans l’implémentation.
//
// Et si je veux demander un nickname dès le début ?
// → Tu fais un autre constructeur (surcharge) :
//
//     Contact(const std::string& nick);
//
// Si tu appelles Contact() (sans arg) alors que seul
// Contact(const std::string&) existe, ça ne compile pas (pas de constructeur par défaut).
//
// Si on veut que le nickname soit optionnel, on peut :
//   - garder deux constructeurs (un par défaut + un avec nick), ou
//   - donner une valeur par défaut
//
// -----------------------------------------------------------------------------
// ~Contact() — destructeur
//
// - Si on a fait new, on doit faire delete : (donc créé un objet avec un pointeur).
// - Le destructeur est automatique pour les objets non alloués avec new
//   (objets “sur la pile”).
//
// -----------------------------------------------------------------------------
// Contact(const Contact& other) — constructeur de copie
//
// - C’est une nouvelle instance, un nouvel objet avec les mêmes valeurs qu’un autre.
// - Il copie la valeur de ses attributs au moment de sa création.
// - Crée un nouvel objet en copiant l’état de other.
//
// -----------------------------------------------------------------------------
// Contact& operator=(const Contact& other) — opérateur d’affectation
//
// - Ne change pas l’adresse de l’objet (ce n’est pas “faire pointer sur un autre”).
// - Il remplace le contenu de l’objet x par le contenu de other y.
//
// -----------------------------------------------------------------------------
// Schéma récap express
// -----------------------------------------------------------------------------
//
// - Constructeur par défaut : crée un objet vide (à toi d’initialiser).
// - Constructeur paramétré : crée un objet en initialisant avec des valeurs.
// - Destructeur : appelé auto (pile) ou via delete (tas).
// - Constructeur de copie : nouvel objet ← copie d’un autre.
// - Opérateur = : même objet ← remplace son contenu par celui d’un autre
//                 (l’adresse ne change pas).
//
