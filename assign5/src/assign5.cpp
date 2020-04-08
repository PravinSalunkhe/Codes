//============================================================================
// Name        : assign5.cpp
// Author      : Pravin Salunkhe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* SE-10
 * G-10
 * 23257
 * PROBLEM STATEMENT:- IMPLEMENT BINARY TREE AND IMPLEMENT FOLLOWING OPERATIONS:-
 * 1.INSERT
 * 2.DISPLAY
 * 3.HEIGHT
 * 4.MIRROR
 * 5.SEARCH
 * 6.DELETE
 */



#include <iostream>
#include "queue.h"
#include "queue.cpp"

using namespace std;


template <class T>
struct tnode		//STRUCT DECLARATION
{
	T data;
	struct tnode<T> *lchild;
	struct tnode<T> *rchild;
};
template <class T>
class bst			//CLASS DECLARATION
{
		tnode<T> *root=NULL;		//PRIVATE MEMBER
	public:
		tnode<T> *getnode(T x);		//PUBLIC MEMBERS
		tnode<T> *retroot();
		void binsert(T x);
		tnode<T> *R_binsert(tnode<T> *,T x);
		void insert1(T x);
		void R_preorder(tnode<T> *);
		void R_postorder(tnode<T> *);
		void R_inorder(tnode<T> *);
		void levelorder(tnode<T> *);
		tnode<T> *mirror(tnode<T> *);
		tnode<T> *NR_mirror();
		int height();
		tnode<T> *search(T key);
		tnode <T> *successor(tnode<T> *p);
		tnode<T> *deletenode(T x,tnode<T> *);
		tnode<T> *delete1(T x);
		void NR_delete(T x);
};
template <class T>
tnode<T> *bst<T> :: getnode(T x)	//GETNODE FUNCTION
{
	tnode<T> *temp=NULL;	//INITIALIZE TEMP
	temp=new tnode<T>();	//ALLOCATING MEMORY
	temp->data=x;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;
}

template <class T>
tnode <T> *bst<T> :: retroot()	//RETURN ROOT
{
	return root;
}
template <class T>
void bst<T> :: binsert(T x)		//NON -RECURSIVE INSERT
{
	tnode <T> *p,*q;
	if(root==NULL)
	{
		root=getnode(x);		//CALLING GETNODE
		return;
	}

	else
	{
		p=q=root;
		while(q!=NULL && x!=p->data)	//TILL DATA NOT FOUND
		{
			p=q;
			if(x<p->data)		//IF KEY IS LESS THAN CURRENT
				q=p->lchild;
			else if(x>p->data)	//IF KEY IS GREATER THAN CURRENT
				q=p->rchild;

		}
		if(x==p->data)
		{
			cout<<"\nDUPLICATE NODE NOT ALLOWED.";	//DUPLIACTE NODE VALIDATION
			return;
		}
		if(x<p->data)
			p->lchild=getnode(x);	//INSERT IN LCHILD
		else
			p->rchild=getnode(x);	//INSERT IN RCHILD
		return;
	}
}
template <class T>
void bst<T> ::insert1(T x)	//RECURSIVE INSERT
{
	root=R_binsert(root,x);
}

