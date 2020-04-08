/*
 * stack.cpp
 *
 *  Created on: 22-Dec-2018
 *      Author: admin1
 */

#include <iostream>
using namespace std;
#include "stack.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
template<class T>
void stack<T>::push(T x)
{
	l1.insert_first(x);
}
template<class T>
void stack<T>::pop()
{
	l1.delete_first();
}
template<class T>
void stack<T>::display()
{
	l1.display();
}
template<class T>
bool stack<T>::isempty()
{
	bool y=l1.isempty();
	return y;
}
template <class T>
T stack<T>::peep()
{
	return (l1.peep());
}
template<class T>
stack <T>::stack()
{
	// TODO Auto-generated constructor stub

}
template<class T>
stack<T>::~stack()
{
	// TODO Auto-generated destructor stub
}
