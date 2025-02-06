#include "Contact.hpp"

void    Contact::setContact(const int idx, const std::string& f_name, 
                            const std::string& l_name, const std::string& n_name,
                            const std::string& phone, const std::string& secret) {
    index = idx;
    first_name = f_name;
    last_name = l_name;
    nickname = n_name;
    phone_number = phone;
    darkest_secret = secret;
}

void    Contact::displayShortContact(void) const {
    std::cout << std::right << std::setw(10) << index << "|";
    printStr(first_name, BAR);
    printStr(last_name, BAR);
    printStr(nickname, NL);
}

void    Contact::displayFullContact(void) const {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "first name     : " << first_name << std::endl;
    std::cout << "last name      : " << last_name << std::endl;
    std::cout << "nickname       : " << nickname << std::endl;
    std::cout << "phone number   : " << phone_number << std::endl;
    std::cout << "darkest secret : ";
    for (int i(0); i < (int)darkest_secret.length(); ++i)
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
    return (!first_name.empty());
}
