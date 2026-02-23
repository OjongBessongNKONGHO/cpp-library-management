//headers for members
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor for members
Membre::Membre(int id, const std::string& nom, const std::string& prenom, const std::string& email)
    : id(id), nom(nom), prenom(prenom), email(email) {}

int Membre::getId() const {
    return id;
}

std::string Membre::getNom() const {
    return nom;
}

std::string Membre::getPrenom() const {
    return prenom;
}

std::string Membre::getEmail() const {
    return email;
}

void Membre::afficher() const {
    std::cout << "ID: " << id << ", Nom: " << nom << ", Prénom: " << prenom
              << ", Email: " << email << std::endl;
}

//  we use a static method to save members to a file
void Membre::saveToFile(const std::vector<Membre>& membres, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture!" << std::endl;
        return;
    }

    for (const auto& membre : membres) {
        outFile << membre.id << "," << membre.nom << ","
                << membre.prenom << "," << membre.email << std::endl;
    }

    outFile.close();
}

// we use a Static method aswell to load members from a file
void Membre::loadFromFile(std::vector<Membre>& membres, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la lecture!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line); // Corrected with proper include
        int id;
        std::string nom, prenom, email;

        ss >> id;
        ss.ignore(); // ignore comma
        std::getline(ss, nom, ',');
        std::getline(ss, prenom, ',');
        std::getline(ss, email, ',');

        membres.push_back(Membre(id, nom, prenom, email));
    }

    inFile.close();
}
