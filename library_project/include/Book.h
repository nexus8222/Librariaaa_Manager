#ifndef BOOK_H
#define BOOK_H

#include "Item.h"
#include <string>

class Book : public Item {
private:
    std::string author;
    int pages;

public:
    Book(int id, std::string title, std::string author, int pages);
    
    void display() override;       
    void saveToFile(std::ostream &out) override;

};

#endif // BOOK_H
