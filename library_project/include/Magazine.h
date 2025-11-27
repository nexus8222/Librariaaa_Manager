#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Item.h"
#include <string>

class Magazine : public Item {
private:
    int issueNumber;
    std::string month;

public:
   
    Magazine(int id, std::string title, int issueNumber, std::string month);

    void display() override;       
    void saveToFile(std::ostream &out) const override;
};

#endif
