#include "PhoneBook.hpp"

static bool    isValidInput(const std::string& input) {
    if (input.length() != 1 || !isdigit(input[0]))
        return (false);
    if (!(input[0] >= '1' && input[0] <= '8'))
        return (false);
    return (true);
}

static bool    isValidNum(const std::string& input) {
    if (input.length() != 10)
        return (false);
    for (int i(0); input[i]; i++) {
        if (!std::isdigit(input[i]))
            return (false);
    }
    return (true);
}

void    PhoneBook::addContact(int idx) {
    int          index;
    std::string  f_name, l_name, n_name, phone, secret;

    std::cout << " first name     : ";
    std::cin >> f_name;
    std::cout << " last name      : ";
    std::cin >> l_name;
    std::cout << " nickname       : ";
    std::cin >> n_name;
    while (1) {
        std::cout << " phne number (10digits) : ";
        std::cin >> phone;
        if (!isValidNum(phone)) {
            std::cout << "10 digits are required. Please try again." << std::endl;
        } else {
            break ;
        }
    }
    std::cout << " darkest secret : ";
    std::cin >> secret;      

    index = (idx + 1) % 8;
    contacts[idx % 8].setContact(index, f_name, l_name, n_name, phone, secret);
}

void    PhoneBook::displayList(void) const {
    std::cout << std:: right << "   index  | FirstName| LastName | NickName " << std::endl;
    std::cout <<                "----------------------------------------------" << std::endl;
    for (int i(0); i < 8; i++) {
        if (contacts[i].isRegistered())
            contacts[i].displayShortContact();
    }
    std::cout <<                "----------------------------------------------" << std::endl;

}

void    PhoneBook::searchContact(void) {
    std::string input;
    int         index;

    displayList();
    while (1)
    {
        std::cout << "index No. ? : ";
        std::cin >> input;
        if (!isValidInput(input) || !contacts[input[0] - '0' - 1].isRegistered())
            std::cout << "Invalid input. Please try again" << std::endl;
        else
            break ;
    }
    index = input[0] - '0' - 1;
    contacts[index].displayFullContact();
}
