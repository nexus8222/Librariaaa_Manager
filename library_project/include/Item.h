#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ostream>

class Item {
protected:
    int id;
    std::string title;

public:
    Item(int id, const std::string& title) : id(id), title(title) {} 

    virtual void display() = 0;
    virtual void saveToFile(std::ostream& out) const = 0;


    virtual ~Item();
    int getIId() const { return id; };
};

#endif // ITEM_H
