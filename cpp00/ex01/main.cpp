#include "phonebook.hpp"

int main() {
    PhoneBook   phoneBook;
    string      command;
    int         idx = 0;

    while (1)
    {
        cout << endl << "Phonebook menu:" << endl
                     << " [ADD] for add contact" << endl
                     << " [SEARCH] for search and display contact" << endl
                     << " [EXIT] for quit program" << endl
                     << "Enter the command : ";
        cin >> command;
        cin.ignore();

        if (command == "ADD") {
            phoneBook.addContact(idx);
            idx = (idx + 1) % 8;
        } else if (command == "SEARCH") {
            phoneBook.searchContact();
        } else if (command == "EXIT") {
            cout << "Exit" << endl;
            return (0);
        } else {
            cout << "Invalid command. Please try again" << endl;
        }
    }
    return (0);
}