template <class T>
tnode<T> *bst<T> :: R_binsert(tnode<T> *p,T x)
{
	if(p==NULL)
	{
		p=getnode(x);	//CALLING GETNODE FUNCTION
		return p;
	}
	else
	{
		if(x<p->data)		//IF KEY IS LESS THAN CURRENT
		{
			if(p->lchild!=NULL)		//IF LCHILD IS NOT NULL
				p->lchild=R_binsert(p->lchild,x);	//CALL FOR LCHILD
			else
				p->lchild=getnode(x);
		}
		else if(x>p->data)	//IF KEY IS GREATER THAN CURRENT
		{
			if(p->rchild!=NULL)		//IF RCHILD IS NOT NULL
				p->rchild=R_binsert(p->rchild,x);	//CALL FOR RCHILD
			else
				p->rchild=getnode(x);		//CALL GETNODE
		}
		else
		{
			cout<<"\nDUPLICATE NODE NOT ALLOWED.";	//NO DUPLICATE NODE
		}
		return p;
	}
}
template<class T>
void bst<T> :: R_inorder(tnode<T> *P)	//INORDER TRAVERSAL
{
	if(P!=NULL)				//IF ROOT IS NOT NULL
	{
		R_inorder(P->lchild);	//RECURSIVE CALL FOR LCHILD
		cout<<"\t"<<P->data;	//DISPLAY ROOT
		R_inorder(P->rchild);	//RECURSIVE CALL FOR RCHILD
	}
}
template<class T>
void bst<T> :: R_preorder(tnode<T> *P)
{
	if(P!=NULL)				//IF ROOT IS NOT NULL
	{
		cout<<"\t"<<P->data;	//DISPLAY ROOT
		R_preorder(P->lchild);	//RECURSIVE CALL FOR LCHILD
		R_preorder(P->rchild);	//RECURSIVE CALL FOR RCHILD
	}
}
template<class T>
void bst<T> :: R_postorder(tnode<T> *P)
{
	if(P!=NULL)				//IF ROOT IS NOT NULL
	{
		R_postorder(P->lchild);	//RECURSIVE CALL FOR RCHILD
		R_postorder(P->rchild);	//RECURSIVE CALL FOR LCHILD
		cout<<"\t"<<P->data;	//DISPLAY ROOT
	}
}
template <class T>
void bst<T>:: levelorder(tnode<T> *p)	//LEVELORDER DISPLAY
{
	queue <tnode<string>*> q;		//CREATE OBJECT OF QUEUE
	if(p==NULL)				//IF ROOT IS NULL
	{
		cout<<"\nTREE IS EMPTY.";
		return;
	}
	else
	{
		q.enqueue(p);		//INSERT P
		while(!q.isEmpty())		//WHILE Q IS NOT EMPTY
		{
			p=q.dequeue();		//DEQUEUE CURRENT LEVEL ELEMENTS
			cout<<"\t"<<p->data;	//DISPLAY THEM
			if(p->lchild!=NULL)
				q.enqueue(p->lchild);	//INSERT NEXT LEVEL ELEMENTS(LCHILD)
			if(p->rchild!=NULL)
				q.enqueue(p->rchild);	//INSERT NEXT LEVEL ELEMENTS(RCHILD)
		}
	}

}
template <class T>
int bst<T> :: height()		//NON RECURSIVE HEIGHT
{
	tnode<T> *temp;
	int height,nodecount;
	if(root==NULL)		//IF ROOT IS NULL
		return 0;
	else
	{
		queue <tnode<string>*> q;		//CREATE OBJECT OF QUEUE
		q.enqueue(root);			//INSERT ROOT
		height=-1;
		while(1)
		{
			nodecount=q.size();		//GETTING COUNT OF NODES
			if(nodecount==0)
				return height;		//IF 0,RETURN HEIGHT
			height++;				//INC HEIGHT

			while(nodecount>0)		//TILL COUNT >0
			{
				temp=q.dequeue();	//DEQUEUE THE CURRENT ELEMENT
				if(temp->lchild!=NULL)
					q.enqueue(temp->lchild);	//INSERT CHILDREN OF THE NODE
				if(temp->rchild!=NULL)
					q.enqueue(temp->rchild);
				nodecount--;			//DEC COUNT
			}
		}

	}

}

template<class T>
tnode<T> * bst<T> :: mirror(tnode <T> *P)
{
		tnode<T> *temp=NULL;
		if(P==NULL)
			return P;				//IF TREE IS EMPTY
		else
		{
			T x=P->data;			//GET DATA OF NODE
			temp=getnode(x);		//ALLOCATE MEMORY
			temp->lchild=mirror(P->rchild);		//CALL FOR LCHILD
			temp->rchild=mirror(P->lchild);		//CALL FOR RCHILD
		}
		return temp;
}
template <class T>
tnode<T> *bst<T> :: NR_mirror()
{
	queue <tnode<string>*> q1,q2;
	tnode<T> *temp=NULL,*t=NULL,*p=NULL,*s=NULL;
	if(root==NULL)				//IF ROOT IS NULL
		{
			cout<<"\nTREE IS EMPTY.";
			return NULL;
		}
	else
	{
		p=getnode(root->data);
		q1.enqueue(root);
		q2.enqueue(p);
		while(!q1.isEmpty())
		{
			t=q1.dequeue();
			s=q2.dequeue();

			if(t->lchild==NULL && t->rchild==NULL)
				continue;
			if(t->lchild!=NULL && t->rchild!=NULL)
			{
				s->lchild=getnode(t->rchild->data);
				s->rchild=getnode(t->lchild->data);
				q1.enqueue(t->lchild);
				q1.enqueue(t->rchild);
				q2.enqueue(s->rchild);
				q2.enqueue(s->lchild);
			}
			else if(t->lchild==NULL)
			{

				s->lchild=getnode(t->rchild->data);
				s->rchild=NULL;
				q1.enqueue(t->rchild);
				q2.enqueue(s->lchild);
			}
			else
			{
				s->rchild=getnode(t->lchild->data);
				s->lchild=NULL;
				q1.enqueue(t->lchild);
				q2.enqueue(s->rchild);
			}
		}
	}
	return p;
}
template <class T>
tnode <T> * bst <T> :: search(T key)		//SEARCH FUNCTION
{
	tnode<T> *p;
	if(root==NULL)
	{
		cout<<"\nTREE IS EMPTY.";
		return NULL;
	}
		p=root;
		while(p)
		{
			if(key==p->data)			//IF KEY=DATA
				return p;
			else if(key<p->data)		//IF P<DATA
				p=p->lchild;

			else
				p=p->rchild;			//IF P>DATA
		}
		return p;
}

