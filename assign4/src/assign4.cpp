//============================================================================
// Name        : assign4.cpp
// Author      : PRAVIN SALUNKHE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * SE-10
 * G-10
 * 23257
 * PROBLEM STATEMENT:-	CREATE A EXPRESSION TREE AND DISPLAY RECURSIVE AND NON RECURSIVE PREORDER,
 * INORDER AND POSTORDER TRAVERSAL OF THE TREE
 */
#include <iostream>
using namespace std;
#include "stackadt.h"
#include "stackadt.cpp"
template <class T>
struct tnode	//STRUCT DECLARATION
{
	T data;
	struct tnode<T> *lchild;	//LCHILD
	struct tnode<T> *rchild;	//RCHILD
};

template <class T>
class exp_tree
{
		tnode<T> *root;	//ROOT DECLARATION
		char postorder[40];	//INPUT STRING
	public:
		exp_tree()		//CONSTRUCTOR
		{
			root=NULL;
		}
		void input();			//FUNCTIONS
		tnode<T> *getnode(int x);
		tnode<T> *ret_root();
		void create_exp_tree();
		void R_preorder(tnode<T> *P);
		void R_inorder(tnode<T> *P);
		void R_postorder(tnode<T> *P);
		void postorder_traversal();
		void preorder_traversal();
		void inorder_traversal();

};
bool isalpha(char x)	//function for detecting operands
{
	if((x>=48 && x<=57)||(x>64 && x<91) || (x>96 && x<123))	//IF OPERAND
		return true;
	else
		return false;	//ELSE OPERATOR
}
template <class T>
tnode<T> *exp_tree<T> :: getnode(int x)	//FUNCTION FOR GETTING NODE
{
	tnode<T> *temp=new tnode<T>();	//MEMORY ALLOCATION
	temp->data=x;		//COPYING DATA
	temp->lchild=NULL;	//SETTING LEFT AND RIGHT CHILD TO NULL
	temp->rchild=NULL;
	return temp;
}
template <class T>
void exp_tree<T> :: input()
{
	cin>>postorder;		//TAKING INPUT
}
template <class T>
tnode<T> *exp_tree<T> :: ret_root()		//RETURN ROOT
{
	return root;
}
template <class T>
void exp_tree<T> :: create_exp_tree()
{
	stackadt<tnode<char>*>s;	//CREATING OBJECT OF TYPE TNODE *
	tnode<T> * temp;
	int i=0;
	char x;
	while(postorder[i]!='\0')	//WHILE END OF INPUT STRING
	{
		x=postorder[i];
		if(isalpha(x))			//IF OPERAND
		{
			temp=getnode(x);	//CREATE NODE
			s.push(temp);		//PUSH ON STACK
		}
		else
		{
			temp=getnode(x);	//CREATE NODE
			temp->rchild=s.pop();	//POP AND SET AS RCHILD OF OPERATOR NODE
			temp->lchild=s.pop();	//POP AND SET AS LCHILD OF OPERATOR NODE
			s.push(temp);			//PUCH THE OPERATOR BACK ON STACK
		}
		i++;
	}
	root=s.pop();	//POP THE LAST ELEMENT AND RETURN TO ROOT
}
template <class T>
void exp_tree<T> :: R_preorder(tnode<T> *P)			//PRE-ORDER TRAVERSAL
{
	if(P!=NULL)
	{
		cout<<"\t"<<P->data;		//FIRST DISPLAY THE NODE
		R_preorder(P->lchild);		//THEN CALL FOR LCHILD
		R_preorder(P->rchild);		//THEN CALL FOR RCHILD
	}

}
template <class T>
void exp_tree<T> :: R_inorder(tnode<T> *P)		//INORDER TRAVERSAL
{
	if(P!=NULL)
	{
		R_inorder(P->lchild);		//FIRST CALL FOR LCHILD
		cout<<"\t"<<P->data;		//THEN DISPLAY ROOT
		R_inorder(P->rchild);		//THE CALL FOR RCHILD
	}
}
template <class T>
void exp_tree<T> :: R_postorder(tnode<T> *P)	//POSTORDER TRAVERSAL
{
	if(P!=NULL)
	{
		R_postorder(P->lchild);		//FIRST CALL FOR LCHILD
		R_postorder(P->rchild);		//THEN CALL FOR RCHILD
		cout<<"\t"<<P->data;		//FINALLY DISPLAY ROOT
	}
}
template <class T>
void exp_tree<T> :: preorder_traversal()		//NON RECURSIVE PRE ORDER TRAVERSAL
{
	stackadt<tnode<char> *>s;		//CREATING OBJECT OF TNODE * TYPE
	tnode<T> *p;
	if(root==NULL)
	{
		cout<<"\nTREE IS EMPTY.";	//IF ROOT IS NULL, TREE IS EMPTY
		return;
	}
	else
	{
		s.push(root);		//PUSH ROOT ON STACK
	}
	do
	{
		p=s.pop();		//POP THE ELEMENT AND RETURN TO P
		while(p!=NULL)
		{
			cout<<"\t"<<p->data;	//WRITE DATA
			if(p->rchild!=NULL)		//CHECK RCHILD IS NULL OR NOT
				s.push(p->rchild);	//PUSH
			p=p->lchild;
		}
	}while(!s.isEmpty());	//TILL STACK IS NOT EMPTY
}
template <class T>
void exp_tree<T> ::  inorder_traversal()	//NON RECURSIVE INORDER
{
	stackadt<tnode<char> *> s;		//CREATING OBJECT OF TNODE * TYPE
	tnode<T> *p;
	if(root==NULL)
	{
		cout<<"\nTREE IS EMPTY";	//IF ROOT IS NULL, TREE IS EMPTY
		return;
	}
	p=root;
	do
	{
		while(p!=NULL)		//WHILE NOT NULL
		{
			s.push(p);		//PUSH ON STACK
			p=p->lchild;	//GO TO LCHILD OF P
		}
		if(!s.isEmpty())	//TILL STACK IS NOT EMPTY
		{
			p=s.pop();		//POP
			cout<<"\t"<<p->data;	//AND DISPLAY
			p=p->rchild;		//GO TO RCHILD
		}
	}while(p!=NULL || !s.isEmpty());	//TILL P IS NOT NULL OR STACK IS NOT EMPTY
}
template <class T>
void exp_tree<T> :: postorder_traversal()	//NON RECURSIVE POSTORDER
{
	stackadt<tnode<char> *>s;		//CREATING OBJECT OF TNODE * TYPE
	tnode<T> *p,*prev;
	if(root==NULL)
	{
		cout<<"\nTREE IS EMPTY.";	//IF ROOT IS NULL, TREE IS EMPTY
		return;
	}
	else
	{
		p=root;
		s.push(p);		//PUSH P
	}
	while(!s.isEmpty())		//TILL STACK IS NOT EMPTY
	{
		p=s.pop();		//POP THE ELEMENT
		if(p->rchild==NULL && p->lchild==NULL)	//CHECK IF LEFT AND RIGHT ARE NULL
		{
			prev=p;					//SET PREV TO P
			cout<<"\t"<<p->data;	//DISPLAY NODE
		}
		else
		{
			if(p->rchild==prev || p->lchild==prev)	//CHECK IF LEFT OR RIGHT ARE POINTED BY PREVIOUS
			{
				prev=p;
				cout<<"\t"<<p->data;	//DISPLAY
			}
			else
			{
				s.push(p);		//PUSH ON STACK
				if(p->rchild)
					s.push(p->rchild);	//IF RCHILD EXISTS
				if(p->lchild)
					s.push(p->lchild);	//IF LCHILD EXISTS
			}
		}
	}
}

