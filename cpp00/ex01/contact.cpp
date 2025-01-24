#include "contact.hpp"

void    Contact::setContact(const int idx, const string& fname, const string& lname, const string& nname) {
    index = idx;
    first_name = fname;
    last_name = lname;
    nickname = nname;
}

void    Contact::printContact(int idx) {
    cout << right << setw(10) << idx << "|";
    printStr(first_name);
    cout << "|";
    printStr(last_name);
    cout << "|";
    printStr(nickname);
    cout << endl;
}

void    Contact::printStr(const string& str) {
    cout << right << setw(10) << (str.length() > 10 ? str.substr(0, 9) + "." : str);
}
