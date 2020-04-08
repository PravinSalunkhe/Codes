/*
 * stack.h
 *
 *  Created on: 22-Dec-2018
 *      Author: admin1
 */

#ifndef STACK_H_
#define STACK_H_
#include "linkedlist.h"
template <class T>
class stack {
	linkedlist<T> l1;
public:
	void push(T );
	void pop();
	bool isempty();
	void display();
	T peep();
	stack();
	virtual ~stack();
};

#endif /* STACK_H_ */
