//============================================================================
// Name        : stackadt.cpp
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
#include "stack.h"
#include "stack.cpp"
int main()
{
	stack<int> s1;	//DECLARING OBJECT OF STACK
	int ch;
	do
	{
		cout<<"\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.CHECK STACK IS EMPTY\n5.PEEP\n6.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
		case 1:
				int a;
				cout<<"\nENTER THE VALUE TO PUSH:-";
				cin>>a;
				s1.push(a);		//CALLING PUSH OPERATION
				s1.display();
				break;
		case 2:
				s1.pop();		//CALLING POP OPERATION
				s1.display();
				break;
		case 3:
				s1.display();	//CALLING DISPLAY
				break;
		case 4:
				bool b;
				b=s1.isempty();		//CALLING ISEMPTY FUNCTION
				if(b==true)
					cout<<"\nSTACK IS EMPTY";
				else
					cout<<"\nSTACK IS NOT EMPTY";
				break;
		case 5:
				int c=s1.peep();	//CALLING PEEP OPERATION
				cout<<"\nDATA OF TOP:-"<<c;
				break;
		}
	}while(ch!=6);
	return 0;
}


/*OUTPUT:-

MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-1

LIST IS :-
1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-2

LIST IS :-
2
1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-3

LIST IS :-
3
2
1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-1

ENTER THE VALUE TO PUSH:-4

LIST IS :-
4
3
2
1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-2

AFTER DELETION :-
LIST IS :-
3
2
1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-3

LIST IS :-
3
2
1
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-4

STACK IS NOT EMPTY
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-5

DATA OF TOP:-3
MENU
1.PUSH
2.POP
3.DISPLAY
4.CHECK STACK IS EMPTY
5.PEEP
6.EXIT
ENTER UR CHOICE:-6
*/
 */
