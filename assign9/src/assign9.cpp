/* G-10
 * 23257
 * PROBLEM STATEMENT:- STORE THE DATA OF STUDENTS WITH TEL NO AND NAME IN STRUCTURE
 * USING HASHING FUNCTION FOR TEL NO AND IMPLEMENT HASHING(CHAINING WITHOUT REPLACEMENT).
 */
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
struct data		//struct for data
{
	char name[50];
	long int tel;
	int id;
	int chain;
};

class hash_table	//class
{
		data t[10];		//10 objects for hash table
public:
		void create();
		void insert(long int tel,char name1[50]);
		int search(long int myno);
		int func(int tel);
		void delete_rec();
		void display();
		void display1(int i);
		void deletekey(long int no);
};
void hash_table :: create()
{
	int i;
	for(i=0;i<10;i++)		//initialize
	{
		t[i].tel=-1;
		t[i].chain=-1;
	}
}
int hash_table :: func(int tel)		//hash function
{
	int key= tel%10;		//return key
	return key;
}
void hash_table :: insert(long int no,char name1[50]) //for insert
{
	int i,j;
	int key=func(no);
		if(t[key].tel==-1)	//if found at proper index
		{
			t[key].tel=no;
			strcpy(t[key].name,name1);
			t[key].chain=-1;
			return;
		}
		else
		{
			i=(key+1)%10;
			while(t[i].tel!=-1 && i!=key)
				i=(i+1)%10;

			if(t[i].tel==-1)
			{
				t[i].tel=no;
				strcpy(t[i].name,name1);
				t[i].chain=-1;
			}
			if(i==key)				//not found
			{
				cout<<"\nHASH TABLE IS FULL\nNO CHANGE MADE\n";
				return;
			}
			j=key;
			while(func(t[j].tel)!=key)
			{
				j=(j+1)%10;
				if(j==key)
				{
					cout<<"\nHASH TABLE IS FULL.\nNO CHANGE MADE.\n";
					return;
				}
			}
			if(func(t[j].tel)==key)
			{
					while(t[j].chain!=-1)
					{
						j=t[j].chain;
					}
					if(j!=i)
					t[j].chain=i;
			}
		}
}
int hash_table :: search(long int myno)	//for search
{
	int i;
	int key=func(myno);
	i=key;
	if(t[key].tel==myno)	//found at proper location
		return i;
	else
	{
		if(t[i].chain==-1)		//if chain is -1
		{
			i=(key+1)%10;
			while(t[i].tel!=myno && i!=key)
				i=(i+1)%10;
			if(t[i].tel==myno)
				return i;
			if(i==key)
			{
				cout<<"\nRECORD NOT FOUND.";
				return -1;
			}
		}
		else
		{
			i=key;
			while(t[i].chain!=-1)	//if chain is not -1
			{
				i=t[i].chain;
				if(t[i].tel==myno)
					return i;		//found
			}
			return -1;		//not found
		}
	}
}

