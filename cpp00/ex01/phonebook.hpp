#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
using namespace std;

class PhoneBook {
private:
    Contact contacts[8];
    bool isValidInput(const string& input) const;
public:
    void    addContact(int idx);
    void    searchContact();
};

#endif
