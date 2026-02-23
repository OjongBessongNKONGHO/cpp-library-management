//setting headers for members
#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include <vector>

class Membre {
private:
    int id;
    std::string nom;
    std::string prenom;
    std::string email;

public:
    // we define Constructor
    Membre(int id, const std::string& nom, const std::string& prenom, const std::string& email);

    //  set the Getters
    int getId() const;
    std::string getNom() const;
    std::string getPrenom() const;
    std::string getEmail() const;

    //  set the Setters
    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setEmail(const std::string& email);

    // to display the member
    void afficher() const;



// to save the list of members in file
static void saveToFile(const std::vector<Membre>& membres, const std::string& filename);

// we use this function to load the list of members from files
static void loadFromFile(std::vector<Membre>& membres, const std::string& filename);
};
#endif // end of membre
