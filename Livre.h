//I have to define the headers we will use in setting up the library
#ifndef LIVRE_H
#define LIVRE_H
#include <string>
#include <iostream>

//here we will define the attributes of Livre and declare the classes
class Livre {
private:
    int id;
    std::string titre;
    std::string auteur;
    int anneePublication;
    std::string genre;

public:
    // Constructors for the class livre
    Livre(int id, const std::string& titre, const std::string& auteur, int anneePublication, const std::string& genre);

    // setting the Getters
    int getId() const;
    std::string getTitre() const;
    std::string getAuteur() const;
    int getAnneePublication() const;
    std::string getGenre() const;

    // setting the Setters
    void setTitre(const std::string& titre);
    void setAuteur(const std::string& auteur);
    void setAnneePublication(int anneePublication);
    void setGenre(const std::string& genre);

    // the function required to display livre
    void afficher() const;

// in order to save livre to file we will use the function below
static void saveToFile(const std::vector<Livre>& livres, const std::string& filename);

// To load the list of livre from the file
static void loadFromFile(std::vector<Livre>& livres, const std::string& filename);

};
#endif // end of livre

