/*
 * queue.cpp
 *
 *  Created on: 07-Jan-2019
 *      Author: g10
 */

#include<iostream>
#include<string.h>
#include<iomanip>
#include "queue.h"
using namespace std;

template <class T>
l_node<T> *queue<T> :: getnode(T x)		//GETNODE FUNCTION
{
	l_node<T> *temp=NULL;
	temp = new l_node<T>();		//ALLOCATION OF MEMORY
	temp->data=x;
	temp->next =NULL;
	return temp;		//RETURN CREATED NODE
}
template <class T>
void queue<T>::enqueue(T x)
{
	l_node<T> *temp;
	temp=getnode(x);		//CALLING GETNODE FUNCTION
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
T queue<T>::dequeue()			//DELETE FUNCTION
{
	l_node<T> *temp;
	if(!isEmpty())
	{
		temp=front;
		T x=temp->data;
		if(front ==rear)
		{
			front=rear=NULL;
			delete(temp);
		}
		else
		{
			front=front->next;
			delete(temp);
		}
		return x;
	}
}
template<class T>
void queue <T>::display()	//DISPLAY FUNCTION
{
	l_node<T> *temp;
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
int queue<T> :: size()
{
	int count=0;
	l_node<T> *temp;
	temp=front;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

template <class T>
bool queue <T>::isEmpty()		//ISEMPTY FUNCTION
{
	if(front==NULL && rear==NULL)		//FRONT=REAR=NULL
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
