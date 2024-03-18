#include "Film.h"
#include "Video.h"

// Constructeur
Film::Film(const std::string newName,const std::string newPathname, int time, int * durations, int nbChap)
    : Video(newName, newPathname, time), nbChap(nbChap) 
    {
        if (nbChap < 0) return;
        if(nbChap == 0) this -> durations = nullptr;
    
        this -> durations = new int[nbChap];
        for (int i = 0; i < nbChap; i++)
        {
            this -> durations[i] = durations[i];
        }
    }

Film::Film() : Video(), durations(nullptr), nbChap(0) {}

// Setters
void Film::setDurations(int* newDurations, int newNbChap) {
    if (newNbChap < 0) return;
    if(newNbChap == 0) this -> durations = nullptr;
    if (durations != nullptr) {
        delete[] durations;
        durations = nullptr;
    }
    nbChap=newNbChap;
    durations = new int[newNbChap];
    for (int i = 0; i < newNbChap; ++i) {
        durations[i] = newDurations[i];
    }
}

// Getters
int const * Film::getDurations() const { return durations; }

int Film::getNbChap() const { return nbChap; }

// Destructeur
Film::~Film() {delete[] durations;}

// Afficher sur le terminal en utilisant std::cout en argument
void Film::display(std::ostream& os) const {
    Video::display(os);
    os << "Durée des chapitres : ";
        for (int i = 0; i < nbChap; ++i) {
            os << durations[i] << " ";
        }
    os << std::endl;
}