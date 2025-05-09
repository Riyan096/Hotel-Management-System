#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

class Hotel{
    private:
        int roomNumber;
        string name;
        string address;
        string phone;
        char* roomType;
        int days;
        int cost;
        long pay;
        void breakfast(int);
        void lunch(int);
        void dinner(int);
    public:
        void menu();
        void add();
        void display() const;
        void rooms();
        void edit();
        int check(int);
        void modify();
        void deleteRecord();
        void restaurant();
        void updateName(int);
        void updateAddress(int);
        void updatePhone(int);
        void updateDays(int);
        void setRoomType(const string &type);
        Hotel();
        ~Hotel();
};

#endif