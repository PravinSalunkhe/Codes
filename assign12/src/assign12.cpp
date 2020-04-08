
/* G-10
 * 23257
 * PROBLEM STATEMENT:- IMPLEMENT DIRECT ACCESS FILE USING HASHING (CHAINING WITHOUT REPLACEMENT) ANDPERFORM FOLLOWING OPERATIONS.
 * 1.CREATE
 * 2.INSERT
 * 3.SEARCH
 * 4.DELETE
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
struct data			//struct for data
{
	char name[50]="EMPTY";
	int roll=-1;
	int id;
	int chain=-1;
};
class hash_table		//class declaration
{
		data t;
public:
		void create();
		void insert(int no,char name1[50]);
		int search(int myno);
		int func(int roll);
		void delete_rec();
		void display();
		void display1(int i);
		void deletekey(int no);
};
int hash_table ::func(int roll)		//hash function
{
	int key=roll%10;		//find key
	return key;
}
void hash_table :: create()		//create hash table
{
	fstream file;
	file.open("database.txt", ios ::out);	//open in write mode
	for(int i=0;i<10;i++)
	{
		t.id=i;
		file.write((char*)&t,sizeof(hash_table));
	}
	file.close();
}
void hash_table :: display()		//display hash file
{
	cout<<"\n"<<setw(11)<<setiosflags(ios::left)<<"|INDEX"<<setw(11)<<setiosflags(ios::left)<<"|ROLL NO."<<setw(16)<<"|NAME"<<setw(16)<<"|CHAIN"<<endl;
	ifstream file;
	file.open("database.txt",ios::in );		//open in read mode
	while(file.read((char*)this,sizeof(hash_table)))
	{
		cout<<"\n|"<<setw(11)<<this->t.id<<setw(10)<<this->t.roll<<"|"<<setw(15)<<this->t.name<<"|"<<setw(15)<<this->t.chain;
	}
	file.close();
}
void hash_table :: insert(int no,char name1[50])	//insert record
{
	fstream file;
	int loc,i,temp=-1;
	data d;
	int key=func(no);
	d.id=key;
	strcpy(d.name,name1);
	d.roll=no;
	d.chain=-1;

	file.open("database.txt",ios ::out |ios ::in);	//open in write or read mode
	file.seekg(key*sizeof(hash_table));			//go to desired index using seekg
	file.read((char*)this,sizeof(hash_table));	//read from file
	if(this->t.roll==-1)
	{
		loc=file.tellg();
		file.seekg(loc-sizeof(hash_table),ios :: beg);
		file.seekp(loc-sizeof(hash_table));			//write in file
		file.write((char*)&d,sizeof(hash_table));
		file.close();
		return;
	}
	else
	{
		if(this->t.chain==-1)		//if chain is -1
		{
			i=(key+1)%10;
			file.seekg(i*sizeof(hash_table),ios ::beg);
			file.read((char*)this,sizeof(hash_table));
		}
		else						//if chain is not -1
		{
			i=key;
			while(this->t.chain!=-1)		//traverse till chain not -1
			{
				i=this->t.chain;
				file.seekg(i*sizeof(hash_table),ios ::beg);
				file.read((char*)this,sizeof(hash_table));
			}
			if(this->t.chain==-1)
			{
				temp=i;
			}
		}
		while(this->t.roll!=-1 && i!=key)		//for finding empty space
		{
			i=(i+1)%10;
			file.seekg(i*sizeof(hash_table),ios ::beg);
			file.read((char*)this,sizeof(hash_table));
		}
		if(this->t.roll==-1)
					{
						d.roll=no;
						strcpy(d.name,name1);
						d.chain=-1;
						if(temp!=-1)
						{
							file.seekg(temp*sizeof(hash_table),ios ::beg);
							file.read((char*)this,sizeof(hash_table));
							this->t.chain=i;
							file.seekp(temp*sizeof(hash_table),ios ::beg);
							file.write((char*)&t,sizeof(hash_table));
						}
						else
						{
							file.seekg(key*sizeof(hash_table),ios ::beg);
							file.read((char*)this,sizeof(hash_table));
							if(key==func(this->t.roll))
								this->t.chain=i;
							file.seekp(key*sizeof(hash_table),ios ::beg);
							file.write((char*)&t,sizeof(hash_table));
						}
						d.id=i;
						file.seekg(i*sizeof(hash_table),ios ::beg);
						file.seekp(i*sizeof(hash_table),ios ::beg);
						file.write((char*)&d,sizeof(hash_table));
						return;
					}
					if(i==key)		//hash file is full
					{
						cout<<"\nHASH TABLE(FILE) IS FULL\nNO CHANGE MADE\n";
						return;
					}

	}
}
int hash_table :: search(int myno)		//for search
{
	fstream file;
	int i;
	int key=func(myno);
	file.open("database.txt",ios ::out |ios ::in);	//open in write or read mode
	file.seekg(key*sizeof(hash_table),ios :: beg);
	file.read((char*)this,sizeof(hash_table));
	if(this->t.roll==myno)
		return key;
	else
	{
		if(this->t.chain==-1)
		{
			return -1;
		}
		else
		{
			i=key;
			while(this->t.chain!=-1)
			{
				i=this->t.chain;
				file.seekg(i*sizeof(hash_table),ios ::beg);
				file.read((char*)this,sizeof(hash_table));
				if(this->t.roll==myno)
					return i;
			}
			return -1;
		}
	}
}
void hash_table :: display1(int i)
{
	fstream file;
	file.open("database.txt",ios ::out |ios ::in);
	file.seekg(0);
	file.seekg(i*sizeof(hash_table),ios :: beg);
	file.read((char*)this,sizeof(hash_table));
	cout<<"\nID:: "<<this->t.id;
	cout<<"\nNAME:: "<<this->t.name;
	cout<<"\nROLL NO:: "<<this->t.roll;
	cout<<"\nCHAIN:: "<<this->t.chain<<"\n";
}
void hash_table :: deletekey(int no)
{
	int key=func(no);
	int temp,i,j;
	data d;
	fstream file;
	file.open("database.txt",ios ::out |ios ::in);		//open in write or read mode
	file.seekg(0);
	file.seekg(key*sizeof(hash_table));
	file.read((char*)this,sizeof(hash_table));

	if(this->t.roll==no)		//if found at correct location
	{
		this->t.roll=-1;
		strcpy(this->t.name,"EMPTY");
		if(this->t.chain!=-1)
		{
			temp=key;
			file.seekg(temp*sizeof(hash_table));
			file.read((char*)this,sizeof(hash_table));
			while(this->t.chain!=-1)
			{
				int m=this->t.chain;
				file.seekg(m*sizeof(hash_table));
				file.read((char*)this,sizeof(hash_table));
				d=this->t;
				file.seekg(temp*sizeof(hash_table));
				file.read((char*)this,sizeof(hash_table));

				this->t.roll=d.roll;
				strcpy(this->t.name,d.name);
				file.seekp(temp*sizeof(hash_table),ios ::beg);
				file.write((char*)&t,sizeof(hash_table));
				if(d.chain==-1)
				{
					j=this->t.chain;
					this->t.chain=-1;
					break;
				}
				temp=this->t.chain;
				file.seekg(temp*sizeof(hash_table),ios ::beg);
				file.read((char*)this,sizeof(hash_table));
			}
			file.seekp(temp*sizeof(hash_table),ios ::beg);
			file.write((char*)&t,sizeof(hash_table));

			file.seekg(j*sizeof(hash_table),ios ::beg);
			file.read((char*)this,sizeof(hash_table));
			this->t.roll=-1;
			this->t.chain=-1;
			strcpy(this->t.name,"EMPTY");
			file.seekp(j*sizeof(hash_table),ios ::beg);
			file.write((char*)&t,sizeof(hash_table));
		}
		else
		{
			this->t.chain=-1;
			file.seekp(key*sizeof(hash_table),ios ::beg);
			file.write((char*)&t,sizeof(hash_table));
		}
		cout<<"\nRECORD DELETED SUCCESSFULLY";
		return;
	}
	else
	{
		if(this->t.chain==-1)
		{
			temp=(key+1)%10;
			file.seekg(temp*sizeof(hash_table),ios ::beg);
			file.read((char*)&t,sizeof(hash_table));
			while(no!=this->t.roll && temp!=key)
			{
				temp=(temp+1)%10;
				file.seekg(temp*sizeof(hash_table),ios ::beg);
				file.read((char*)this,sizeof(hash_table));
			}
				if(no==this->t.roll)
				{
					this->t.roll=-1;
					strcpy(this->t.name,"EMPTY");
					this->t.chain=-1;
					file.seekp(temp*sizeof(hash_table),ios ::beg);
					file.write((char*)&t,sizeof(hash_table));
					cout<<"\nRECORD DELETED SUCCESSFULLY";
					return;
				}
				if(temp==key)
				{
					cout<<"\nRECORD NOT FOUND";
					return;
				}
		}
		else
		{
			temp=key;i=0;
			file.seekg(temp*sizeof(hash_table),ios ::beg);
			file.read((char*)this,sizeof(hash_table));
			while(temp!=-1 && no!=this->t.roll)
			{
				i=temp;
				temp=this->t.chain;
				file.seekg(temp*sizeof(hash_table),ios ::beg);
				file.read((char*)this,sizeof(hash_table));
			}
			if(no==this->t.roll)
			{
				int n=this->t.chain;
				if(this->t.chain!=-1)
				{
					file.seekg(i*sizeof(hash_table),ios ::beg);
					file.read((char*)this,sizeof(hash_table));
					this->t.chain=n;
				}
				else
				{
					file.seekg(i*sizeof(hash_table),ios ::beg);
					file.read((char*)this,sizeof(hash_table));
					this->t.chain=-1;
				}
				file.seekp(i*sizeof(hash_table),ios ::beg);
				file.write((char*)&t,sizeof(hash_table));

				file.seekg(temp*sizeof(hash_table),ios ::beg);
				file.read((char*)this,sizeof(hash_table));
				this->t.chain=-1;
				this->t.roll=-1;
				strcpy(this->t.name,"EMPTY");
				file.seekp(temp*sizeof(hash_table),ios ::beg);
				file.write((char*)&t,sizeof(hash_table));
				cout<<"\nRECORD DELETED SUCCESSFULLY";
				return;
			}
			else
			{
				cout<<"\nRECORD NOT FOUND";
				return;
			}
		}
	}
}
int main()
{
		hash_table h;		//object of class
		int ch,a;
		char name[50];
		int no;
	do
	{
		cout<<"\n-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------\nMENU\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.SEARCH\n5.DELETE\n6.EXIT\nENTER UR CHOICE::";
		cin>>ch;
		switch(ch)
		{
		case 1:
				h.create();		//call create
				h.display();
				break;
		case 2:
				h.display();
				break;
		case 3:
				cout<<"\nENTER THE ROLL NO.";
				cin>>no;
				cout<<"\nENTER THE NAME::";
				cin>>name;
				h.insert(no,name);	///open in write mode/call insert
				h.display();
				break;
		case 4:
				cout<<"\nENTER THE ROLL NO OF THE RECORD TO BE SEARCHED:-";
				cin>>no;
				a=h.search(no);		//call search
				if(a!=-1)
				{
					cout<<"\nRECORD FOUND\n";
					cout<<"-----RECORD DETAILS-----";
					h.display1(a);
				}

				else
					cout<<"\nRECORD NOT FOUND";

				break;
		case 5:
				cout<<"\nENTER THE ROLL NO OF THE RECORD TO BE DELETED FROM HASH TABLE::";
				cin>>no;
				h.deletekey(no);	//call delete
				h.display();
				break;
		case 6:
				break;
		}
	}while(ch!=6);
	return 0;
}
/*
 * OUTPUT:-

-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::1

|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          -1        |EMPTY          |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          -1        |EMPTY          |-1
|4          -1        |EMPTY          |-1
|5          -1        |EMPTY          |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE ROLL NO.33

ENTER THE NAME::abc

|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          -1        |EMPTY          |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          33        |abc            |-1
|4          -1        |EMPTY          |-1
|5          -1        |EMPTY          |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE ROLL NO.44

ENTER THE NAME::def

|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          -1        |EMPTY          |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          33        |abc            |-1
|4          44        |def            |-1
|5          -1        |EMPTY          |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE ROLL NO.53

ENTER THE NAME::pqr

|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          -1        |EMPTY          |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          33        |abc            |5
|4          44        |def            |-1
|5          53        |pqr            |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE ROLL NO.10

ENTER THE NAME::xyz

|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          10        |xyz            |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          33        |abc            |5
|4          44        |def            |-1
|5          53        |pqr            |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::4

ENTER THE ROLL NO OF THE RECORD TO BE SEARCHED:-53

RECORD FOUND
-----RECORD DETAILS-----
ID:: 5
NAME:: pqr
ROLL NO:: 53
CHAIN:: -1

-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::5

ENTER THE ROLL NO OF THE RECORD TO BE DELETED FROM HASH TABLE::53

RECORD DELETED SUCCESSFULLY
|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          10        |xyz            |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          33        |abc            |-1
|4          44        |def            |-1
|5          -1        |EMPTY          |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::5

ENTER THE ROLL NO OF THE RECORD TO BE DELETED FROM HASH TABLE::33

RECORD DELETED SUCCESSFULLY
|INDEX     |ROLL NO.  |NAME           |CHAIN

|0          10        |xyz            |-1
|1          -1        |EMPTY          |-1
|2          -1        |EMPTY          |-1
|3          -1        |EMPTY          |-1
|4          44        |def            |-1
|5          -1        |EMPTY          |-1
|6          -1        |EMPTY          |-1
|7          -1        |EMPTY          |-1
|8          -1        |EMPTY          |-1
|9          -1        |EMPTY          |-1
-------ASSIGN-12-(DIRECT ACCESS FILE USING HASHING)--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::6

 */
