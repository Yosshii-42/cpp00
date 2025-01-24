#include "phonebook.hpp"

bool    PhoneBook::isValidInput(const string& input) const {
    return !input.empty();
}

void    PhoneBook::addContact(int idx) {
    int     index;
    string  first_name, last_name, nickname;

    while (1) {
        cout << " Enter first_name : ";
        getline(cin, first_name);

        cout << " Enter last_name  : ";
        getline(cin, last_name);

        cout << " Enter nickname   : ";
        getline(cin, nickname);

        if (isValidInput(first_name) && isValidInput(last_name) && isValidInput(nickname)) {
            break ;
        } else {
            cout << "All fields must be filled in. Please try again." << endl;
        }
    }
    index = idx + 1;
    contacts[idx].setContact(index, first_name, last_name, nickname);
}

void    PhoneBook::searchContact() {
    int idx = 0;

    while (1) {
        cout << "Enter index number (1 ~ 8) : ";
        cin >> idx;
        if (idx < 1 || idx > 8) {
            cout << "Invalid number. Please try again.";
        } else {
            break ;
        }
    }
    cout << endl;
    contacts[idx - 1].printContact(idx);
}
