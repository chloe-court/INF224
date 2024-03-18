#include "Manager.h"

// Create methods
PhotoPtr Manager::createPhoto(const std::string& name, const std::string& path, int width, int height) {
    PhotoPtr photo = PhotoPtr(new Photo(name, path, width, height));
    multTable[name] = photo;
    return photo;
}

VideoPtr Manager::createVideo(const std::string& name, const std::string& path, int duration) {
    VideoPtr video = VideoPtr(new Video(name, path, duration));
    multTable[name] = video;
    return video;
}

FilmPtr Manager::createFilm(const std::string name, const std::string pathname, int time, int * durations, int nbChap) {
    FilmPtr film = FilmPtr(new Film(name, pathname, time, durations, nbChap));
    multTable[name] = film;
    return film;
}

GroupPtr Manager::createGroup(const std::string& name) {
    GroupPtr group = GroupPtr(new Group(name));
    groupTable[name] = group;
    return group;
}

void Manager::searchAndDisplay(const std::string& name, std::ostream& os=std::cout) {
        // Search for multimedia object
        auto multIt = multTable.find(name);
        if (multIt != multTable.end()) {
            MultimediaPtr multimedia = multIt->second;
            multimedia->display(os);
            return;
        }
        // Search for group
        auto groupIt = groupTable.find(name);
        if (groupIt != groupTable.end()) {
            GroupPtr group = groupIt->second;
            group->display(os);
            return;
        }
        // Object or group not found
        os << "Object or group not found." << std::endl;
}

void Manager::play(const std::string& name) {
    // Search for multimedia object
    auto multIt = multTable.find(name);
    if (multIt != multTable.end()) {
        MultimediaPtr multimedia = multIt->second;
        multimedia->play();
        return;
    }
    // Object not found
    std::cout << "Object not found." << std::endl;
}

std::vector<std::string> Manager::getAllItems() {
    std::vector<std::string> items;
    for (const auto& item : multTable) {
        items.push_back(item.first);
    }
    for (const auto& item : groupTable) {
        items.push_back(item.first);
    }
    return items;
}

