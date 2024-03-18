#ifndef GROUP_H
#define GROUP_H

#include "Multimedia.h"
#include <iostream>
#include <list>
#include <vector>
#include <memory>

using MultimediaPtr = std::shared_ptr<Multimedia>;

class Group : public std::vector<MultimediaPtr> {
private:
    std::string groupName;

public:
    /** Constructors */
    Group(const std::string groupName) : groupName(groupName) {}
    Group() : groupName("") {}

    /** Getters */
    std::string getGroupName() const { return groupName; }

    /** Display Method */
    void display(std::ostream& os) const {
        for (auto multimedia : *this) {
            multimedia->display(os);
        }
    }

    /** Add multimedia to the group */
    void add(MultimediaPtr multimedia) {
        push_back(multimedia);
    }
};

#endif