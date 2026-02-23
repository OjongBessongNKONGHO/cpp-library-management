//setting the headers to define emprunt class and its methods
#ifndef EMPRENT_H
#define EMPRENT_H
#include "Livre.h"
#include "Member.h"
#include <string>
#include <ctime>
#include <iostream>

class Emprunt {
private:
    int idLivre;             // ID of the book being borrowed
    int idMembre;            // ID of the member borrowing the book
    std::time_t dateEmprunt; // Date when the book was borrowed
    std::time_t dateRetour;  // Date when the book should be returned

public:
    // generating the Constructor
    Emprunt(int idLivre, int idMembre, std::time_t dateEmprunt, std::time_t dateRetour);

    //  generating Getters
    int getIdLivre() const;
    int getIdMembre() const;
    std::time_t getDateEmprunt() const;
    std::time_t getDateRetour() const;

    //  generating Setters
    void setDateRetour(std::time_t dateRetour);

    // Display loan details
    void afficher() const;

    // Check if the loan is overdue
    bool estEnRetard() const;


#endif // end of EMPRENT_H

// to save the emprunt to files we use this function
static void saveToFile(const std::vector<Emprunt>& emprunts, const std::string& filename);

// to load emprunts from files we use this function aswell
static void loadFromFile(std::vector<Emprunt>& emprunts, const std::string& filename);
};
