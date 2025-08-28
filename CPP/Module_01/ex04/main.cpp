/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:37:21 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/26 03:37:21 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replace_line(const std::string& line, const std::string& str1, const std::string& str2)
{
    std::string line_replaced;
    std::size_t position;
    std::size_t found;
    
    position = 0;

    while (true) 
    {
        found = line.find(str1, position);

        if (found == std::string::npos)
        {
            line_replaced.append(line, position, std::string::npos);
            break ;
        }

        line_replaced.append(line, position, found - position);
        line_replaced += str2;
        position = found + str1.size();
    }
    return (line_replaced);
}

static void read_replace_stock(std::ifstream& infile, std::ofstream& outfile, char *argv[])
{
    std::string line;
    std::string line_replaced;
    std::string str1;
    std::string str2;
    bool is_first_line;

    str1 = argv[2];
    str2 = argv[3];
    is_first_line = true;
    while (std::getline(infile, line))
    {
        line_replaced = replace_line(line, str1, str2);
        if (is_first_line == false)
        {
            outfile << '\n';
        }
        else
        {
            is_first_line = false;
        }
        outfile << line_replaced;
    }
    outfile << "\n";
}

int main(int argc, char *argv[])
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     outname;

    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <search_string> <replacement_string>" << std::endl;
        return (1);
    }

    if (argv[2][0] == '\0')
    {
        std::cerr << "Error: <search_string> must not be empty" << std::endl;
        return (1);
    }

    infile.open(argv[1]);
    if (infile.is_open() == false)
    {
        std::cerr << "Error: Cannot open input file " << std::endl;
        return (1);
    }

    // on construit une string avec son construct et on concatenne
    outname = std::string(argv[1]) + ".replace";
    // l'un des attributs de l'objet string est un const char *str avec la meme valeur qu'en c
    outfile.open(outname.c_str());
    if (outfile.is_open() == false)
    {
        std::cerr << "Error: Cannot create output file" << std::endl;
        return (1);
    }

    read_replace_stock(infile, outfile, argv);

    return (0);
}


// ============================================================================
// Explication de :
//
//     std::ifstream infile;
//     std::ofstream outfile;
//
//     infile.open(argv[1]);
//     if (infile.is_open() == false)
// ============================================================================

// ---------------------------------------------------------------------------
// 1) Déclaration des flux :
// ---------------------------------------------------------------------------
//
// ✅ std::ifstream infile;
//
// - ifstream = input file stream (flux d'entrée depuis un fichier).
// - Il provient de <fstream> et sert à LIRE des données à partir d’un fichier.
// - infile est un OBJET (pas un pointeur), donc :
//     • Il est construit ici (aucun fichier ouvert pour le moment).
//     • On pourra plus tard appeler :
//           infile.open("mon_fichier.txt");
//       pour lui associer un fichier.
//
// On peut aussi faire tout en une seule étape :
//     std::ifstream infile("mon_fichier.txt");
//
// Mais la version en deux temps (déclarer d'abord, ouvrir ensuite)
// est souvent utilisée pour plus de clarté.
//
// ---------------------------------------------------------------------------
// ✅ std::ofstream outfile;
//
// - ofstream = output file stream (flux de sortie vers un fichier).
// - Sert à ÉCRIRE dans un fichier.
// - Comme pour ifstream, outfile est créé sans fichier ouvert.
//   On l’associe ensuite avec :
//       outfile.open("mon_fichier.txt");
//
// Alternative en une ligne :
//       std::ofstream outfile("mon_fichier.txt");
//
// ---------------------------------------------------------------------------
// 2) Ouverture réelle du fichier :
// ---------------------------------------------------------------------------
//
//     infile.open(argv[1]);
//
// - infile est un objet de type std::ifstream.
// - La méthode .open(const char* filename) ouvre le fichier dont le chemin
//   est passé en paramètre.
// - Ici, argv[1] est un char* (deuxième argument de la ligne de commande,
//   donc le nom du fichier à lire).
// - Par défaut, std::ifstream ouvre en mode lecture (std::ios::in).
//
// 📌 Après cet appel :
//     • Si le fichier existe ET que les droits de lecture sont suffisants,
//       le flux infile devient VALIDE.
//     • Sinon, il passe dans un état d’erreur (failbit) et
//       is_open() retournera false.
//
// ---------------------------------------------------------------------------
// TL;DR
// - std::ifstream et std::ofstream sont des objets C++ pour lire/écrire
//   des fichiers.
// - Déclaration simple : crée un flux sans l’ouvrir.
// - .open(path) : associe le flux à un fichier.
// - .is_open() : vérifie si l’ouverture a réussi.
// - Fermeture automatique grâce à RAII quand l’objet sort de portée.
// ============================================================================















// ============================================================================
// Mémo rapide : static_cast vs Constructeur
// ============================================================================
//
// Quand utiliser static_cast ?
// ----------------------------
// - Objectif : convertir un type en un autre type *compatible*.
// - Sans appel à un constructeur “arbitraire” (conversion connue du compilateur).
// - Idéal pour :
//     • Conversions numériques (int -> double, double -> int, ...)
//     • Pointeurs dans une hiérarchie (Derived* -> Base*)
//     • void* -> T* (et l’inverse si sûr)
// - Exemples :
//     int    i = 42;
//     double d = static_cast<double>(i);        // OK (numérique)
//     void*  p = &i;
//     int*   pi = static_cast<int*>(p);         // OK (pointeur)
//     Base*  b = static_cast<Base*>(derived);   // OK (hiérarchie connue)
//
// ⚠️ À éviter :
// - Conversions nécessitant une construction d’objet (ex: char* -> std::string)
//   static_cast<std::string>(argv[1]); // ❌ Non : ce n’est pas une simple conversion
//
//
// Quand utiliser un constructeur ?
// --------------------------------
// - Objectif : *créer un objet* à partir d’une autre valeur.
// - À utiliser quand :
//     • Tu veux instancier un objet “complexe” (std::string, std::ofstream, …)
//     • Tu as besoin d’une vraie initialisation (logique du constructeur).
// - Exemples :
//     std::string s(argv[1]);             // OK : std::string(const char*)
//     std::ofstream file("data.txt");     // OK : ouvre le fichier à la construction
//
// Notes pratiques :
// - En C++98, beaucoup d’API prennent const char* → passer .c_str() depuis std::string
//     std::string name = "out.txt";
//     file.open(name.c_str());            // OK en C++98
//
//
// TL;DR
// -----
// - Conversion simple, types primitifs/pointeurs connus → static_cast
// - Création/initialisation d’un objet “complexe” → constructeur
// ============================================================================



// std::string str1(argv[2]);   // constructeur
// std::string str2(argv[3]);   // constructeur

// équivalent :
// std::string str1 = argv[2];  // assignation à l'init
// std::string str2 = argv[3];