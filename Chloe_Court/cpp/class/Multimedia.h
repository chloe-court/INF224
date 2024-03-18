#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
private:
    std::string name;
    std::string pathname;

public:
    /** Constructors */
    Multimedia(std::string newName, std::string newPathname);
    Multimedia();

    /** Setters */
    void setName(std::string);
    void setPathname(std::string);

    /** Getters */
    std::string getName() const;
    std::string getPathname() const;

    /** Destructors */
    ~Multimedia();

    /** Display Method */
    virtual void display(std::ostream& os) const;

    /** Play Video or Photo */
    virtual void play() const = 0;
};

#endif
