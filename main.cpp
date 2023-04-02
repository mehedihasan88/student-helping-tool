#include<bits/stdc++.h>
#include "class_note.h"
#include "common.h"
#include "calculator.h"
using namespace std;
char date[100]="DD_MM_YYYY";
char name[100]="xxxxxx";
void welcome_menu()
{
    cout<<"Enter your name : "<<endl;
    cin.getline(name,sizeof(name));
    cout<<"--------------------------------------------"<<endl;
    cout<<"Hello ! "<<name<<"!"<<endl;
    cout<<"Welcome to Student Helping Tool application"<<endl;
    cout<<"--------------------------------------------"<<endl<<endl;

}
void menu()
{
    cout<<"-------------------------------"<<endl;
    cout<<"Enter 1 to start taking a note!"<<endl;
    cout<<"Enter 2 to view a previous note!"<<endl;
    cout<<"Enter 3 to use calculator!"<<endl;
    cout<<"Enter 4 to make a routine!"<<endl;
    cout<<"Enter 5 to view your routine!"<<endl;
    cout<<"Enter 6 to exit!"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter your choice : "<<endl;

}




int main()
{
    welcome_menu();
    int command;
        menu();
        cout<<"---------------------------------------"<<endl;
    while(cin>>command)
    {


        if(command==1)
        {
            class_note c;
            c.create();
            c.show_today();
        }
        else if(command==2)
        {
            class_note c;
            c.find();

        }
        else if(command==3)
        {
            calculator c;
            c.get_expression();
            c.show_solution();
        }
        menu();
        cout<<"---------------------------------------"<<endl;

    }




    return 0;
}