template <class T>
tnode <T> *bst<T> ::successor(tnode<T> *p)	//SUCCESSOR FUNCTION
{
	while(p->lchild!=NULL)
	{
		p=p->lchild;
	}
		return p;
}
template <class T>
tnode <T> *bst<T> :: delete1(T x)	//DELETE FUNCTION FOR RECURSIVE DELETE
{
	root=deletenode(x,root);
	return root;			//RETURN ROOT
}


template <class T>
tnode <T> *bst <T> :: deletenode(T key,tnode <T> *p)	//DELETE FUNCTION
{
	tnode<T> *temp;
	if(p==NULL)
	{
		cout<<"\nNODE NOT FOUND.";
		return NULL;
	}
	else if(key<p->data)				//IF P<DATA
	{
		p->lchild=deletenode(key,p->lchild);
		return p;
	}
	else if(key>p->data)				//IF P>DATA
	{
		p->rchild=deletenode(key,p->rchild);
		return p;
	}
	else								//IF KEY=DATA
	{

		if(p->lchild && p->rchild)			//IF BOTH CHILDREN ARE PRESENT
		{
			temp=successor(p->rchild);		//GET SUCCESSOR
			p->data=temp->data;				//COPY DATA OF SUCCESSOR IN THE NODE TO BE DELETED
			p->rchild=deletenode(p->data,p->rchild);	//CALL FOR RCHILD OF DELETED NODE
		}
		else
		{
			temp=p;
			if(p->lchild==NULL)		//IF LCHILD OR ZERO CHILDREN
				p=p->rchild;
			else if(p->rchild==NULL)	//IF RCHILD
				p=p->lchild;
			temp=NULL;
			delete(temp);		//DELETE NODE
		}
		return p;
	}
}
template <class T>
void bst <T> :: NR_delete(T x)
{
	tnode<T> *temp,*t,*q;
	if(root==NULL)
	{
		cout<<"\nTREE IS EMPTY";
		return;
	}
	else
	{
		t=root;
		while(t!=NULL)
		{
			if(x<t->data)
			{	q=t;
				t=t->lchild;
			}
			else if(x>t->data)
			{
				q=t;
				t=t->rchild;
			}
			else
			{
				cout<<"\nNODE FOUND.";
				if(t->lchild && t->rchild)
				{
					q=t;
					temp=successor(t->rchild);
					while(q->lchild!=temp && q->rchild!=temp)
					{
						if(q->data > temp->data)
							q=q->lchild;
						else if(q->data < temp->data)
							q=q->rchild;
					}
					t->data=temp->data;
					if(q->lchild==temp)
					{	if(temp->rchild!=NULL)
						q->lchild=temp->rchild;
						else
						q->lchild=NULL;
					}
					else

					{	if(temp->rchild!=NULL)
						q->rchild=temp->rchild;
						else
						q->rchild=NULL;
					}
				}
				else
				{
					temp=t;
					if(t==root)
					{
						if(t->rchild!=NULL)
						t=t->rchild;
						else
							t=t->lchild;
						root=t;
						delete(temp);
						cout<<"\nNODE SUCCESSFULLY DELETED.";
						return;
					}
					else if(t->lchild==NULL)
					{
						t=t->rchild;
					}
					else if(t->rchild==NULL)
					{
						t=t->lchild;
					}
					if(q->lchild==temp)
						q->lchild=t;
					if(q->rchild==temp)
						q->rchild=t;
				}
				delete(temp);
				cout<<"\nNODE SUCCESSFULLY DELETED.";
				return;
			}
		}
		if(t==NULL)
			cout<<"\nNODE NOT FOUND";
	}
}

