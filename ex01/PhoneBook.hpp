#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <sstream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>
# include "Contact.hpp"

# define MAX_CONTACTS 8
# define STRING 0
# define NUM 1

class PhoneBook {
private:
    Contact _contacts[MAX_CONTACTS];
    bool    _isValidIndex( const std::string& input );
    bool    _isValidNum( const std::string& input );
    bool    _isEmpty( const std::string& input);
    bool    _isStrMatch( const std::string& str, std::string input );
    void    _getNewInput( const std::string& message, std::string& input, int select);
    bool    _handle_eof_fail( void );

public:
    void    registerPhoneBook(void);
    void    addContact(int idx);
    void    displayList(void) const;
    void    searchContact(void);
};

#endif
