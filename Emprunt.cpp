#include <fstream>
#include <sstream>
#include <vector>
#include "Emprunt.h"
#include <ctime>

//  generating the Constructor for emprunt
Emprunt::Emprunt(int idLivre, int idMembre, std::time_t dateEmprunt, std::time_t dateRetour)
    : idLivre(idLivre), idMembre(idMembre), dateEmprunt(dateEmprunt), dateRetour(dateRetour) {}

//  generating Getters for emprunt
int Emprunt::getIdLivre() const { return idLivre; }
int Emprunt::getIdMembre() const { return idMembre; }
std::time_t Emprunt::getDateEmprunt() const { return dateEmprunt; }
std::time_t Emprunt::getDateRetour() const { return dateRetour; }

// generating Setters for emprunt
void Emprunt::setDateRetour(std::time_t dateRetour) { this->dateRetour = dateRetour; }

// To display loan details
void Emprunt::afficher() const {
    std::cout << "Livre ID: " << idLivre << ", Membre ID: " << idMembre
              << ", Date Emprunt: " << std::ctime(&dateEmprunt)
              << ", Date Retour: " << std::ctime(&dateRetour) << std::endl;
}

// we need to check if the emprunt is overdue
bool Emprunt::estEnRetard() const {
    std::time_t currentDate = std::time(nullptr);
    return currentDate > dateRetour;
}
// To save the list of emprunt to a file
void Emprunt::saveToFile(const std::vector<Emprunt>& emprunts, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture!" << std::endl;
        return;
    }

    for (const auto& emprunt : emprunts) {
        outFile << emprunt.getIdLivre() << "," << emprunt.getIdMembre() << ","
                << emprunt.getDateEmprunt() << "," << emprunt.getDateRetour() << std::endl;
    }

    outFile.close();
}
// we will use this function to load all emprunts from a file
void Emprunt::loadFromFile(std::vector<Emprunt>& emprunts, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la lecture!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        int idLivre, idMembre;
        std::time_t dateEmprunt, dateRetour;

        ss >> idLivre;
        ss.ignore(); //here we use this function to ignore the commas which appear
        ss >> idMembre;
        ss.ignore();
        ss >> dateEmprunt;
        ss.ignore();
        ss >> dateRetour;

        //  function to Add the loan to the list
        emprunts.push_back(Emprunt(idLivre, idMembre, dateEmprunt, dateRetour));
    }

    inFile.close();
}
