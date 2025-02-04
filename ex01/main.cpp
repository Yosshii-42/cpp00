#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
    PhoneBook   phoneBook;
    std::string      command;
    int         idx = 0;

    while (1)
    {
        std::cout << std::endl << "Phonebook menu: [ADD][SEARCH][EXIT]" << std::endl
                  << std::endl << "Enter the command : ";
        std::cin >> command;
        std::cin.ignore();
        PhoneBook::handle_bad_eof_fail();
        if (command == "ADD") {
            phoneBook.addContact(idx);
            idx = (idx + 1) % 8;
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "Exit" << std::endl;
            return (0);
        } else {
            std::cout << "Invalid command. Please try again" << std::endl;
        }
    }
    return (0);
}
