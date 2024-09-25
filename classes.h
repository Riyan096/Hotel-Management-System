#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

class Hotel{
    private:
        int roomNumer;
        char *name;
        char *address;
        char *phone;
        long days;
        long cost;
        char rtype[30];
        long pay;
        void breakfast(int);
        void lunch(int);
        void dinner(int);
    public:
        void menu();
        void add();
        void display();
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
};

#endif