int main()
{
	bst <string> A;	//CREATING OBJECT OF BST
	tnode <string> *temp,*temp1=NULL;
	int ch,ch1;
	string info,key;
	do
	{
		cout<<"\n\nBINARY SEARCH TREE\nMENU\n1.BINARY TREE CREATION\n2"
				".DISPLAY\n3.MIRROR IMAGE\n4.SEARCH\n5.DELETE\n6.HEIGHT\n7.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
		case 1:
				cout<<"\nENTER THE DATA TO ENTER:-";
				cin>>info;
				cout<<"\n1].RECURSIVE INSERT \n2].NON_RECURSIVE INSERT\nENTER UR CHOICE:-";
				cin>>ch1;
				switch(ch1)
				{
				case 1:
					A.insert1(info);		//CALLING RECURSIVE INSERT
					cout<<"\nINORDER TRAVERSAL:-";
					A.R_inorder(A.retroot());
					break;
				case 2:
					A.binsert(info);	//CALLING NON RECURSIVE INSERT
					cout<<"\nINORDER TRAVERSAL:-";
					A.R_inorder(A.retroot());
					break;
				}
				break;

		case 2:
				if(A.retroot()!=NULL)
				{
					cout<<"\nPREORDER TRAVERSAL:-";	//PREORDER TRAVERSAL
					A.R_preorder(A.retroot());
					cout<<"\nINORDER TRAVERSAL:-";	//INORDER TRAVERSAL
					A.R_inorder(A.retroot());
					cout<<"\nPOSTORDER TRAVERSAL:-";	//POSTORDER TRAVERSAL
					A.R_postorder(A.retroot());
					cout<<"\nLEVELORDER TRAVERSAL:-";	//LEVELORDER TRAVERSAL
					A.levelorder(A.retroot());
				}
				else
				{
					cout<<"\nTREE IS EMPTY.";
				}
				break;

		case 3:
				if(A.retroot()!=NULL)
				{
					cout<<"\n1].NON-RECURSIVE MIRROR \n2]RECURSIVE MIRROR\nENTER UR CHOICE:-";
					cin>>ch1;
					switch(ch1)
					{
					case 1:
							cout<<"\nMIRROR OF THE TREE-->";
							temp=A.NR_mirror();				//CALLING NON-RECURSIVE MIRROR FUNCTION
							cout<<"\nPREORDER TRAVERSAL:-";
							A.R_preorder(temp);
							cout<<"\nINORDER TRAVERSAL:-";
							A.R_inorder(temp);
							cout<<"\nPOSTORDER TRAVERSAL:-";
							A.R_postorder(temp);
							cout<<"\nLEVELORDER TRAVERSAL:-";
							A.levelorder(temp);
							break;
					case 2:
							cout<<"\nMIRROR OF THE TREE-->";
							temp=A.mirror(A.retroot());		//CALLING RECURSIVE MIRROR FUNCTION
							cout<<"\nPREORDER TRAVERSAL:-";
							A.R_preorder(temp);
							cout<<"\nINORDER TRAVERSAL:-";
							A.R_inorder(temp);
							cout<<"\nPOSTORDER TRAVERSAL:-";
							A.R_postorder(temp);
							cout<<"\nLEVELORDER TRAVERSAL:-";
							A.levelorder(temp);
							break;
					}
				}
				else
				{
					cout<<"\nTREE IS EMPTY.";
				}
				break;

		case 4:
				cout<<"\nENTER THE NODE TO BE SEARCHED:-";
				cin>>key;
				temp=A.search(key);		//CALLING SEARCH
				if(temp!=NULL)			//IF NODE FOUND
				{
					cout<<"\nNODE FOUND.\nDATA IN THE NODE IS:-\t";
					cout<<"\t"<<temp->data;
				}
				else		//NOT FOUND
				{
					cout<<"\nNODE NOT FOUND.";
				}
				break;
		case 5:
				cout<<"\nWHICH NODE IS TO BE DELETED ?";
				cin>>key;
				cout<<"\n1]RECURSIVE DELETE\n2]NON-"
						"RECURSIVE DELETE\nENTER UR CHOICE:-";
				cin>>ch1;
				switch(ch1)
				{
				case 1:
						if(A.retroot()!=NULL)
						{
							temp1=A.delete1(key);		//CALLING RECURSIVE DELETE
							if(temp1!=NULL)
								cout<<"\nNODE IS SUCCESSFULLY DELETED.";
						}
						break;
				case 2:
						A.NR_delete(key);
						break;
				}
				break;
		case 6:
				int h=A.height();		//CALLING HEIGHT
				cout<<"\nHEIGHT OF TREE IS:-\t"<<h;
				break;

		}
	}while(ch!=7);
	return 0;
}

