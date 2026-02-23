#include <fstream>
#include <vector>
#include <sstream>
#include "Livre.h"

// setting the Constructor for livre
Livre::Livre(int id, const std::string& titre, const std::string& auteur, int anneePublication, const std::string& genre)
    : id(id), titre(titre), auteur(auteur), anneePublication(anneePublication), genre(genre) {}

//  setting Getters for livre
int Livre::getId() const { return id; }
std::string Livre::getTitre() const { return titre; }
std::string Livre::getAuteur() const { return auteur; }
int Livre::getAnneePublication() const { return anneePublication; }
std::string Livre::getGenre() const { return genre; }

// setting Setters for livre
void Livre::setTitre(const std::string& titre) { this->titre = titre; }
void Livre::setAuteur(const std::string& auteur) { this->auteur = auteur; }
void Livre::setAnneePublication(int anneePublication) { this->anneePublication = anneePublication; }
void Livre::setGenre(const std::string& genre) { this->genre = genre; }

// the function do display livre
void Livre::afficher() const {
    std::cout << "ID: " << id << ", Titre: " << titre
              << ", Auteur: " << auteur
              << ", Annee: " << anneePublication
              << ", Genre: " << genre << std::endl;
}
// we need to Save the list of livre to a file, so we use this function
void Livre::saveToFile(const std::vector<Livre>& livres, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'ecriture!" << std::endl;
        return;
    }

    for (const auto& livre : livres) {
        outFile << livre.getId() << "," << livre.getTitre() << ","
                << livre.getAuteur() << "," << livre.getAnneePublication() << ","
                << livre.getGenre() << std::endl;
    }

    outFile.close();
}
// To load books from a file we need to use this function
void Livre::loadFromFile(std::vector<Livre>& livres, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour la lecture!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        int id;
        std::string titre, auteur, genre;
        int anneePublication;

        std::getline(ss, titre, ',');
        std::getline(ss, auteur, ',');
        ss >> anneePublication;
        ss.ignore(); // ignore comma
        std::getline(ss, genre, ',');

        // Add the book to the list
        livres.push_back(Livre(id, titre, auteur, anneePublication, genre));
    }

    inFile.close();
}
