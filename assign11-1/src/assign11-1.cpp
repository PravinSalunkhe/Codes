/*

Problem Statement _ File handling In C++(Sequential file )
Write a program in C++ to implement sequential file for students' database
and perform following operations on it
i.Create
ii.Display
iii.Add
iv.Delete
v.Modify
*/

#include "file.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;



int main()
{
      fstream f;
       file obj,obj1;
      int ch;
      char str[20];

      do
      {
          cout<<"\n\nMENU\n1.Insert\n2.Display\n3.Search\n4.Edit\n5.Delete\n6.Create\n7.Exit\n\nEnter your choice  : \t";
          cin>>ch;
          switch(ch)
          {
              case 1:
                     obj.insert(1);

                      break;
              case 2: cout<<"Name           |Roll No |Subject     |Code    |Int. |Marks\n";
                      cout<<"----------------------------------------------------------------\n";
                      obj1.display();
                      cout<<"----------------------------------------------------------------\n";
                      break;
              case 3: cout<<"\nEnter Name of student to search:\t";
                      cin>>str;
                      obj1.search(str);
                      break;
              case 4: cout<<"\nEnter name of student to edit:\t";
                      cin>>str;
                      obj1.edit(str);
                      break;
              case 5: cout<<"\nEnter name to Delete:\t";
                      cin>>str;
                      obj1.delete1(str);
                      break;
              case 6: obj.create();
                      break;
              case 7: break;
              default: cout<<"\nInvalid option\n";
                       break;
           }
      }while(ch!=7);

}
