#ifndef FILM_H
#define FILM_H

#include "Video.h"
#include <iostream>

class Film : public Video {
private:
    int * durations{};
    int nbChap{};

public:
    /** Constructors */
    Film(const std::string name, const std::string pathname, int time, int * durations, int nbChap);
    Film();

    /** Setters */
    void setDurations(int * durations, int nbChap);

    /** Getters */
    int const * getDurations() const;
    int getNbChap() const;

    /** Destructors */
    ~Film();

    /** Display Method */
    void display(std::ostream& os) const override;
};

#endif