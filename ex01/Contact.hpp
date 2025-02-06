#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

#define BAR 0
#define NL 1 

class Contact {
private:
    int         _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

    void    _printStr(const std::string& str, int end) const;

public:
    void    setContact(const int idx, const std::string& f_name,
                       const std::string& l_name, const std::string& n_name,
                       const std::string& phone, const std::string& secret);
    void    displayShortContact() const;
    void    displayFullContact() const;
    bool    isRegistered() const;
};

#endif