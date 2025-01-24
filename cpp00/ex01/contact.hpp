#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Contact {
public:
    int     index;
    string  first_name;
    string  last_name;
    string  nickname;

    void    setContact(const int idx, const string& fname, const string& lname, const string& nname);
    void    printContact(int idx);
    void    printStr(const string& str);
};

#endif