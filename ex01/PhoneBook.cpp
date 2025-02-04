#include "PhoneBook.hpp"

static bool    isValidInput(const std::string& input) {
    if (input.length() != 1 || !isdigit(input[0]))
        return (false);
    if (!(input[0] >= '1' && input[0] <= '8'))
        return (false);
    return (true);
}

static bool    isValidNum(const std::string& input) {
    if (input.length() != 8)
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
    handle_bad_eof_fail();
    std::cout << " last name      : ";
    std::cin >> l_name;
    handle_bad_eof_fail();
    std::cout << " nickname       : ";
    std::cin >> n_name;
    handle_bad_eof_fail();
    while (1) {
        std::cout << " phne number (8digits) : ";
        std::cin >> phone;
        handle_bad_eof_fail();
        if (!isValidNum(phone)) {
            std::cout << "*** 8 digits are required. Please try again. ***" << std::endl;
        } else {
            break ;
        }
    }
    std::cout << " darkest secret : ";
    std::cin >> secret;      
    handle_bad_eof_fail();

    index = idx % 8 + 1;
    contacts[idx].setContact(index, f_name, l_name, n_name, phone, secret);
}

void    PhoneBook::displayList(void) const {
    std::cout << std:: right << "     index| FirstName|  LastName|  NickName" << std::endl;
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

    if (!contacts[0].isRegistered()) {
        std::cout << "\n*** No retistration. Please add a contact first. ***" << std::endl;
        return ;
    }

    displayList();
    while (1)
    {
        std::cout << "index No. ? : ";
        std::cin >> input;
        handle_bad_eof_fail(); 
        if (!isValidInput(input) || !contacts[input[0] - '0' - 1].isRegistered())
            std::cout << "*** Invalid input. Please try again ***" << std::endl;
        else
            break ;
    }
    index = input[0] - '0' - 1;
    contacts[index].displayFullContact();
}

bool   PhoneBook::handle_bad_eof_fail()
{
    if (std::cin.bad() || std::cin.eof() || std::cin.fail())
        exit(1);
    return (true);
}
