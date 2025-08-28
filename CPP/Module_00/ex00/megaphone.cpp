/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 08:50:14 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 08:50:14 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// En C++ on n’est plus contraint par la norme de 42 pour les commentaires, 
// donc on peut utiliser des commentaires classiques, et les écrire en français si on le souhaite.

// std::cout → sortie standard (fd 1)
// std::cerr → sortie d’erreur (fd 2)
// std::cin → entrée standard (fd 0)


// Ici, std (abréviation de standard) regroupe toute la bibliothèque standard C++.
// Ça évite les conflits de noms.

// Par exemple :

// std::cout = l’objet “sortie standard” défini dans namespace std
// std::toupper = fonction de transformation en majuscule définie dans namespace std
// std::string = classe chaîne de caractères définie dans namespace std

                    // C               C++
// Sortie standard	stdout (FILE*)	std::cout (std::ostream)
// Entrée standard	stdin (FILE*)	std::cin (std::istream)
// Sortie erreur	stderr (FILE*)	std::cerr (std::ostream)

// Qu’est-ce qu’un namespace ?
// C’est un contenant logique pour regrouper des fonctions, classes, variables…

// Le namespace std est toujours “déclaré” par la bibliothèque standard du C++ dès le départ.
// Mais il ne contient rien d’utile pour toi tant que tu n’as pas inclus les bons headers.


// Le << écrit dans le flux std::cout
// Mais le flux n’est pas vidé à chaque fois 
// C’est là qu’intervient la notion de buffer.

// Comment ça marche :

// std::cout a un tampon (buffer) en mémoire.
// Chaque << écrit dans ce tampon.
// Le tampon est vidé (flush) seulement dans certains cas :

// - Quand il est plein
// - Quand tu mets un std::endl (flush forcé)
// - Quand tu mets explicitement std::flush
// - Quand ton programme se termine
// - Quand la sortie est line-buffered et qu’un \n est envoyé vers un terminal (mais pas toujours pour un fichier)

// Il est possible de faire : 
// std::cout << "Salut " << "Hello ";

// En C++, on peut assembler dynamiquement avec << sans te soucier du format.


int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			c = static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}


// Pour ecrire lettre par lettre donc sans tampon : 

// std::cout << c << std::flush;

// Sans tampon → chaque std::cout << c; ferait un appel système write() vers fd 1 → très lent (1 million d’appels)
// Avec tampon → std::cout stocke les caractères dans une zone mémoire, et quand le tampon est plein, il envoie tout d’un coup avec un seul appel write() → beaucoup plus rapide.
