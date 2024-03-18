#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"
#include <iostream>

class Photo : public Multimedia {
private:
    float width{};
    float height{};

public:
    /** Constructors */
    Photo(const std::string name, const std::string pathname, float width, float height)
        :Multimedia(name, pathname),width(width), height(height){}

    Photo() : Multimedia(), width(0), height(0) {}

    /** Setters */
    void setWidth(float newWidth){ width = newWidth; };
    void setHeight(float newHeight){ height = newHeight; };

    /** Getters*/
    float getWidth() const{ return width; };
    float getHeight() const{ return height; };

    /** Destructors */
    ~Photo(){std::cout << "Destruction de l'objet Photo : " << getName() << std::endl;};

    /** Display Method */
    void display(std::ostream& os) const override{
        Multimedia::display(os);
        os << "Largeur : " << width << "\nHauteur : " << height << std::endl;
    };

    /** Play photo */
    void play() const override {
        std::string command = "open -a \"/Applications/ImageJ.app/Contents/MacOS/ImageJ\" " + getPathname();
        system(command.c_str());
    };
};

#endif
