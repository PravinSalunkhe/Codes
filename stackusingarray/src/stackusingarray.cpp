//============================================================================
// Name        : stackusingarray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 SE-10
 G-10
 23257
 PRACTICE ASSIGNMENT :-IMPLEMENT STACK OPERATIONS USING LINKEDLIST.
 */

#include <iostream>
using namespace std;
template <class T>
class stack	//class creation
{
		T arr[10];	//declaring array
		int top;	//declaring top of stack
	public:
		stack()
		{
			top=-1;		//initializing top to -1
		}
		void display();
		void pop();
		void push(T x);
		bool isempty();
		bool isfull();
		T peep();
};

template <class T>
void stack<T>:: push(T x)	//PUSH OPERATION
{
	if(!isfull())		//CHECK IF STACK IS FULL
	{
		top=top+1;		//INC TOP
		arr[top]=x;
	}
	else
		cout<<"\nSTACK IS FULL";
}
template <class T>
void stack<T>::pop()		//POP OPERATION
{
	if(!isempty())
	{
		T x =arr[top];
		top=top-1;		//DEC TOP
	}
	return;
}
template <class T>
void stack<T>::display()	//DISPLAY FUNCTION
{
	if(!isempty())
	{
		cout<<"\nSTACK-->";
		for(int i=top;i>=0;i--)
		{
			cout<<"\n\t\t"<<arr[i];
		}
	}
	else
		cout<<"\nSTACK IS EMPTY";
}
template <class T>
bool stack<T>::isempty()		//ISEMPTY FUNCTION
{
	if(top==-1)			//CHECK TOP==-1 OR NOT
		return true;
	else
		return false;
}
template <class T>
bool stack<T>::isfull()
{
	if(top==9)		//CHECK TOP ==9 OR NOT
		return true;
	else
		return false;
}
template <class T>
T stack<T>::peep()	//TO DISPLAY TOP ELEMENT OF STACK
{
	if(!isempty())
		return(arr[top]);	//RETURN TOP ELEMENT
	else
	{
		cout<<"\nSTACK IS EMPTY";
		return NULL;
	}
}
int main()
{
	stack<int> s1;		//DECLARING OBECT OF STACK
	int ch;
	do
	{
		cout<<"\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.CHECK STACK IS EMPTY\n5.CHECK STACK IS FULL\n6.PEEP\n7.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
		case 1:
				int a;
				cout<<"\nENTER THE VALUE TO PUSH:-";
				cin>>a;
				s1.push(a);
				s1.display();
				break;
		case 2:
				s1.pop();
				s1.display();
				break;

		case 3:
				s1.display();
				break;
		case 4:
				bool b;
				b=s1.isempty();
				if(b==true)
					cout<<"\nSTACK IS EMPTY";
				else
					cout<<"\nSTACK IS NOT EMPTY";
				break;
		case 5:
				bool m;
				m=s1.isfull();
				if(m==true)
					cout<<"\nSTACK IS FULL";
				else
					cout<<"\nSTACK IS NOT FULL";
				break;
		case 6:
				int c=s1.peep();
				cout<<"\nDATA OF TOP:-"<<c;
				break;
		}
	}while(ch!=7);
	return 0;
}


/*OUTPUT:-

MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-1

STACK-->
		1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-2

STACK-->
		2
		1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-3

STACK-->
		3
		2
		1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK-->
		2
		1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK-->
		1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK IS EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK IS EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-3

STACK IS EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-4

STACK IS EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-5

STACK IS NOT FULL
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-6

STACK IS EMPTY
DATA OF TOP:-0
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-12

STACK-->
		12
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-2

STACK-->
		2
		12
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK-->
		12
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK IS EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-12

STACK-->
		12
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-11

MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-123

STACK-->
		123
		12
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-6

DATA OF TOP:-123
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK-->
		12
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-2

STACK IS EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.CHECK STACK IS FULL
6.PEEP
7.EXIT
ENTER UR CHOICE:-7
*/
 */
