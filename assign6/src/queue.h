/*
 * queue.h
 *
 *  Created on: 07-Jan-2019
 *      Author: g10
 */

#ifndef QUEUE_H_
#define QUEUE_H_

namespace std {

template <class T>
struct l_node			//l_node structure
{
	T data;
	struct l_node<T> *next;

};
template <class T>
class queue			//class declaration
{
	l_node<T> *front,*rear;	//declaration of front and rear
public:
	queue();				//function declaration
	~queue();
	l_node<T>*getnode(T x);
	void enqueue(T x);
	T dequeue();
	int size();
	void display();
	bool isEmpty();
};

} /* namespace std */

#endif /* QUEUE_H_ */
