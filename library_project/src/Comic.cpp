#include "Comic.h"
#include <iostream>

#include <fstream>

Comic::Comic(int id, std::string title, int Volume, std::string illustrator,std::string universe)
    : Item(id, title), Volume(Volume), illustrator(illustrator),universe(universe) {}

void Comic::saveToFile(std::ostream &out)const {
    out << "Comic|" << id << "|" << title << "|" << illustrator << "|" << Volume << "|" << universe << std::endl;

}

void Comic::display() {
    std::cout << "Comic ID: " << id 
              << "\nTitle: " << title
              << "\nIllustrator: " << illustrator
              << "\nVolume: " << Volume << std::endl;
}