int main()
{
	exp_tree<char> e;	//OBJECT OF CHAR TYPE
	int ch;
	do
	{
		cout<<"\nEXPRESSION TREE\nMENU\n1.INPUT\n2.CREATE TREE\n3.PRE-ORDER TRAVERSAL\n"
				"4.IN-ORDER TRAVERSAL\n5.POST-ORDER TRAVERSAL\n6.EXIT\nENTER UR CHOICE:-";
		cin>>ch;		//GET CHOICE
		switch(ch)
		{
		case 1:
				cout<<"\nENTER A POSTFIX EXPRESSION:-";
				e.input();
				break;
		case 2:
				e.create_exp_tree();
				break;
		case 3:
				if(e.ret_root()!=NULL)
				{
					cout<<"\nRECURSIVE PREORDER TRAVERSAL:-\t";	//RECURSIVE PREORDER TRAVERSAL
					e.R_preorder(e.ret_root());
					cout<<"\nNON-RECURSIVE PREORDER TRAVERSAL:-";	//NON-RECURSIVE PREORDER TRAVERSAL
					e.preorder_traversal();
				}
				else
					cout<<"\nTREE IS EMPTY.";
				break;
		case 4:
				if(e.ret_root()!=NULL)
				{
					cout<<"\nRECURSIVE INORDER TRAVERSAL:-\t";		//RECURSIVE INORDER TRAVERSAL
					e.R_inorder(e.ret_root());
					cout<<"\nNON-RECURSIVE INORDER TRAVERSAL:-";	//NON-RECURSIVE INORDER TRAVERSAL
					e.inorder_traversal();
				}
				else
					cout<<"\nTREE IS EMPTY.";
				break;
		case 5:
				if(e.ret_root()!=NULL)
				{
					cout<<"\nRECURSIVE POSTORDER TRAVERSAL:-\t";	//RECURSIVE POSTORDER TRAVERSAL
					e.R_postorder(e.ret_root());
					cout<<"\nNON-RECURSIVE INORDER TRAVERSAL:-";	//NON-RECURSIVE INORDER TRAVERSAL
					e.postorder_traversal();
				}
				else
					cout<<"\nTREE IS EMPTY.";
				break;
		}
	}while(ch!=6);
	return 0;
}

