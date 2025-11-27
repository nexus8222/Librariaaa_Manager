#include "Magazine.h"
#include <iostream>
#include <fstream>

Magazine::Magazine(int id, std::string title, int issueNumber, std::string month)
    : Item(id, title), issueNumber(issueNumber), month(month) {}

// Save to file
void Magazine::saveToFile(std::ostream &out) const {
    out << "Magazine|" << id << "|" << title << "|" << issueNumber << "|" << month << std::endl;
}

// Display magazine info
void Magazine::display() {
    std::cout << "Magazine ID: " << id 
              << "\nTitle: " << title
              << "\nIssue Number: " << issueNumber
              << "\nMonth: " << month << std::endl;
}
