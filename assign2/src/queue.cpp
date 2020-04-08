/*
 * queue.cpp
 *
 *  Created on: 07-Jan-2019
 *      Author: g10
 */

#include "queue.h"
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

template <class T>
node<T> *queue<T> :: getnode()		//GETNODE FUNCTION
{
	node<T> *temp=NULL;
	temp = new node<T>();		//ALLOCATION OF MEMORY
	temp->next =NULL;
	cout<<"\nENTER the NAME of the PATIENT:-";		//GETTING DATA
	cin.ignore();
	cin.getline(temp->data.name,40);
	cout<<"\nENTER the REGISTRATION ID of the PATIENT:-";
	cin>>temp->data.regid;
	cout<<"\nENTER the AGE of the PATIENT:-";
	cin>>temp->data.age;
	while((temp->data.age)<=0)			//AGE VALIDATION
	{
		cout<<"\nPLEASE ENTER A VALID AGE:-";		//AGE CANNOT BE <=0
		cin>>temp->data.age;
	}
	cout<<"\nENTER the WEIGHT of the PATIENT:-";
	cin>>temp->data.weight;
	while((temp->data.weight)<=0)		//WEIGHT VALIDATION
	{
		cout<<"\nPLEASE ENTER A VALID WEIGHT:-";	//WEIGHT CANNOT BE <=0
		cin>>temp->data.weight;
	}
	cout<<"\nENTER the PRIORITY of the PATIENT\n1.CRITICAL\n2.MEDIUM\n3.GENERAL\nENTER UR CHOICE:-";
	cin>>temp->data.priority;
	while((temp->data.priority)!=3 && (temp->data.priority)!=2 && (temp->data.priority)!=1)
	{																				//PRIORITY VALIDATION
		cout<<"\nPLEASE ENTER A VALID PRIORITY:-";
		cin>>temp->data.priority;					//PRIORITY HAS TO BE BETWEEN (1-3)
	}
	return temp;		//RETURN CREATED NODE
}
template <class T>
void queue<T>::insert_last()
{
	node<T> *temp;
	temp=getnode();		//CALLING GETNODE FUNCTION
	if(isEmpty())		//CHECK ISEMPTY CONDITION
	{
		front=temp;
		rear=temp;
		rear->next=NULL;	//FIRST NODE CREATION
		front->next=NULL;
		return;
	}
	rear->next=temp;
	rear=temp;
}
template<class T>
void queue<T>::delete_pos()			//DELETE FUNCTION
{
	node<T> *temp,*temp1,*min,*prev;
	temp=front;			//INITIALISING TEMP
	temp1=NULL;
	min=front;			//INITIALISING MIN
	while(temp!=NULL)	//TILL TEMP !=NULL
	{
		if((temp->data.priority) < (min->data.priority))		//IF MIN PRIORITY IS PRESENT AHEAD
		{
			min=temp;			//ASSIGN TEMP TO MIN
			prev=temp1;			//PREV POINTER REQUIRED FOR DELETION
		}
		temp1=temp;
		temp=temp->next;		//INCREMENT TEMP
	}
	if(min==front)			//NODE TO BE DELETED PRESENT AT FRONT
	{
		front=front->next;	//INC FRONT
		if(min==rear)
		{
			rear=NULL;
		}
		delete(min);		//FREE MEMORY OF NODE
		return;
	}
	if(min==rear)		//NODE TO BE DELETED PRESENT AT REAR
	{
		rear=prev;
	}
	prev->next=min->next;
	delete(min);		//FREE MEMORY OF NODE
}
template<class T>
void queue <T>::display()	//DISPLAY FUNCTION
{
	node<T> *temp;
		temp=front;
			while(temp!=NULL)	//TILL TEMP IS NOT EQUAL TO NULL
			{					//FORMATTED DISPLAY
				cout<<"\n|"<<setw(19)<<setiosflags(ios::left)<<temp->data.name;
				cout<<"|"<<setw(10)<<setiosflags(ios::left)<<temp->data.age;
				cout<<"|"<<setw(20)<<setiosflags(ios::left)<<temp->data.regid;
				cout<<"|"<<setw(10)<<setiosflags(ios::left)<<temp->data.weight;
				cout<<"|"<<setw(10)<<setiosflags(ios::left)<<temp->data.priority;
				temp=temp->next;
			}
}

template <class T>
bool queue <T>::isEmpty()		//ISEMPTY FUNCTION
{
	if(front==NULL && rear ==NULL)		//FRONT=REAR=NULL
		return true;			//EMPTY
	else
		return false;			//NOT EMPTY
}
template <class T>
queue<T>::queue()		//CONSTRUCTOR
{
	// TODO Auto-generated constructor stub
	rear=NULL;
	front=NULL;

}
template <class T>
queue<T>::~queue()		//DESTRUCTOR
{
	// TODO Auto-generated destructor stub
}
