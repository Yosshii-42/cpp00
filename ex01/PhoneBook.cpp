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
        std::cerr << "\n*** No input. Please try again. ***" << std::endl;
        return (false);
    }
    return (true);
}

bool   PhoneBook::_handle_eof_fail( void)
{
    if (std::cin.eof()) {
        std::cerr << "\n*** EOF detected. Exitting. ***" << std::endl;
        exit(1);
    }
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "\n*** Invalid input. Please try again. ***" << std::endl;
        return (true);
    }
    return (false);
}

void    PhoneBook::_getNewInput( const std::string& message, std::string& input, int select) {
    while (1) {
        std::cout << message;
        std::getline(std::cin, input);
        if (this->_handle_eof_fail())
            continue ;
        if (!this->_isEmpty(input))
            continue ;
        if (select == NUM && !this->_isValidNum(input)) {
            std::cerr << "*** Numeric inputs are required. Please try again. ***" << std::endl;
            continue ;
        }
        break ;
    }    
}

bool    PhoneBook::_isStrMatch( const std::string& str, std::string input ) {
    if (str.length() == input.length())
        return (true);
    return (false);
}

void    PhoneBook::registerPhoneBook( void ) {
    std::string      command;
    int         idx = 0;

    while (1)
    {
        std::cout << std::endl << "Phonebook menu: [ADD][SEARCH][EXIT]" << std::endl;
        this->_getNewInput(" Enter the command : ", command, STRING);
        if (_isStrMatch("ADD", command)) {
            this->addContact(idx);
            idx = (idx + 1) % 8;
        } else if (_isStrMatch("SEARCH", command)) {
            this->searchContact();
        } else if (_isStrMatch("EXIT", command)) {
            std::cout << "Exit" << std::endl;
            return ;
        } else {
            std::cerr << "*** Invalid command. Please try again. ***" << std::endl;
        }
    }    
}

void    PhoneBook::addContact(int idx) {
    int          index;
    std::string  f_name, l_name, n_name, phone, secret;

    this->_getNewInput(" first name     : ", f_name, STRING);
    this->_getNewInput(" last name      : ", l_name, STRING);
    this->_getNewInput(" nickname       : ", n_name, STRING);
    this->_getNewInput(" pohne number   : ", phone, NUM);
    this->_getNewInput(" darkest secret : ", secret, STRING);
    index = idx % MAX_CONTACTS + 1;
    this->_contacts[idx].setContact(index, f_name, l_name, n_name, phone, secret);
}

void    PhoneBook::displayList(void) const {
    std::cout << std:: right << "     index| FirstName|  LastName|  NickName" << std::endl;
    std::cout <<                "----------------------------------------------" << std::endl;
    for (int i(0); i < MAX_CONTACTS; i++) {
        if (this->_contacts[i].isRegistered())
            this->_contacts[i].displayShortContact();
    }
    std::cout <<                "----------------------------------------------" << std::endl;
}

void    PhoneBook::searchContact(void) {
    std::string input;
    int         index;

    if (!this->_contacts[0].isRegistered()) {
        std::cerr << "\n*** No retistration. Please add a contact first. ***" << std::endl;
        return ;
    }
    displayList();
    while (1) {
        this->_getNewInput(" index No. ? : ", input, STRING);
        if (!(this->_isValidNum(input) && this->_isValidIndex(input))
            || !this->_contacts[input[0] - '0' - 1].isRegistered())
            std::cerr << "*** Invalid input. Please try again ***" << std::endl;
        else
            break ;
    }
    index = input[0] - '0' - 1;
    this->_contacts[index].displayFullContact();
}
