#include "classes.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void Hotel::menu(){
    int choice;
    while(choice != 6){
        system("clear");
        cout << "\t\t   Welcome to Hotel Management System" << endl;
        cout << "\t\t" << setfill('-') << setw(40) << "" << endl << endl;
        cout << "Press the numbers listed to choose an option:" << endl << endl;
        cout<< "1. Book A Room" << endl;
		cout<< "2. Customer Information" << endl;
		cout<< "3. Rooms Allotted" << endl;
		cout<< "4. Edit Customer Details" << endl;
		cout<< "5. Order Food from Restaurant" << endl;
		cout<< "6. Exit" << endl << endl;
		cout<< "Enter Your Choice: ";
		cin >> choice;
        switch(choice){
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                rooms();
                break;
            case 4:
                edit();
                break;
            case 5:
                restaurant();
                break;
            default:
                cout << "Invalid option! Available options are 1-6" << endl;
                cout << "Press any key to continue";
                cin.get();
        }
    }
}

void Hotel::add(){
    system("clear");
    
}