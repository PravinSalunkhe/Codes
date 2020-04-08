/*
 * binarytree.cpp
 *
 *  Created on: 19-Jan-2019
 *      Author: admin1
 */

#include "binarytree.h"
#include<iostream>
using namespace std;

int max(int x,int y)	//MAX FUNCTION REQUIRED FOR HEIGHT
{
	if(x>=y)
		return x;		//X>Y
	else
		return y;		//Y>X
}

tnode *binary_tree :: ret_root()		//RETURN ROOT
{
	return root;
}
tnode *binary_tree :: maketree(int x)	//MAKETREE FUNCTION
{
	tnode *p;
	p= new tnode();		//ALLOCATING MEMORY FOR NODE
	p->data=x;			//GETTING DATA
	p->lchild=NULL;		//INITIALIZE NULL
	p->rchild=NULL;		//INITIALIZE NULL
	return p;
}

void binary_tree :: insert(int a)	//NON RECURSIVE FUNCTION
{
	tnode *q;
	int ch;
	if(root==NULL)			//IF ROOT IS NULL
	{
		root=maketree(a);	//CALL MAKETREE
	}
	else
	{
		q=root;			//INITIALIZE Q WITH ROOT
		do
		{
			cout<<"\nWHERE TO INSERT THE NODE:-\n1.LEFT\n2.RIGHT\nENTER UR CHOICE:-";
			cin>>ch;
			while(ch!=1 && ch!=2)		//VALIDATION FOR CHOICE
			{
				cout<<"\nPLEASE ENTER A VALID CHOICE";
				cin>>ch;
			}
			switch(ch)
			{
			case 1:						//IF CHOICE IS 1
					if(q->lchild==NULL)
					{
						q->lchild=maketree(a);	//INSERT ON LEFT
						return;
					}
					else
					{
						q=q->lchild;	//ELSE GO TO LEFT OF LEFT
					}
					break;
			case 2:						//IF CHOICE IS 2
					if(q->rchild==NULL)
					{
						q->rchild=maketree(a);	//INSERT ON RIGHT
						return;
					}
					else
					{
						q=q->rchild;	//ELSE GO TO RIGHT OF RIGHT
					}
					break;

			}
		}while(1);
	}
}

void binary_tree :: insert1(int a)
{
	root=Rec_insert(root,a);		//CALLING RECURSIVE INSERT
}
tnode *binary_tree :: Rec_insert(tnode *T,int a)
{
	tnode *q;
	int ch;
	if(T==NULL)
	{
		T=maketree(a);		//IF ROOT IS NULL,INSERT NODE
		return T;
	}
	else					//else
	{
		q=T;
		cout<<"\nWHERE TO INSERT THE NODE:-\n1.LEFT\n2.RIGHT\nENTER UR CHOICE:-";
		cin>>ch;			//get choice from user
					while(ch!=1 && ch!=2)		//choice validation
					{
						cout<<"\nPLEASE ENTER A VALID CHOICE";
						cin>>ch;
					}
					switch(ch)
					{
					case 1:
							q->lchild=Rec_insert(q->lchild,a);		//IF CHOICE IS 1,CALL THE FUNCTION RECURSIVELY AND
																	//RETURN TO LEFT CHILD OF Q
							break;
					case 2:
							q->rchild=Rec_insert(q->rchild,a);		//IF CHOICE IS 2,CALL THE FUNCTION RECURSIVELY AND
																	//RETURN TO RIGHT CHILD OF Q
							break;
					}

	}
}
void binary_tree :: R_preorder(tnode *T)			//PRE-ORDER TRAVERSAL
{
	if(T!=NULL)
	{
		cout<<"\t"<<T->data;		//FIRST DISPLAY THE NODE
		R_preorder(T->lchild);		//THEN CALL FOR LCHILD
		R_preorder(T->rchild);		//THEN CALL FOR RCHILD
	}

}

void binary_tree :: R_inorder(tnode *T)
{
	if(T!=NULL)
	{

		R_inorder(T->lchild);		//FIRST CALL FOR LCHILD
		cout<<"\t"<<T->data;		//THEN DISPLAY ROOT
		R_inorder(T->rchild);		//THE CALL FOR RCHILD
	}
}

void binary_tree :: R_postorder(tnode *T)
{
	if(T!=NULL)
	{
		R_postorder(T->lchild);		//FIRST CALL FOR LCHILD
		R_postorder(T->rchild);		//THEN CALL FOR RCHILD
		cout<<"\t"<<T->data;		//FINALLY DISPLAY ROOT
	}
}

void binary_tree :: levelorder()
{
	queue <tnode*> q;
	tnode *p=root;
	if(p==NULL)
	{
		cout<<"\nTREE IS EMPTY.";
		return;
	}
	else
	{
		q.enqueue(p);
		while(!q.isEmpty())
		{
			p=q.dequeue();
			cout<<"\t"<<p->data;
			if(p->lchild!=NULL)
				q.enqueue(p->lchild);
			if(p->rchild!=NULL)
				q.enqueue(p->rchild);
		}
	}

}


int binary_tree :: height(tnode *T)		//HEIGHT  OF TREE
{
	if(T==NULL)
		return -1;
	else
		return(1+max(height(T->lchild),height(T->rchild)));		/*IF TREE IS NOT EMPTY,SELECT THE MAXIMUM OF THE LEFT AND
																RIGHT SUBTREE*/
}

tnode *binary_tree :: copy_btree(tnode *T)			//COPY OF BINARY TREE
{
	tnode *temp=NULL;
	if(T==NULL)
		return T;				//IF TREE IS EMPTY
	else
	{
		int x=T->data;			//GET DATA OF NODE
		temp=maketree(x);		//ALLOCATE MEMORY
		temp->lchild=copy_btree(T->lchild);		//CALL FOR LCHILD
		temp->rchild=copy_btree(T->rchild);		//CALL FOR RCHILD
	}
	return temp;
}

void binary_tree :: display_leaf(tnode *T)		//LEAF NODES
{
	tnode *p=NULL;
	if(T==NULL)
		return;			//IF TREE IS EMPTY
	else
	{
		p=T;
		if(p->lchild==NULL && p->rchild==NULL)		//IF NO LEFT OR RIGHT NODE, DISPLAY THE NODE
		{
			cout<<"\t"<<p->data;
			return;
		}
		else		//ELSE
		{
			display_leaf(p->lchild);		//CALL FOR LEFT CHILD
			display_leaf(p->rchild);		//CALL FOR RIGHT CHILD
		}
	}
}
binary_tree::binary_tree()			//CONSTRUCTOR FUNCTION
{
	// TODO Auto-generated constructor stub
	root=NULL;						//INITIALIZE ROOT TO NULL
}

binary_tree::~binary_tree()			//DESTRUCTOR FUNCTION
{
	// TODO Auto-generated destructor stub
}
