#include "Contact.hpp"

void    Contact::setContact(const int idx, const std::string& f_name, 
                            const std::string& l_name, const std::string& n_name,
                            const std::string& phone, const std::string& secret) {
    this->_index = idx;
    this->_first_name = f_name;
    this->_last_name = l_name;
    this->_nickname = n_name;
    this->_phone_number = phone;
    this->_darkest_secret = secret;
}

void    Contact::displayShortContact(void) const {
    std::cout << std::right << std::setw(10) << _index << "|";
    this->_printStr(this->_first_name, BAR);
    this->_printStr(this->_last_name, BAR);
    this->_printStr(this->_nickname, NL);
}

void    Contact::displayFullContact(void) const {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "first name     : " << this->_first_name << std::endl;
    std::cout << "last name      : " << this->_last_name << std::endl;
    std::cout << "nickname       : " << this->_nickname << std::endl;
    std::cout << "phone number   : " << this->_phone_number << std::endl;
    std::cout << "darkest secret : ";
    for (int i(0); i < (int)this->_darkest_secret.length(); ++i)
        std::cout << ".";
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void    Contact::_printStr(const std::string& str, int end) const {
    std::cout << std::setw(10) << (str.length() > 10 ? str.substr(0, 9) + "." : str);
    if (end == BAR) {
        std::cout << "|";
    } else {
        std::cout << "\n";
    }
}

bool    Contact::isRegistered(void) const {
    return (!this->_first_name.empty());
}
