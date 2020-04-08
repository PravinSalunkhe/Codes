/*
 * linkedlist.h
 *
 *  Created on: 22-Dec-2018
 *      Author: admin1
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
template <typename T>
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
		linkedlist();
		node<T> *getnode();
		void insert_first(T );
		void delete_first();
		bool isempty();
		void display();
		T peep();
		virtual ~linkedlist();
};

#endif /* LINKEDLIST_H_ */
