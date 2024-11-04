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
        string roomType;
        int days;
        int cost;
        long pay;
        void breakfast(int);
        void lunch(int);
        void dinner(int);
    public:
        void menu(); //complete
        void add(); //complete
        void display() const; //complete
        void rooms(); //complete
        void edit(); //complete
        int check(int); //complete
        void modify(); //complete
        void deleteRecord(); //complete
        void restaurant();
        void updateName(int);
        void updateAddress(int);
        void updatePhone(int);
        void updateDays(int);
        // Hotel();
};

#endif