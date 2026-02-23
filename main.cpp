#include <iostream>
#include <vector>
#include "Livre.h"
#include "Member.h"
#include <string>

//to create a brief welcome and description about my work
void afficherBienvenue() {
    std::cout << "============*****===============*****===============\n";
    std::cout << "   BIENVENUE AU GESTIONNAIRE DE BIBLIOTHEQUE\n";
    std::cout << "============*****====================*****==========\n";
    std::cout << "Un systeme simple et efficace pour gerer vos livres\n";
    std::cout << "et vos membres. Simplifiez vos operations des aujourd'hui!\n";
    std::cout << "------------------------------------------\n";
    std::cout << "             Parfait pour :               \n";
    std::cout << "   - Ajouter des livres                  \n";
    std::cout << "   - Gerer vos membres                   \n";
    std::cout << "   - Enregistrer et charger vos donnees  \n";
    std::cout << "------------------------------------------\n\n";
}
//i ussed to model to create a list of options in the intaercative menu with the different users of my code
void afficherMenu() {
    std::cout << "\n=== GESTIONNAIRE DE BIBLIOTHEQUE ===\n";
    std::cout << "1. Ajouter un livre\n";
    std::cout << "2. Afficher tous les livres\n";
    std::cout << "3. Sauvegarder les livres dans un fichier\n";
    std::cout << "4. Charger les livres depuis un fichier\n";
    std::cout << "5. Ajouter un membre\n";
    std::cout << "6. Afficher tous les membres\n";
    std::cout << "7. Sauvegarder les membres dans un fichier\n";
    std::cout << "8. Charger les membres depuis un fichier\n";
    std::cout << "9. Quitter\n";
    std::cout << "Choisissez une option : ";
}

int main() {
    afficherBienvenue();
    std::vector<Livre> livres;
    std::vector<Membre> membres;

    int choix;
    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
        case 1: { // adding a book
            std::cin.ignore(); //i used this function to clear the input buffers generated
            int id;
            std::string titre, auteur, genre;
            int anneePublication;

            std::cout << "Entrez l'ID du livre : ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Entrez le titre du livre : ";
            std::getline(std::cin, titre);
            std::cout << "Entrez l'auteur du livre : ";
            std::getline(std::cin, auteur);
            std::cout << "Entrez l'annee de publication : ";
            std::cin >> anneePublication;
            std::cin.ignore();
            std::cout << "Entrez le genre du livre : ";
            std::getline(std::cin, genre);

            livres.emplace_back(id, titre, auteur, anneePublication, genre);
            std::cout << "Livre ajouté avec succès.\n";
            break;
        }
        case 2: { // to display all books
            if (livres.empty()) {
                std::cout << "Aucun livre disponible.\n";
            } else {
                for (const auto& livre : livres) {
                    livre.afficher();
                }
            }
            break;
        }
        case 3: { // TO save the books in a file
            Livre::saveToFile(livres, "livres.txt");
            std::cout << "Livres sauvegardes dans 'livres.txt'.\n";
            break;
        }
        case 4: { // To load books from a file
            Livre::loadFromFile(livres, "livres.txt");
            std::cout << "Livres charges depuis 'livres.txt'.\n";
            break;
        }
        case 5: { // To add a member
            std::cin.ignore(); // Clear input buffer
            int id;
            std::string nom, prenom, email;

            std::cout << "Entrez l'ID du membre : ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Entrez le nom du membre : ";
            std::getline(std::cin, nom);
            std::cout << "Entrez le prenom du membre : ";
            std::getline(std::cin, prenom);
            std::cout << "Entrez l'email du membre : ";
            std::getline(std::cin, email);

            membres.emplace_back(id, nom, prenom, email);
            std::cout << "Membre ajoute avec succes.\n";
            break;
        }
        case 6: { // To display all members
            if (membres.empty()) {
                std::cout << "Aucun membre disponible.\n";
            } else {
                for (const auto& membre : membres) {
                    membre.afficher();
                }
            }
            break;
        }
        case 7: { // to save all members in a file
            Membre::saveToFile(membres, "membres.txt");
            std::cout << "Membres sauvegardes dans 'membres.txt'.\n";
            break;
        }
        case 8: { // To load a member from a file
            Membre::loadFromFile(membres, "membres.txt");
            std::cout << "Membres charges depuis 'membres.txt'.\n";
            break;
        }
        case 9: { // Exiting
            std::cout << "Au revoir et a bientot!!!\n";
            break;
        }
        default:
            std::cout << "Option invalide. Veuillez reessayer.\n";
            break;
        }
    } while (choix != 9);



    return 0;
}
