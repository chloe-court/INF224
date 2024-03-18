#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"
#include <iostream>

class Video : public Multimedia {
private:
    int time{};

public:
    /** Constructors */
    Video(const std::string name, const std::string pathname, int time)
        : Multimedia(name, pathname), time(time) {}
    Video() : Multimedia(), time(0) {}

    /** Setters */
    void setTime(int newTime){ time = newTime; };

    /** Getters*/
    int getTime() const{ return time; };

    /** Destructors */
    ~Video(){std::cout << "Destruction de l'objet Video : " << getName() << std::endl;};

    /** Display Method */
    virtual void display(std::ostream& os) const override{
        Multimedia::display(os);
        os << "Durée : " << time << std::endl;
    };

    /** Play video */
    void play() const override {
        std::string command = "mpv " + getPathname() + " &";
        system(command.data());
    };
};
#endif
