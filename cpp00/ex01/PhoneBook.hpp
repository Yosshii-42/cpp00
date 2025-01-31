#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];

public:
    void    addContact(int idx);
    void    displayList(void) const;
    void    searchContact(void);
};

#endif
