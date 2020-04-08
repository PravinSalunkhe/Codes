/*
 * stackadt.cpp
 *
 *  Created on: 20-Dec-2018
 *      Author: g10
 */

#include "stackadt.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include<iostream>
using namespace std;
template <class T>
stackadt<T>::stackadt()
{

}
template <class T>
stackadt<T>::~stackadt()
{
	// TODO Auto-generated destructor stub
}

template <class T>
void stackadt<T>::push(T x)
{
	l1.insert_first(x);
}
template <class T>
T stackadt<T>::pop()
{
	T x=l1.delete_first();
	return x;
}
template <class T>
void stackadt<T>::display()
{
	l1.display();
}
template <class T>
bool stackadt<T>::isEmpty()
{
	if(l1.isEmpty()==true)
		return true;
	else
		return false;
}
template <class T>
T stackadt<T>::peep()
{
	return (l1.peep());
}

