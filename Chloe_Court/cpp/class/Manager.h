#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <memory>

using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using GroupPtr = std::shared_ptr<Group>;

class Manager {
private:
    std::map<std::string, MultimediaPtr> multTable{};
    std::map<std::string, GroupPtr> groupTable{};

public:
    /** Constructors */ 
    Manager() {};

    /** Destructors */
    ~Manager() {};

    /** Create methods 
        * @return a pointer to the created multimedia object in the manager object
    */
    PhotoPtr createPhoto(const std::string& name, const std::string& path, int width, int height);
    VideoPtr createVideo(const std::string& name, const std::string& path, int duration);
    FilmPtr createFilm(const std::string name, const std::string pathname, int time, int * durations, int nbChap);
    GroupPtr createGroup(const std::string& name);

    /** Search and display method 
        * @param name : name of the multimedia object or group to search
        * @param os : output stream to display the object
    */
    void searchAndDisplay(const std::string& name, std::ostream& os);

    /* Play method */
    void play(const std::string& name);

    /**  Get all items in the manager
        * @return a vector of strings containing all the items in the manager
    */
    std::vector<std::string> getAllItems();
};

#endif