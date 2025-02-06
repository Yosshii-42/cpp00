#include "PhoneBook.hpp"

bool    PhoneBook::_isValidIndex(const std::string& input) {
    int num;

    std::stringstream ss(input);
    ss >> num;
    if (!(num >= 1 && num <= MAX_CONTACTS))
        return (false);
    return (true);
}

bool    PhoneBook::_isValidNum(const std::string& input) {
    for (size_t i(0); i < input.length(); ++i) {
        if (!std::isdigit(input[i]))
            return (false);
    }
    return (true);
}

bool    PhoneBook::_isEmpty( const std::string& input ) {
    if (input.empty()) {
        std::cout << "\n*** No input. Please try again. ***" << std::endl;
        return (false);
    }
    return (true);
}

bool   PhoneBook::_handle_bad_eof_fail( const std::string& input)
{
    if (std::cin.bad() || std::cin.eof() || std::cin.fail())
        exit(1);
    if (_isEmpty(input) == false)
        return (true);
    return (false);
}

void    PhoneBook::registerPhoneBook( void ) {
    std::string      command;
    int         idx = 0;

    while (1)
    {
        while (1) {
            std::cout << std::endl << "Phonebook menu: [ADD][SEARCH][EXIT]" << std::endl
                    << std::endl << "Enter the command : ";
            std::getline(std::cin, command);
            if (_handle_bad_eof_fail(command) == false)
                break ; 
        }
        if (command == "ADD" && command.length() == 3) {
            this->addContact(idx);
            idx = (idx + 1) % 8;
        } else if (command == "SEARCH" && command.length() == 6) {
            this->searchContact();
        } else if (command == "EXIT" && command.length() == 4) {
            std::cout << "Exit" << std::endl;
            return ;
        } else {
            std::cout << "*** Invalid command. Please try again. ***" << std::endl;
        }
    }    
}

void    PhoneBook::addContact(int idx) {
    int          index;
    std::string  f_name, l_name, n_name, phone, secret;

    while (1) {
        std::cout << " first name     : ";
        std::getline(std::cin, f_name);
        if (_handle_bad_eof_fail(f_name) == false)
            break ;
    }

    while (1) {
        std::cout << " last name      : ";
        std::getline(std::cin, l_name);
        if (_handle_bad_eof_fail(l_name) == false)
            break ;
    }

    while (1) {
        std::cout << " nickname       : ";
        std::getline(std::cin, n_name);
        if (_handle_bad_eof_fail(n_name) == false)
            break ;
    }

    while (1) {
        std::cout << " pohne number   : ";
        std::getline(std::cin, phone);
        if (_handle_bad_eof_fail(phone) == true || !_isValidNum(phone)) {
            std::cout << "*** Numeric inputs are required. Please try again. ***" << std::endl;
        } else {
            break ;
        }
    }

    while (1) {
        std::cout << " darkest secret : ";
        std::getline(std::cin, secret);
        if (_handle_bad_eof_fail(secret) == false)        
            break ;
    }

    index = idx % MAX_CONTACTS + 1;
    _contacts[idx].setContact(index, f_name, l_name, n_name, phone, secret);
}

void    PhoneBook::displayList(void) const {
    std::cout << std:: right << "     index| FirstName|  LastName|  NickName" << std::endl;
    std::cout <<                "----------------------------------------------" << std::endl;
    for (int i(0); i < MAX_CONTACTS; i++) {
        if (_contacts[i].isRegistered())
            _contacts[i].displayShortContact();
    }
    std::cout <<                "----------------------------------------------" << std::endl;

}

void    PhoneBook::searchContact(void) {
    std::string input;
    int         index;

    if (!_contacts[0].isRegistered()) {
        std::cout << "\n*** No retistration. Please add a contact first. ***" << std::endl;
        return ;
    }

    displayList();
    while (1) {
        while (1) {
            std::cout << "index No. ? : ";
            std::getline(std::cin, input);
            if (_handle_bad_eof_fail(input) == false)
                break ;
        }
        if (!(this->_isValidNum(input) && this->_isValidIndex(input)) || !_contacts[input[0] - '0' - 1].isRegistered())
            std::cout << "*** Invalid input. Please try again ***" << std::endl;
        else
            break ;
    }
    index = input[0] - '0' - 1;
    _contacts[index].displayFullContact();
}
