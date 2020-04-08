//============================================================================
// Name        : assign2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * NAME:-PRAVIN SALUNKHE
 * SE-10
 * G-10
 * 23257
 * PROBLEM STATEMENT:-	IMPLEMENT PRIORITY QUEUE AS AN ADT USING SINGLY LINKED LIST
 * FOR SERVING PATIENTS WITH PRIORITIES AS:
 * 1]SERIOUS(TOP PRIORITY)
 * 2]MEDIUM(MEDIUM PRIORITY)
 * 3]GENERAL(LEAST PRIORITY)
 */
#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include<iomanip>
using namespace std;
class hospital		//class declaration
{
	queue<char> l;	//creating object of queue ADT
	public:
		void add_patient();		//declaring functions
		void delete_patient();
		void display();
};
void hospital :: display()
{
	if(!(l.isEmpty()))	//IF LIST IS NOT EMPTY
	{
		cout<<"\n\n      --------PATIENT LIST---------     "
		"\n---------------------------"
		"-----------------------"
		"-------------------\n"<<setw(20)<<setiosflags(ios::left)<<"NAME"<<setw(10)<<setiosflags(ios::left)<<"AGE"<<setw(20)<<setiosflags(ios::left)<<"REGISTRATION ID"<<setw(10)<<setiosflags(ios::left)<<"WEIGHT"<<setw(10)<<setiosflags(ios::left)<<"PRIORITY\n";
		l.display();
	}
	else				//LIST IS EMPTY
		cout<<"\nLIST IS EMPTY";
}
void hospital :: add_patient()
{
	l.insert_last();	//INSERTING AT LAST
}
void hospital :: delete_patient()
{
	if(!(l.isEmpty()))	//IF LIST IS NOT EMPTY
	{
		l.delete_pos();
		cout<<"\nLIST HAS BEEN UPDATED";	//PATIENT DELETED SUCCESSFULLY
	}
	else								//LIST IS EMPTY
		cout<<"\nLIST IS EMPTY";
}
int main()
{
	int ch;
	hospital p;		//CREATING OBJECT OF HOSPITAL CLASS

	do
	{
		cout<<"\n\nHOSPITAL RECORDS\nMENU\n1.ADD PATIENT\n2.DISPLAY LIST\n3.DELETE PATIENT\n4.EXIT\nENTER UR CHOICE:-";
		cin>>ch;		//GET THE CHOICE FROM USER
		switch(ch)
		{
		case 1:
				p.add_patient();	//CALLING ADD PATIENT FUNCTION
				break;
		case 2:
				p.display();		//CALLING DISPLAY FUNCTION
				break;
		case 3:
				p.delete_patient();	//CALLING DELETE FUNCION
				p.display();
				break;
		}
	}while(ch!=4);
return 0;
}


/*OUTPUT:-

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-1

ENTER the NAME of the PATIENT:-RAM

ENTER the REGISTRATION ID of the PATIENT:-1234

ENTER the AGE of the PATIENT:-56

ENTER the WEIGHT of the PATIENT:-55

ENTER the PRIORITY of the PATIENT
1.CRITICAL
2.MEDIUM
3.GENERAL
ENTER UR CHOICE:-2


HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-1

ENTER the NAME of the PATIENT:-LAXMAN

ENTER the REGISTRATION ID of the PATIENT:-1235

ENTER the AGE of the PATIENT:-66

ENTER the WEIGHT of the PATIENT:-78

ENTER the PRIORITY of the PATIENT
1.CRITICAL
2.MEDIUM
3.GENERAL
ENTER UR CHOICE:-1


HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-1

ENTER the NAME of the PATIENT:-RAJ

ENTER the REGISTRATION ID of the PATIENT:-1236

ENTER the AGE of the PATIENT:-33

ENTER the WEIGHT of the PATIENT:--3

PLEASE ENTER A VALID WEIGHT:-45

ENTER the PRIORITY of the PATIENT
1.CRITICAL
2.MEDIUM
3.GENERAL
ENTER UR CHOICE:-4

PLEASE ENTER A VALID PRIORITY:-1


HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-1

ENTER the NAME of the PATIENT:-MOHAN

ENTER the REGISTRATION ID of the PATIENT:-1237

ENTER the AGE of the PATIENT:-15

ENTER the WEIGHT of the PATIENT:-44

ENTER the PRIORITY of the PATIENT
1.CRITICAL
2.MEDIUM
3.GENERAL
ENTER UR CHOICE:-3


HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-2


                    --------PATIENT LIST---------
---------------------------------------------------------------------
NAME                AGE       REGISTRATION ID     WEIGHT    PRIORITY
---------------------------------------------------------------------
|RAM                |56        |1234                |55        |2
|LAXMAN             |66        |1235                |78        |1
|RAJ                |33        |1236                |45        |1
|MOHAN              |15        |1237                |44        |3

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-3

LIST HAS BEEN UPDATED


                    --------PATIENT LIST---------
---------------------------------------------------------------------
NAME                AGE       REGISTRATION ID     WEIGHT    PRIORITY
---------------------------------------------------------------------
|RAM                |56        |1234                |55        |2
|RAJ                |33        |1236                |45        |1
|MOHAN              |15        |1237                |44        |3

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-3

LIST HAS BEEN UPDATED


                    --------PATIENT LIST---------
---------------------------------------------------------------------
NAME                AGE       REGISTRATION ID     WEIGHT    PRIORITY
---------------------------------------------------------------------
|RAM                |56        |1234                |55        |2
|MOHAN              |15        |1237                |44        |3

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-3

LIST HAS BEEN UPDATED


                    --------PATIENT LIST---------
---------------------------------------------------------------------
NAME                AGE       REGISTRATION ID     WEIGHT    PRIORITY
---------------------------------------------------------------------
|MOHAN              |15        |1237                |44        |3

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-3

LIST HAS BEEN UPDATED

LIST IS EMPTY

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-2

LIST IS EMPTY

HOSPITAL RECORDS
MENU
1.ADD PATIENT
2.DISPLAY LIST
3.DELETE PATIENT
4.EXIT
ENTER UR CHOICE:-4

 */
