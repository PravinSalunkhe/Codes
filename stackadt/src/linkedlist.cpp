/*
 * linkedlist.cpp
 *
 *  Created on: 22-Dec-2018
 *      Author: admin1
 */

#include "linkedlist.h"
#include <iostream>
using namespace std;
template <class T>
linkedlist<T>::linkedlist()
{
	// TODO Auto-generated constructor stub
	head=NULL;
}
template <class T>
node<T> *linkedlist<T>::getnode()
{
	node<T> *temp = new node <T>();
	temp->next = NULL;
	return temp;
}
template <class T>
void linkedlist<T>::insert_first(T x)
{
	node <T> *temp;
	temp=getnode();
	temp->data=x;
	temp->next=head;
	head=temp;
}
template <class T>
void linkedlist<T>::delete_first()
{
	node <T> *temp=head;
	bool y=isempty();
	if(y==false)
	{
		head=head->next;
		delete(temp);
		cout<<"\nAFTER DELETION :-";
	}
	else
	{
		head=NULL;
		return;
	}
}
template <class T>
void linkedlist<T>::display()
{
	node <T> *temp=head;
	bool y;
	y=isempty();
	if(y==false)
	{
		cout<<"\nLIST IS :-";
		while(temp!=NULL)
		{
			cout<<"\n"<<temp->data;
			temp=temp->next;
		}
	}
	else
		cout<<"\nLIST IS EMPTY";
}
template <class T>
T linkedlist<T>::peep()
{
	return (head->data);
}
template <class T>
bool linkedlist<T>::isempty()
{
	if(head==NULL)
		return true;
	else
		return false;
}
template <class T>
linkedlist<T>::~linkedlist()
{
	// TODO Auto-generated destructor stub
}