void hash_table :: deletekey(long int no)
{
	int key=func(no);
	int temp,i,j;
	if(t[key].tel==no)		//found at proper location
	{
		t[key].tel=-1;
		strcpy(t[key].name,"EMPTY");
		if(t[key].chain!=-1)		//for updating chain
		{
			temp=key;
			while(t[temp].chain!=-1)	//find end of chain
			{
				t[temp].tel=t[t[temp].chain].tel;
				strcpy(t[temp].name,t[t[temp].chain].name);
				if(t[t[temp].chain].chain==-1)
				{
					j=t[temp].chain;
					t[temp].chain=-1;
					break;
				}
				temp=t[temp].chain;
			}
			t[j].tel=-1;
			t[j].chain=-1;
			strcpy(t[j].name,"EMPTY");
		}
		else
		{
		t[key].chain=-1;
		}
		cout<<"\nRECORD DELETED SUCCESSFULLY";
		return;
	}
	else
	{
		if(t[key].chain==-1)		//if chain is -1
		{
			temp=key+1;
			while(no!=t[temp].tel && temp!=key)		//find next available location
			{
				temp=(temp+1)%10;
			}
				if(no==t[temp].tel)		//if found
				{
					t[temp].tel=-1;
					strcpy(t[temp].name,"EMPTY");
					t[temp].chain=-1;
					cout<<"\nRECORD DELETED SUCCESSFULLY";
					return;
				}
				if(temp==key)	//not found
				{
					cout<<"\nRECORD NOT FOUND";
					return;
				}
		}
		else
		{
			temp=key;i=0;
			while(temp!=-1 && no!=t[temp].tel)
			{
				i=temp;
				temp=t[temp].chain;
			}
			if(no==t[temp].tel)
			{
				t[temp].tel=-1;
				strcpy(t[temp].name,"EMPTY");
				if(t[temp].chain!=-1)
					t[i].chain=t[temp].chain;
				else
					t[i].chain=-1;

				t[temp].chain=-1;
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
void hash_table :: display()
{
		cout<<"\n|"<<setw(15)<<setiosflags(ios::left)<<"INDEX"<<"|"<<setw(15)<<setiosflags(ios::left)<<"TEL NO"<<"|"<<setw(15)<<setiosflags(ios::left)<<"CHAIN\n";
		for(int i=0;i<10;i++)
		{
			cout<<"\n|"<<setw(15)<<setiosflags(ios::left)<<i<<"|";
			if(t[i].tel!=-1)
			cout<<setw(15)<<setiosflags(ios::left)<<t[i].tel<<"|";
			else
				cout<<setw(15)<<setiosflags(ios::left)<<"EMPTY"<<"|";
			cout<<setw(15)<<setiosflags(ios::left)<<t[i].chain;
		}
}
void hash_table :: display1(int i)
{
	cout<<"\nNAME:: "<<t[i].name;
	cout<<"\nTEL NO:: "<<t[i].tel;
	cout<<"\nCHAIN:: "<<t[i].chain<<"\n";
}
int main()
{
		hash_table h;	//create object
		int ch,a;
		char name[50];
		long int no;
	do
	{
		cout<<"\n-------HASHING--------\nMENU\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.SEARCH\n5.DELETE\n6.EXIT\nENTER UR CHOICE::";
		cin>>ch;
		switch(ch)
		{
		case 1:
				h.create();
				h.display();
				break;
		case 2:
				h.display();
				break;
		case 3:
				cout<<"\nENTER THE TEL NO.";
				cin>>no;
				cout<<"\nENTER THE NAME::";
				cin>>name;
				h.insert(no,name);
				h.display();
				break;
		case 4:
				cout<<"\nENTER THE TEL NO TO BE SEARCHED:-";
				cin>>no;
				a=h.search(no);
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
				cout<<"\nENTER THE TEL NO TO BE DELETED FROM HASH TABLE::";
				cin>>no;
				h.deletekey(no);
				h.display();
				break;
		case 6:
				break;
		}
	}while(ch!=6);
	return 0;
}
/*OUTPUT:-
 *
-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::1

|INDEX          |TEL NO         |CHAIN

|0              |EMPTY          |-1
|1              |EMPTY          |-1
|2              |EMPTY          |-1
|3              |EMPTY          |-1
|4              |EMPTY          |-1
|5              |EMPTY          |-1
|6              |EMPTY          |-1
|7              |EMPTY          |-1
|8              |EMPTY          |-1
|9              |EMPTY          |-1
-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE TEL NO.976534232

ENTER THE NAME::ram

|INDEX          |TEL NO         |CHAIN

|0              |EMPTY          |-1
|1              |EMPTY          |-1
|2              |976534232      |-1
|3              |EMPTY          |-1
|4              |EMPTY          |-1
|5              |EMPTY          |-1
|6              |EMPTY          |-1
|7              |EMPTY          |-1
|8              |EMPTY          |-1
|9              |EMPTY          |-1
-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE TEL NO.7652327

ENTER THE NAME::pravin

|INDEX          |TEL NO         |CHAIN

|0              |EMPTY          |-1
|1              |EMPTY          |-1
|2              |976534232      |-1
|3              |EMPTY          |-1
|4              |EMPTY          |-1
|5              |EMPTY          |-1
|6              |EMPTY          |-1
|7              |7652327        |-1
|8              |EMPTY          |-1
|9              |EMPTY          |-1
-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::3

ENTER THE TEL NO.458587

ENTER THE NAME::yash

|INDEX          |TEL NO         |CHAIN

|0              |EMPTY          |-1
|1              |EMPTY          |-1
|2              |976534232      |-1
|3              |EMPTY          |-1
|4              |EMPTY          |-1
|5              |EMPTY          |-1
|6              |EMPTY          |-1
|7              |7652327        |8
|8              |458587         |-1
|9              |EMPTY          |-1
-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::4

ENTER THE TEL NO TO BE SEARCHED:-458587

RECORD FOUND
-----RECORD DETAILS-----
NAME:: 4yash
TEL NO:: 458587
CHAIN:: -1

-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::5

ENTER THE TEL NO TO BE DELETED FROM HASH TABLE::976534232

RECORD DELETED SUCCESSFULLY
|INDEX          |TEL NO         |CHAIN

|0              |EMPTY          |-1
|1              |EMPTY          |-1
|2              |EMPTY          |-1
|3              |EMPTY          |-1
|4              |EMPTY          |-1
|5              |EMPTY          |-1
|6              |EMPTY          |-1
|7              |7652327        |8
|8              |458587         |-1
|9              |EMPTY          |-1
-------HASHING--------
MENU
1.CREATE
2.DISPLAY
3.INSERT
4.SEARCH
5.DELETE
6.EXIT
ENTER UR CHOICE::6
 *
 */