/*OUTPUT:-
 *
EXPRESSION TREE
MENU
1.INPUT
2.CREATE TREE
3.PRE-ORDER TRAVERSAL
4.IN-ORDER TRAVERSAL
5.POST-ORDER TRAVERSAL
6.EXIT
ENTER UR CHOICE:-1

ENTER A POSTFIX EXPRESSION:-ab+c*def+*-

EXPRESSION TREE
MENU
1.INPUT
2.CREATE TREE
3.PRE-ORDER TRAVERSAL
4.IN-ORDER TRAVERSAL
5.POST-ORDER TRAVERSAL
6.EXIT
ENTER UR CHOICE:-2

EXPRESSION TREE
MENU
1.INPUT
2.CREATE TREE
3.PRE-ORDER TRAVERSAL
4.IN-ORDER TRAVERSAL
5.POST-ORDER TRAVERSAL
6.EXIT
ENTER UR CHOICE:-3

RECURSIVE PREORDER TRAVERSAL:-		-	*	+	a	b	c	*	d	+	e	f
NON-RECURSIVE PREORDER TRAVERSAL:-	-	*	+	a	b	c	*	d	+	e	f
EXPRESSION TREE
MENU
1.INPUT
2.CREATE TREE
3.PRE-ORDER TRAVERSAL
4.IN-ORDER TRAVERSAL
5.POST-ORDER TRAVERSAL
6.EXIT
ENTER UR CHOICE:-4

RECURSIVE INORDER TRAVERSAL:-		a	+	b	*	c	-	d	*	e	+	f
NON-RECURSIVE INORDER TRAVERSAL:-	a	+	b	*	c	-	d	*	e	+	f
EXPRESSION TREE
MENU
1.INPUT
2.CREATE TREE
3.PRE-ORDER TRAVERSAL
4.IN-ORDER TRAVERSAL
5.POST-ORDER TRAVERSAL
6.EXIT
ENTER UR CHOICE:-5

RECURSIVE POSTORDER TRAVERSAL:-		a	b	+	c	*	d	e	f	+	*	-
NON-RECURSIVE INORDER TRAVERSAL:-	a	b	+	c	*	d	e	f	+	*	-
EXPRESSION TREE
MENU
1.INPUT
2.CREATE TREE
3.PRE-ORDER TRAVERSAL
4.IN-ORDER TRAVERSAL
5.POST-ORDER TRAVERSAL
6.EXIT
ENTER UR CHOICE:-6
 *
 */

