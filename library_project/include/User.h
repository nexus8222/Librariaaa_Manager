#ifndef USER_H
#define USER_H
#include <string>

class User {
private:
    int id;

public:
    User();

    std::string name;
    int* borrowedItemIds;   // dynamic array
    int borrowedCount;      // how many items
    int capacity;           // array size

    // Constructor
    User(int id, std::string name);

    // Deep Copy Constructor
    User(const User& other);

    // Destructor
    ~User();

    void borrowItem(int itemId);
    void returnItem(int itemId);
    int getId() const { return id; }


    void display() const;
};

#endif
