#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

#define BAR 0
#define NL 1 

class Contact {
private:
    int     index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void    setContact(const int idx, const std::string& f_name,
                       const std::string& l_name, const std::string& n_name,
                       const std::string& phone, const std::string& secret);
    void    displayShortContact() const;
    void    displayFullContact() const;
    void    printStr(const std::string& str, int end) const;
    bool    isRegistered() const;
};

#endif