#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "Item.h"
#include "User.h"

class Library {
private:
    Item** items;
    int itemCount;
    int itemCapacity;

    User* users;
    int userCount;
    int userCapacity;

    int nextItemId;
    int nextUserId;

    void expandItems();
    void expandUsers();

public:
    Library();
    ~Library();

    int addBook(std::string title, std::string author, int pages);
    int addMagazine(std::string title, int issue, std::string month);
    int addComic(std::string title, std::string universe);

    int addUser(std::string name);

    void borrowItem(int userId, int itemId);
    void returnItem(int userId, int itemId);

    void showAllItems();
    void showAllUsers();
};

#endif
