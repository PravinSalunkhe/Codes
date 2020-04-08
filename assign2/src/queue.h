/*
 * queue.h
 *
 *  Created on: 07-Jan-2019
 *      Author: g10
 */

#ifndef QUEUE_H_
#define QUEUE_H_

namespace std {

struct patient	//structure declaration for data
{
	char name[40];
	int age;
	int regid;
	int weight;
	int priority;
};
template <class T>
struct node			//node structure
{
	patient data;
	node<T> *next;

};
template <class T>
class queue			//class declaration
{
	node<T> *front,*rear;	//declaration of front and rear
public:
	queue();				//function declaration
	virtual ~queue();
	node<T>*getnode();
	void insert_last();
	void delete_pos();
	void display();
	bool isEmpty();
};

} /* namespace std */

#endif /* QUEUE_H_ */
