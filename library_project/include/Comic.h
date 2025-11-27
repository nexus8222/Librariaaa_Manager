#ifndef COMIC_H
#define COMIC_H
#include "Item.h"
#include <string>

class Comic : public Item {
private:
    int Volume;
    std::string illustrator;
    std::string universe;

public:
    Comic(int id, std::string title, int Volume, std::string illustrator,std::string universe);

    void display() override;       
    void saveToFile(std::ostream &out) const override;
};

#endif
