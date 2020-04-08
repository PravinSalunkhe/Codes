//============================================================================
// Name        : assign11.cpp
// Author      : PRAVIN SALUNKHE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
SE-10
G-10
23257
PROBLEM STATEMENT:-
Write a program in C++ to implement sequential file for students' database
and perform following operations on it
i.Create
ii.Display
iii.Add
iv.Delete
v.Modify
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;
class student
{
	private:
		int rollno;
		char name[20];
		int marks;
		int sub_code;
	public:
		void create(int n);
		void display();
		void add();
		int search(int a);
		int modify(int a);
		void deletion(int a);

};
void student :: create(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER THE NAME OF THE STUDENT:-";
		cin.ignore();
		cin.getline(name,20);
		cout<<"ENTER THE ROLL NO OF THE STUDENT:-";
		cin>>rollno;
		cout<<"ENTER THE SUBJECT CODE:-";
		cin>>sub_code;
		cout<<"ENTER THE MARKS:-";
		cin>>marks;
		ofstream file;
		file.open("student.txt",ios::app | ios::out );
		file.write((char*)this,sizeof(student));
		file.close();
	}
}
void student :: display()
{
	cout<<"\n"<<setw(11)<<setiosflags(ios::left)<<"|ROLL NO."<<setw(16)<<"|NAME"<<setw(16)<<"|SUBJECT CODE"<<setw(11)<<"|MARKS"<<endl;
	ifstream file;
	file.open("student.txt",ios::in );
	while(file.read((char*)this,sizeof(student)))
	{
		cout<<"\n|"<<setw(10)<<rollno<<"|"<<setw(15)<<name<<"|"<<setw(15)<<sub_code<<"|"<<setw(10)<<marks;
	}
	file.close();
}
void student :: add()
{
	ofstream file;
	file.open("student.txt",ios::out | ios::app);
	cout<<"ENTER THE NAME OF THE STUDENT:-";
	cin.ignore();
	cin.getline(name,20);
	cout<<"ENTER THE ROLL NO OF THE STUDENT:-";
	cin>>rollno;
	cout<<"ENTER THE SUBJECT CODE";
	cin>>sub_code;
	cout<<"ENTER THE MARKS";
	cin>>marks;
	file.write((char*)this,sizeof(student));
	file.close();
}
int student :: search(int a)
{
	ifstream f;
	f.open("student.txt",ios :: in);
	f.seekg(0,ios::beg);
	while(f.read((char*)this,sizeof(student)))
	{
		if(this->rollno==a)
		{
			cout<<"RECORD FOUND\nRECORD DETAILS ARE:-\n";
			cout<<"NAME:-"<<this->name<<"\n";
			cout<<"SUBJECT CODE:-"<<this->sub_code<<"\n";
			cout<<"MARKS:-"<<this->marks<<"\n";
			f.close();
			return (1);
		}
	}
f.close();
return 0;
}

int student :: modify(int a)
{
	fstream f1;
	int loc;
	f1.open("student.txt",ios :: in | ios :: out);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)this,sizeof(student)))
	{
		if(this->rollno==a)
		{
			loc=f1.tellg();
			f1.seekg(loc-sizeof(student));
			cout<<"ENTER THE NEW NAME OF THE STUDENT:-";
			cin.ignore();
			cin.getline(name,20);
			cout<<"ENTER THE NEW ROLL NO OF THE STUDENT:-";
			cin>>rollno;
			cout<<"ENTER THE NEW SUBJECT CODE";
			cin>>sub_code;
			cout<<"ENTER THE NEW MARKS";
			cin>>marks;
			f1.write((char*)this,sizeof(student));
			f1.close();
			return (1);
		}
	}
	f1.close();
	return 0;
}

void student :: deletion(int a)
{
	fstream f2;
	fstream temp;
	//student s;
	f2.open("student.txt",ios :: in);
	temp.open("2.txt",ios :: out);
	while(f2.read((char*)this,sizeof(student)))
	{
		if(this->rollno!=a)
		{
	 		/*s.rollno=this->rollno;
	 		strcpy(s.name,this->name);
	 		s.sub_code=this->sub_code;
	 		s.marks=this->marks;*/
	 		temp.write((char*)this,sizeof(student));
	 	}
	}
	f2.close();
	temp.close();
	temp.open("2.txt",ios :: in);
	f2.open("student.txt",ios ::out);
	temp.seekg(0,ios::beg);
	while(temp.read((char*)this,sizeof(student)))
	{
		/*this->rollno=s.rollno;
		strcpy(this->name,s.name);
		this->sub_code=s.sub_code;
		this->marks=s.marks;*/
		f2.write((char*)this,sizeof(student));
	}
	f2.close();
	temp.close();
	cout<<"\nREQUESTED RECORD DELETED SUCCESSFULLY";
}



int main()
{
	int ch,a,flag,n;
	student s;
	cout<<"FILE OPERATIONS";
	do
	{
		cout<<"\nMENU\n\n1.CREATE\n2.DISPLAY\n3.ADD\n4.SEARCH\n5.MODIFY\n6.DELETE\n7.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the no of students:-";
				cin>>n;
				s.create(n);
				break;
			case 2:
				s.display();
				break;
			case 3:
				s.add();
				break;
			case 4:
				cout<<"ENTER THE ROLL NO OF THE STUDENT TO BE SEARCHED:-";
				cin>>a;
				flag=s.search(a);
				if(flag==0)
				{
					cout<<"RECORD NOT FOUND";
				}
				break;
			case 5:
				cout<<"ENTER THE ROLL NO OF THE STUDENT WHOSE DETAILS ARE TO BE MODIFIED:-";
				cin>>a;
				flag=s.modify(a);
				if(flag==0)
				{
					cout<<"RECORD NOT FOUND";
				}
				break;
			case 6:
				cout<<"ENTER THE ROLL NO OF THE STUDENT WHOSE DETAILS ARE TO BE DELETED:-";
				cin>>a;
				flag=s.search(a);
				if(flag==0)
				{
					cout<<"RECORD NOT FOUND";
				}
				else
				{
					s.deletion(a);
				}
				break;


		}
	}while(ch!=7);
}
