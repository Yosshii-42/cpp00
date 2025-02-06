#include "Contact.hpp"

void    Contact::setContact(const int idx, const std::string& f_name, 
                            const std::string& l_name, const std::string& n_name,
                            const std::string& phone, const std::string& secret) {
    _index = idx;
    _first_name = f_name;
    _last_name = l_name;
    _nickname = n_name;
    _phone_number = phone;
    _darkest_secret = secret;
}

void    Contact::displayShortContact(void) const {
    std::cout << std::right << std::setw(10) << _index << "|";
    printStr(_first_name, BAR);
    printStr(_last_name, BAR);
    printStr(_nickname, NL);
}

void    Contact::displayFullContact(void) const {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "first name     : " << _first_name << std::endl;
    std::cout << "last name      : " << _last_name << std::endl;
    std::cout << "nickname       : " << _nickname << std::endl;
    std::cout << "phone number   : " << _phone_number << std::endl;
    std::cout << "darkest secret : ";
    for (int i(0); i < (int)_darkest_secret.length(); ++i)
        std::cout << ".";
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void    Contact::printStr(const std::string& str, int end) const {
    std::cout << std::setw(10) << (str.length() > 10 ? str.substr(0, 9) + "." : str);
    if (end == BAR) {
        std::cout << "|";
    } else {
        std::cout << "\n";
    }
}

bool    Contact::isRegistered(void) const {
    return (!_first_name.empty());
}
