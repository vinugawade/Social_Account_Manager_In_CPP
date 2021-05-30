#include <iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define psw 3020
using namespace std;

class title
{
public:
    char ititle[50];
public:
    void get_title()
    {
        cout<<"\nEnter Account Name:\n";
        cin>>ititle;
    }
};

class username:virtual public title
{
public:
    char iusername[50];
public:
    void get_username()
    {
        cout<<"\nEnter Username:\n";
        cin>>iusername;
    }
};

class password:virtual public title
{
public:
    char ipassword[50];
public:
    void get_password()
    {
        cout<<"\nEnter Password:\n";
        cin>>ipassword;
    }
};

class write:public username,public password
{
public:
    void write_data()
    {
        fstream in("Data",ios::out|ios::app);
        if(in.is_open())
        {
            in<<"\n\t\t"<<ititle;
            in<<"\n"<<"Username :"<<iusername;
            in<<"\n"<<"Password :"<<ipassword<<"\n";
            in.close();
        }
        else
        {
            cout<<"\nUnable To Open File.....\n";
        }
    }
    friend void show_data();
};

void show_data()
{
    system("cls");
    std::string line;
    ifstream out("Data");
    if(out.is_open())
    {
        while(getline(out,line))
        {
            std::cout<<line<<"\n";
        }
        out.close();
    }
    else
    {
        cout<<"\nUnable To Open File.....\n";
    }
}
int main()
{
    int c,p;
    write w;
    cout<<"*********************************\n";
    cout<<"\t  MAIN MENU\n";
    cout<<"*********************************\n";
    cout<<"1.Admin Login\n2.Save Data\n3.Exit\n";
    cout<<"\n*********************************\n";
    cout<<"\nEnter Your Choice :\n";
    cin>>c;
    switch(c)
    {
    case 1:
        cout<<"\nEnter Your Password :\n";
        cin>>p;
        if(p==psw)
        {
            show_data();
            cout<<"\nPress Any Key To Main Menu....\n";
            getchar();
            getchar();
            main();
        }
        else
        {
            cout<<"\nIncorrect Password....\n";
            main();
        }
        break;

    case 2:
    w.get_title();
    w.get_username();
    w.get_password();
    w.write_data();
    cout<<"\nYour Data Get Successfully Saved.........\n";
    main();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout<<"\nInvalid Input....\n";
        main();
    }

    return 0;
}

/***************************************************************************/
/*
            Social Account Manager System
         Micro-Project Of Vinay Gawade
                Year 2019-2020

*/
/***************************************************************************/