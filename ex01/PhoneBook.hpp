#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];

public:
    void        addContact(int idx);
    void        displayList(void) const;
    void        searchContact(void);
    static bool handle_bad_eof_fail(void);    
};

#endif
