#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
public:
    string  index;
    string  first_name;
    string  last_name;
    string  nickname;

    void setContact(const string& idx, const string& fname, const string& lname, const string& nname) {
        index = idx;
        first_name = fname;
        last_name = lname;
        nickname = nname;
    }

    void displayContact(int idx) {
        cout << right << setw(10) << idx + 1 << "|"
             << setw(10) << first_name << "|"
             << setw(10) << last_name << "|"
             << setw(10) << nickname << endl;
    }
};

class PhoneBook {
private:
    Contact contacts[3];

    bool isValidInput(const string& input) const {
        return !input.empty();
    }

public:
    void addContact(int idx) {
            string  index, first_name, last_name, nickname;

            while (true) {

                index = idx;

                cout << "Enter first name: ";
                getline(cin, first_name);

                cout << "Enter last name: ";
                getline(cin, last_name);

                cout << "Enter nickname: ";
                getline(cin, nickname);

                if (isValidInput(first_name) && isValidInput(last_name) && isValidInput(nickname)) {
                    break ;
                } else {
                    cout << "All fields are required. Please try again." << endl;
                }
            }
            contacts[idx].setContact(index, first_name, last_name, nickname);
    }

    void displayContacts() {
        int idx = 0;
        cout << "Enter index number (1 ~ 8):";
        cin >> idx;
        cout << endl;
        contacts[idx].displayContact(idx);
    }
};

int main() {
    PhoneBook   PhoneBook;
    string      choice;
    int         idx = 1;

    while (true) {
        cout << "\nEnter one of the following commands:" << endl;
        cout << "  [ADD] for add Contact" << endl;
        cout << "  [SEARCH] for display Contact" << endl;
        cout << "  [Exit] for quit program" << endl;
        cout << "Enter the command: ";
        cin >> choice;
        cin.ignore();

        if (choice == "ADD") {
            PhoneBook.addContact(idx % 3);
            idx++;
        } else if (choice == "SEARCH") {
            PhoneBook.displayContacts();
        } else if (choice == "EXIT") {
            cout << "Exit" << endl;
            return 0;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    return 0;
}
