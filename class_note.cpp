#include<bits/stdc++.h>
#include "class_note.h"
#include "common.h"
using namespace std;



class_note::class_note()
{
    file_name[0]='\0';
}
void class_note::create()
{
    getchar();
    cout<<"-Enter subject name : "<<endl;
    cin.getline(subject_name,sizeof(subject_name));
    cout<<"Enter today's date : (DD-MM-YYYY)"<<endl;
    cin.getline(date,sizeof(date));


    strcat(strcat(strcat(strcat(file_name,date),"_"),subject_name),".txt");


    ofstream file;
    file.open(file_name);
    if(file.is_open())
    {
        cout<<"-------------------------------------"<<endl;
        cout<<"Start writing from here : (Enter ctrl+Z to finish)"<<endl;
        cout<<"-------------------------------------"<<endl;


        file<<"_____________________________________________________"<<endl;
        file<<"\t\t\t"<<subject_name<<" class note"<<endl;
        file<<"\t\t\t"<<date<<endl;
        file<<"\t\t\t"<<"----------"<<endl;
        while(cin.getline(note_line,sizeof(note_line)))
        {
            file<<note_line<<"\n";
        }
        file<<"_____________________________________________________"<<endl;


    }
    else
    {
        cout<<"Error creating file!!!\n"<<"Please try again\n"<<endl;
    }
    file.close();
}

void class_note::show_today()
{
    if(strlen(file_name)!=0)
    {
        ifstream file(file_name);
        while(!file.eof())
        {
            file.get(read_char);

            cout<<read_char;
        }
        file.close();

    }

}
void class_note::find()
{
    getchar();
    cout<<"--Enter subject name : "<<endl;
    cin.getline(subject_name,sizeof(subject_name));
    cout<<"Enter date : (Format : DD-MM-YYYY)"<<endl;
    cin.getline(date,sizeof(date));
    strcat(strcat(strcat(strcat(file_name,date),"_"),subject_name),".txt");

    if(strlen(file_name)!=0)
    {
        ifstream file(file_name);
        if(file.is_open())
        {
        while(!file.eof())
        {
            file.get(read_char);

            cout<<read_char;
        }
        file.close();

        }
        else
        {
            cout<<"Error opening file or file not found!!!\n"<<endl;

        }

    }


}
