#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class contact{
    private:
        char fname[50], lname[50], address[50], email[50];
        long long phNo;
    public:
        void createContact(){
            cout<<"Enter your first name : ";
            cin>>fname;
            cout<<"Enter your last name : ";
            cin>>lname;
            cout<<"Enter Phone No : ";
            cin>>phNo;
            cout<<"Enter Address : ";
            cin>>address;
            cout<<"Enter mail ID : ";
            cin>>email;

        }
        void showContact(){
            cout<<"Name : "<<fname<<" "<<lname<<endl;
            cout<<"Phone Number : "<<phNo<<endl;
            cout<<"Address : "<<address<<endl;
            cout<<"Email : "<<email<<endl;
        }
        void writeOnFile(){
            char ch;
            ofstream f1;
            f1.open("CMS.dat",ios::binary | ios::app);
            do{
                createContact();
                f1.write(reinterpret_cast<char*>(this), sizeof(*this));
                cout<<"Do you have next data?(y/n) : ";
                cin>>ch;
            }while(ch=='y');

            cout<<"Contact has been sucessfully created.";
            f1.close();
        }
        void readFromFile(){
            ifstream f2;
            f2.open("CMS.dat", ios::binary);
            cout<<"\n---------------------------------------\n";
            cout<<"    LIST OF CONTACT"<<endl;
            cout<<"-----------------------------------------\n";

            while(!f2.eof()){
                if(f2.read(reinterpret_cast<char*>(this), sizeof(*this))){
                    showContact();
                    cout<<"\n--------------------------------\n";
                }  
            }
            f2.close();

        }
        void searchOnFile(){
            ifstream f3;
            long long phone;
            cout<<"Enter phone No : ";
            cin>>phone;
            f3.open("CMS.dat", ios::binary);
            while(!f3.eof()){
                if(f3.read(reinterpret_cast<char*>(this),sizeof(*this))){
                    if(phone==phNo){
                        showContact();
                        return;
                    }
                }
            }
            cout<<"\n NO RECORD FOUND\n";
            f3.close();
        }
        void deleteFromFile(){
            long long phone;
            int flag=0;
            ofstream f4;
            ifstream f5;
            f5.open("CMS.dat", ios::binary);
            f4.open("temp.dat", ios::binary);

            cout<<"Enter phone no. to delete : ";
            cin>>phone;
            while(!f5.eof()){
                if(f5.read(reinterpret_cast<char*>(this), sizeof(*this))){
                    if(phNo !=phone){
                        f4.write(reinterpret_cast<char*>(this), sizeof(*this));
                    }
                    else flag=1;
                }
            }
            f5.close();
            f4.close();
            remove("CMS.dat");
            rename("temp.dat", "CMS.dat");

            flag==1?
            cout<<"\tContact Deleted\n":
            cout<<"\tContact Not Found\n";  

        }
        void editContact(){
            long long phone;
            fstream f6;
            cout<<"Edit Contact";
            cout<<"\n-------------------------------\n";
            cout<<"Enter the phone number to be edited : ";
            cin>>phone;
            f6.open("CMS.dat", ios::binary|ios::out|ios::in);

            while(!f6.eof()){
                if(f6.read(reinterpret_cast<char*>(this), sizeof(*this))){
                    if(phone==phNo){
                        cout<<"Enter new record\n";
                        createContact();
                        int pos= -1*sizeof(*this);
                        f6.seekp(pos, ios::cur);
                        f6.write(reinterpret_cast<char*>(this), sizeof(*this));
                        cout<<endl<<"\tContact Successfully Updated.";
                        return;

                    }
                }
            }
            cout<<"\nNO RECORD FOUND";
            f6.close();
        }
};
int main(){
    system("cls");
    system("Color 3F");//color XY, X= background color, Y= text color

    cout<<"\n\n\n\t**WELCOME TO THE CONTACT MANAGEMENT SYSTEM**";
    getch();
    while(1){
        contact c1;
        int choice;
        system("cls");
        system("Color 03");

        cout<<"\nCONTACT MANAGEMENT SYSTEM";
        cout<<"\n MAIN MENU";
        cout<<"\n-----------------------------------------\n";
        cout<<"1. Add a new Contact\n";
        cout<<"2. List all Contacts\n";
        cout<<"3. Search all contacts\n";
        cout<<"4. Delete a Contact\n";
        cout<<"5. Edit a Contact\n";
        cout<<"0. EXIT";
        cout<<"\n------------------------------------------\n";
        cout<<"Enter your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            system("cls");
            c1.writeOnFile();
            break;

            case 2:
            system("cls");
            c1.readFromFile();
            break;

            case 3:
            system("cls");
            c1.searchOnFile();
            break;

            case 4:
            system("cls");
            c1.deleteFromFile();
            break;

            case 5:
            system("cls");
            c1.editContact();
            break;

            case 0:
            system("cls");
            cout<<"\n\n \tTHANKYOU!!"<<endl;
            exit(0);
            break;

            default:
            continue;
        }

        int option;
        cout<<"\n\n Enter the choice:\n 1. Main Menu\t\t 2. Exit\n ";
        cin>>option;
        switch(option){
            case 2:
            system("cls");
            cout<<"\n\n\t THANKYOU!!"<<endl;
            exit(0);
            break;

            default:
            continue;

        }


    }
}