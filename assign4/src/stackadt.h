/*
 * stackadt.h
 *
 *  Created on: 20-Dec-2018
 *      Author: g10
 */

#ifndef STACKADT_H_
#define STACKADT_H_
#include "linkedlist.h"
template <class T>
class stackadt
{
	linkedlist<T> l1;
public:
	void push(T x);
	T pop();
	bool isEmpty();
	void display();
	stackadt();
	T peep();
	virtual ~stackadt();
};

#endif /* STACKADT_H_ */
