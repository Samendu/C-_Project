#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
using namespace std;
class hotel
{
int room_no;
char name[30];
char address[50];
char phone[10];
public:
void main_menu();		//to dispay the main menu
void add();			//to book a room
void display(); 		//to display the customer record
int check(int);			//to check room status
     };
void hotel::main_menu()
{
int choice;
while(choice!=5)
{
system("cls");
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*****";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Records";
cout<<"\n\t\t\t3.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;
switch(choice)
{
case 1:	
add();
break;
case 2: 
display();
break;
case 3:
exit(-1);
break;
}
}
}
void hotel::add()
{
system("cls");
int r,flag;
ofstream fout("Record.txt",ios::app);
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;
flag=check(r);
if(flag)
cout<<"\n Sorry..!!!Room is already booked";
else
{
room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";
}
cout<<"\n Press any key to continue.....!!";
getch();
fout.close();
}
void hotel::display()
{
system("cls");

ifstream fin("Record.txt",ios::in);
int r,flag;
cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;
}
}
if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";
getch();
fin.close();
}
int hotel::check(int r)
{
int flag=0;
ifstream fin("Record.txt",ios::in);
while(!fin.eof())
{
fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{
flag=1;
break;
}
}
fin.close();
return(flag);
}
int main()
{

hotel h;

  system("cls");
char admin[10];
char pass[10];
    cout<<"Enter your username"<<endl;
    cin>>admin;
    cout<<"Enter your password"<<endl;
    cin>>pass;
    if(strcmp(admin,"admin")==0&&strcmp(pass,"password")==0){
        cout<<"Login Successful"<<endl;
    _sleep(2)
    }
    else{
        cout<<"Invalid Details"<<endl;
        exit(-1);
    }

getch();

h.main_menu();
return 0;
}