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

int Hotel::check(int roomNum)
{
	int flag=0;
	ifstream file("Record.DAT",ios::in|ios::binary);
	while(file.read((char*)this,sizeof(Hotel)))
	{
		if(roomNumber == roomNum)
		{
			flag=1;
			break;
		}
		else
		{
		  if(roomNum > 100)
		  {
			flag=2;
			break;
		  }
		}
	}
	file.close();
	return(flag);
}

void Hotel::display() const{
    system("clear");
    ifstream file("Record.DAT",ios::in|ios::binary);
    int roomNum, flag;
    cout << "Enter the Room Number: ";
    cin >> roomNum;
    while(file.read((char*)this,sizeof(Hotel))){
        if(roomNumber == roomNum){
            system("clear");
            cout << "\t\tCustomer Details" << endl;
            cout << "\t\t" << setfill('-') << setw(25) << "" << endl << endl;
            cout << "Room Number: " << roomNumber << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone Number: " << phone << endl;
            cout << "Staying for: " << days << " days" << endl;
            cout << "Room Type: " << roomType << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "\nThe specified room is vacant" << endl;
    }
    file.close();
    cout<<"\n\n Press any key to continue.";
	getchar();
	getchar();
}

void Hotel::rooms(){
    system("clear");
    ifstream file("Record.DAT",ios::in|ios::binary);
    cout<<"\n\t\t\t    LIST OF ROOMS ALLOTED";
	cout<<"\n\t\t\t   -----------------------";
	cout<<"\n\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n | Room No.|    Guest Name    |      Address    |   Room Type  |  Contact No. |";
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
    while(file.read((char*)this,sizeof(Hotel))){
        cout << "\n| " << setfill(' ') << setw(8) << roomNumber;
        cout << " | " << setfill(' ') << setw(15) << name;
        cout << " | " << setfill(' ') << setw(15) << address;
        cout << " | " << setfill(' ') << setw(10) << roomType;
        cout << " | " << setfill(' ') << setw(10) << phone;
    }
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";
    file.close();
    cout<<"\n\n Press any key to continue.";
    getchar();
    getchar();
}

void Hotel::edit(){
    system("clear");
    int choice;
    cout<<"\n\t\t\t    EDIT MENU";
    cout<<"\n\t\t\t   -----------------------";
    cout<<"\n\n 1. Edit Customer Information.";
    cout<<"\n 2. Customer Check Out.";
    cout<<"\n 3. Back to Main Menu.";
    /*Possible room for more functions*/
    cout<<"\n\n Enter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            modify();
            break;
        case 2:
            deleteRecord();
            break;
        case 3:
            menu();
            break;
        default:
            cout << "\nInvalid Choice!";
            break;
    }
    cout<<"\n\n Press any key to continue.";
    getchar();
    getchar();
}

void Hotel::modify(){
    system("clear");
    int roomNum, choice;
    cout << "\n\t\tCUSTOMER INFORMATION EDIT MENU";
    cout << "\n\t\t-------------------------------";
    cout << "\n\n Enter the room number of the customer you want to edit: ";
    cin >> roomNum;
    system("clear");
    cout << "\n 1. Edit Name";
    cout << "\n 2. Edit Address";
    cout << "\n 3. Edit Phone Number";
    cout << "\n 4. Edit Number of Days Customer Has Stayed";
    cout << "\n 5. Back to Edit Menu";
    cout << "\n\n Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            updateName(roomNum);
            break;
        case 2:
            updateAddress(roomNum);
            break;
        case 3:
            updatePhone(roomNum);
            break;
        case 4:
            updateDays(roomNum);
            break;
        case 5:
            edit();
            break;
        default:
            cout << "\nInvalid Choice!";
            getchar(); //test what this does, remove if not needed
            getchar();
            break;
    }
}

void Hotel::deleteRecord(){
    system("clear");
    int roomNum, flag;
    char choice;
    cout << "\n Enter the Room Number: ";
    cin >> roomNum;
    system("clear");
    ifstream file_in("Record.DAT", ios::in|ios::binary);
    ofstream file_out("temp.DAT", ios::out|ios::binary);
    while(file_in.read((char*)this, sizeof(Hotel))){
        if(roomNumber = roomNum){
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone Number: " << phone;
            cout << "\n Number of Days Customer Has Stayed: " << days;
            cout << "\n Your total bill is: $" << cost;
            cout << "\n\n Would you like to check out this customer? (Enter Y for yes, N for no): ";
            cin >> choice;
            if(choice == 'y' || choice == 'Y'){ //could use a validation check
                cout << "\n Customer checked out.";
                flag = 1;
            }
            else if(choice == 'n' || choice == 'N'){
                file_out.write((char*)this, sizeof(Hotel));
                cout << "\n Customer not checked out.";
            }
        }
        else{
            file_out.write((char*)this, sizeof(Hotel));
        }
    }
    file_in.close();
    file_out.close();
    if(flag==0){
        cout << "\nThe room is currently vacant.";
    }
    remove("Record.DAT");
    rename("temp.DAT", "Record.DAT");
    cout<<"\n\n Press any key to continue.";
    getchar();
    getchar();   
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

