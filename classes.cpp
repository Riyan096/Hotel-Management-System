#include "classes.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;


void Hotel::add(){
    system("clear");
    int room, flag;
    ofstream fout("Record.DAT",ios::app|ios::binary);
    cout<<"\n\t\t  Rooms  |   Room Type  " << endl;
    cout<<"\t\t -----------------------" << endl;
    cout<<"\t\t    1-50 |    Deluxe    " << endl;
    cout<<"\t\t   51-80 |   Executive  " << endl;
    cout<<"\t\t  81-100 | Presidential " << endl;
    cout<<"\t\t -----------------------" << endl << endl;
    cout << "Enter customer details" << endl;
    cout << setfill('~') << setw(23) << "" << endl << endl;
    cout << "Enter room number: ";
    cin >> room;
    while(true){
        if(room < 1 || room > 100){
            cout << "Invalid room number (1-100)" << endl;
            cout << "Enter room number: ";
            cin >> room;
        }
        else{break;}
    }
    flag = check(room);
    if(flag==1){
		cout<<"\n Sorry, Room is already booked.\n";
    }
	else{
	    if(flag==2){
	       cout<<"\n Sorry, Room does not exist.\n";
        }
        else{
            roomNumber = room;
            cout << "Enter customer's name: ";
            cin >> name;
            cout << "\nEnter customer's address: ";
            cin >> address;
            cout << "\nEnter customer's phone number: ";
            cin >> phone;
            cout << "\nEnter number of days customer will stay for: ";
            cin >> days;
            if (roomNumber >= 1 && roomNumber <= 50){
                roomType = "Deluxe";
                cost = days * 300;
            }
            else if (roomNumber > 50 && roomNumber <= 80){
                roomType = "Executive";
                cost = days * 500;
            }
            else if (roomNumber > 80 && roomNumber <= 100){
                roomType = "Presidential";
                cost = days * 700;
            }
        }
        fout.write((char*)this, sizeof(Hotel));
		cout<<"\n Room has been booked.";
    }
    cout<<"\n Press any key to continue.";
	getchar();
	getchar();
	fout.close();
}

int Hotel::check(int r)
{
	int flag=0;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	while(fin.read((char*)this,sizeof(Hotel)))
	{
		if(roomNumber==r)
		{
			flag=1;
			break;
		}
		else
		{
		  if(r>100)
		  {
			flag=2;
			break;
		  }
		}
	}
	fin.close();
	return(flag);
}

// void Hotel::menu(){
//     int choice = 0;
//     while(choice != 6){
//         system("clear");
//         cout << "\t\t   Welcome to Hotel Management System" << endl;
//         cout << "\t\t" << setfill('-') << setw(40) << "" << endl << endl;
//         cout << "Press the numbers listed to choose an option:" << endl << endl;
//         cout<< "1. Book A Room" << endl;
// 		cout<< "2. Customer Information" << endl;
// 		cout<< "3. Rooms Allotted" << endl;
// 		cout<< "4. Edit Customer Details" << endl;
// 		cout<< "5. Order Food from Restaurant" << endl;
// 		cout<< "6. Exit" << endl << endl;
// 		cout<< "Enter Your Choice: ";
// 		cin >> choice;
//         switch(choice){
//             case 1:
//                 add();
//                 break;
//             case 2:
//                 display();
//                 break;
//             case 3:
//                 rooms();
//                 break;
//             case 4:
//                 edit();
//                 break;
//             case 5:
//                 restaurant();
//                 break;
//             default:
//                 cout << "Invalid option! Available options are 1-6" << endl;
//                 cout << "Press any key to continue";
//                 cin.get();
//         }
//     }
// }

