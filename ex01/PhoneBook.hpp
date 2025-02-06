#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
private:
    Contact _contacts[MAX_CONTACTS];
    bool    _isValidIndex( const std::string& input );
    bool    _isValidNum( const std::string& input );
    bool    _isEmpty( const std::string& input);
    bool    _handle_bad_eof_fail( const std::string& input );    

public:
    void    registerPhoneBook(void);
    void    addContact(int idx);
    void    displayList(void) const;
    void    searchContact(void);
};

#endif
