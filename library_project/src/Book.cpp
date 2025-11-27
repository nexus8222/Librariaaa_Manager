#include "Book.h"
#include <iostream>
#include <fstream>
Book::Book(int id, std::string title, std::string author, int pages)
    : Item(id, title), author(author), pages(pages) {}


    
void Book::saveToFile(std::ostream &out) {
    out << "Book|" << id << "|" << title << "|" << author << "|" << pages << std::endl;
}



// Display book info
void Book::display() {
    std::cout << "Book ID: " << id << "\nTitle: " << title
              << "\nAuthor: " << author << "\nPages: " << pages << std::endl;
}
