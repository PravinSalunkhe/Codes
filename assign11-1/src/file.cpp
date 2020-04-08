/*
 * file.cpp
 *
 *  Created on: 07-Apr-2019
 *      Author: akshay
 */

#include "file.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

void file::create()
{
    int n;
    cout<<"\n\nHow many records are there ??\t";
    cin>>n;
    int i;
    cout<<"\nEnter 1st record\n\n";
    insert(0);
    for(i=1;i<n;i++)
    {
        cout<<"\n\nEnter "<<i+1<<" th record\n\n";
        insert(1);
    }
}

void file::insert(int flag)
{
     ofstream fout;
     if(flag==1)
     fout.open("Record.txt",ios::app);
     else
     fout.open("Record.txt");

     cout<<"Enter name : \t";
     cin.ignore();
     cin.getline(name,29);
    fout<<name;
    fout<<" ";
     cout<<"Enter roll number : \t";
     cin>>roll;
     fout<<roll;
     fout<<" ";
     cout<<"Enter subject : \t";
     cin.ignore();
    cin.getline(subject,19);

     fout<<subject;
     fout<<" ";
     cout<<"Enter subject code : \t";
     cin>>code;
     fout<<code;
     fout<<" ";
     cout<<"Enter internal assesment : \t";
     cin>>internal;
     fout<<internal;
     fout<<" ";
     cout<<"Enter university marks : \t";
     cin>>marks;
     fout<<marks;
     fout<<" ";
     fout.close();
}
void file::display()
{
     ifstream fin;
     char ch;
     fin.open("Record.txt",ios::app);

     fin.seekg(0,ios::beg);
     while(!fin.eof())
     {
   //  fin.getline(name,strlen(name)+1);
     fin>>name;
     fin>>roll;
     fin>>subject;
     fin>>code>>internal>>marks;
     if(fin.eof())
       break;
     cout<<std::left<<setw(15)<<name<<"|"<<setw(8)<<roll<<"|"<<setw(12)<<subject<<"|"<<setw(8)<<code<<"|"<<setw(5)<<internal<<"|"<<setw(5)<<marks<<endl;

     }
     fin.close();
}

void file::search(char str[])
{
     ifstream fin;
     char ch;
     fin.open("Record.txt",ios::app);

     fin.seekg(0,ios::beg);
     while(!fin.eof())
     {
   //  fin.getline(name,strlen(name)+1);
     fin>>name;
     fin>>roll;
     fin>>subject;
     fin>>code>>internal>>marks;
     if(strcmp(name,str)==0)
     {
         cout<<"\nFound\n";
         cout<<"\n\nDetail of required record\n\n";
         cout<<"Name           |Roll No |Subject     |Code    |Int. |Marks\n";
         cout<<"----------------------------------------------------------------\n";
         cout<<std::left<<setw(15)<<name<<"|"<<setw(8)<<roll<<"|"<<setw(12)<<subject<<"|"<<setw(8)<<code<<"|"<<setw(5)<<internal<<"|"<<setw(5)<<marks<<endl;
         cout<<"----------------------------------------------------------------\n";
         break;
     }
     if(fin.eof())
       break;
     }
     fin.close();
}
void file::edit(char str[])
{
     fstream fout,temp;
     char ch;
     fout.open("Record.txt",ios::app | ios::in);
     temp.open("temp.txt",ios::out);
     fout.seekg(0,ios::beg);

     while(!fout.eof())
     {
        fout>>name;
        fout>>roll;
        fout>>subject;
        fout>>code>>internal>>marks;
        if(fout.eof())
          break;
        temp<<name<<" "<<roll<<" "<<subject<<" "<<code<<" "<<internal<<" "<<marks<<" ";


     }
     temp.close();
     temp.open("temp.txt",ios::app | ios::in);
     temp.seekg(0,ios::beg);
     fout.close();
     fout.open("Record.txt",ios::out);
     while(!temp.eof())
     {
   //  fin.getline(name,strlen(name)+1);
     temp>>name;
            if(temp.eof())
          break;
     fout<<name<<" ";


     if(strcmp(name,str)==0)
     {
          cout<<"Enter roll number : \t";
     cin>>roll;
     fout<<roll;
     fout<<" ";
     cout<<"Enter subject : \t";
     cin.ignore();
    cin.getline(subject,19);

     fout<<subject;
     fout<<" ";
     cout<<"Enter subject code : \t";
     cin>>code;
     fout<<code;
     fout<<" ";
     cout<<"Enter internal assesment : \t";
     cin>>internal;
     fout<<internal;
     fout<<" ";
     cout<<"Enter university marks : \t";
     cin>>marks;
     fout<<marks;
     fout<<" ";
     temp>>roll;
           temp>>subject;
           temp>>code>>internal>>marks;
      }
      else
      {

           temp>>roll;
           temp>>subject;
           temp>>code>>internal>>marks;
           if(temp.eof())
              break;
           fout<<roll<<" "<<subject<<" "<<code<<" "<<internal<<" "<<marks<<" ";
       }
     }
     fout.close();
     temp.close();
}
void file::delete1(char str[])
{
     fstream fout,temp;
     char ch;
     fout.open("Record.txt",ios::app | ios::in);
     temp.open("temp.txt",ios::out);
     fout.seekg(0,ios::beg);

     while(1)
     {
        fout>>name;
        fout>>roll;
        fout>>subject;
        fout>>code>>internal>>marks;
        if(fout.eof())
          break;
        temp<<name<<" "<<roll<<" "<<subject<<" "<<code<<" "<<internal<<" "<<marks<<" ";


     }
     temp.close();
     temp.open("temp.txt",ios::app | ios::in);
     temp.seekg(0,ios::beg);
     fout.close();
     fout.open("Record.txt",ios::out);
     fout.seekg(0,ios::beg);
     while(!temp.eof())
     {
   //  fin.getline(name,strlen(name)+1);
     temp>>name;
            if(temp.eof())
          break;


      if(strcmp(name,str))
      {

           temp>>roll;
           temp>>subject;
           temp>>code>>internal>>marks;
           if(temp.eof())
              break;
           fout<<name<<" ";

           fout<<roll<<" "<<subject<<" "<<code<<" "<<internal<<" "<<marks<<" ";
       }
       else
       {
         temp>>roll;
           temp>>subject;
           temp>>code>>internal>>marks;
       }
     }
     fout.close();
     temp.close();
}
