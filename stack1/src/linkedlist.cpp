/*
 * linkedlist.cpp
 *
 *  Created on: 20-Dec-2018
 *      Author: g10
 */


#include "linkedlist.h"
#include<iostream>
using namespace std;
template <class T>
node<T> *linkedlist<T> :: getnode()
{
	node<T> *temp;
	temp = new node<T>();
	temp->next =NULL;
	return temp;
}
template <class T>
void linkedlist<T> :: insert_first(T x)
{
	node<T> *temp;
	temp=getnode();
	temp->data =x;
	temp->next=head;
	head=temp;
}
template <class T>
T linkedlist<T> ::delete_first()
{
		node<T> *temp;
		temp=head;
		T x = temp->data;
		head=head->next;
		delete(temp);
		return x;
}
template <class T>
void linkedlist<T>::display()
{
	node<T> *temp;
	temp=head;
	if(isEmpty()!=true)
	{
		while(temp!=NULL)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
	else
		cout<<"EMPTY";
}
template <class T>
bool linkedlist<T>::isEmpty()
{
	if(head==NULL)
		return true;
	else
		return false;
}

template <class T>
T linkedlist<T>::peep()
{
	return (head->data);
}
template <class T>
linkedlist<T>::linkedlist()
{
	// TODO Auto-generated constructor stub
	head=NULL;
}
template <class T>
linkedlist<T>::~linkedlist()
{
	// TODO Auto-generated destructor stub
}

