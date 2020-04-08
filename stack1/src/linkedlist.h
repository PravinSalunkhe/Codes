/*
 * linkedlist.h
 *
 *  Created on: 20-Dec-2018
 *      Author: g10
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
template <class T>
struct node
{
	T data;
	struct node<T> *next;
};
template <class T>
class linkedlist
{
	node<T> *head;
public:
	void insert_first(T x);
	T delete_first();
	void display();
	bool isEmpty();
	node<T> *getnode();
	T peep();
	linkedlist();
	virtual ~linkedlist();
};

#endif /* LINKEDLIST_H_ */