/*
 * OUTPUT:-
 *


BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-abc

1].RECURSIVE INSERT
2].NON_RECURSIVE INSERT
ENTER UR CHOICE:-1

INORDER TRAVERSAL:-	abc

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-bcd

1].RECURSIVE INSERT
2].NON_RECURSIVE INSERT
ENTER UR CHOICE:-1

INORDER TRAVERSAL:-	abc	bcd

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-asd

1].RECURSIVE INSERT
2].NON_RECURSIVE INSERT
ENTER UR CHOICE:-2

INORDER TRAVERSAL:-	abc	asd	bcd

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-qwerty

1].RECURSIVE INSERT
2].NON_RECURSIVE INSERT
ENTER UR CHOICE:-1

INORDER TRAVERSAL:-	abc	asd	bcd	qwerty

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-aaa

1].RECURSIVE INSERT
2].NON_RECURSIVE INSERT
ENTER UR CHOICE:-1

INORDER TRAVERSAL:-	aaa	abc	asd	bcd	qwerty

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-5

WHICH NODE IS TO BE DELETED ?asd

1]RECURSIVE DELETE
2]NON-RECURSIVE DELETE
ENTER UR CHOICE:-2

NODE FOUND.
NODE SUCCESSFULLY DELETED.

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-2

PREORDER TRAVERSAL:-	abc	aaa	bcd	qwerty
INORDER TRAVERSAL:-	aaa	abc	bcd	qwerty
POSTORDER TRAVERSAL:-	aaa	qwerty	bcd	abc
LEVELORDER TRAVERSAL:-	abc	aaa	bcd	qwerty

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-5

WHICH NODE IS TO BE DELETED ?abc

1]RECURSIVE DELETE
2]NON-RECURSIVE DELETE
ENTER UR CHOICE:-2

NODE FOUND.
NODE SUCCESSFULLY DELETED.

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-2

PREORDER TRAVERSAL:-	bcd	aaa	qwerty
INORDER TRAVERSAL:-	aaa	bcd	qwerty
POSTORDER TRAVERSAL:-	aaa	qwerty	bcd
LEVELORDER TRAVERSAL:-	bcd	aaa	qwerty

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-3

1].NON-RECURSIVE MIRROR
2]RECURSIVE MIRROR
ENTER UR CHOICE:-4


BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-3

1].NON-RECURSIVE MIRROR
2]RECURSIVE MIRROR
ENTER UR CHOICE:-2

MIRROR OF THE TREE-->
PREORDER TRAVERSAL:-	bcd	qwerty	aaa
INORDER TRAVERSAL:-	qwerty	bcd	aaa
POSTORDER TRAVERSAL:-	qwerty	aaa	bcd
LEVELORDER TRAVERSAL:-	bcd	qwerty	aaa

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-4

ENTER THE NODE TO BE SEARCHED:-bcd

NODE FOUND.
DATA IN THE NODE IS:-		bcd

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-6

HEIGHT OF TREE IS:-	1

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-2

PREORDER TRAVERSAL:-	bcd	aaa	qwerty
INORDER TRAVERSAL:-	aaa	bcd	qwerty
POSTORDER TRAVERSAL:-	aaa	qwerty	bcd
LEVELORDER TRAVERSAL:-	bcd	aaa	qwerty

BINARY SEARCH TREE
MENU
1.BINARY TREE CREATION
2.DISPLAY
3.MIRROR IMAGE
4.SEARCH
5.DELETE
6.HEIGHT
7.EXIT
ENTER UR CHOICE:-7


 */

