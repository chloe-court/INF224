#include "Multimedia.h"

// Constructeur
Multimedia::Multimedia(std::string newName, std::string newPathname) : name(newName), pathname(newPathname) {}
Multimedia::Multimedia() : name(""), pathname("") {}

// Setters
void Multimedia::setName(std::string newName) { name = newName; }
void Multimedia::setPathname(std::string newPathname) { pathname = newPathname; }

// Getters
std::string Multimedia::getName() const { return name; }
std::string Multimedia::getPathname() const { return pathname; }

// Destructeur
Multimedia::~Multimedia() {}

// Afficher sur le terminal en utilisant std::cout en argument
void Multimedia::display(std::ostream& os) const {
    os << "Nom : " << name << "\nChemin : " << pathname << std::endl;
}
