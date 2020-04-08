//============================================================================
// Name        : assign3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "binarytree.h"
//#include "binarytree.cpp"
/*SE-10
  G-10
  23257
  PROBLEM STATEMENT:-CREATE A BINARY TREE AND PERFORM FOLLOWING OPERATIONS:-
  1.INSERT
  2.DISPLAY
  3.HEIGHT
  4.COPY
  5.DISPLAY LEAF NODES
*/
int main()
{
	binary_tree T;	//create object
	tnode *temp;		//create copy tree
	int ch,h,info;
	do
	{
		cout<<"\n---------BINARY TREE--------\nMENU\n1.INSERT\n2.DISPLAY\n3.HEIGHT\n4.COPY TREE\n5.DISPLAY LEAF NODES"
				"\n6.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
		case 1:
				cout<<"\nENTER THE DATA TO ENTER:-";
				cin>>info;
				//T.insert(info);	//NON-RECURSIVE INSERT
				T.insert1(info);	//RECURSIVE INSERT
				cout<<"\nINORDER TRAVERSAL\t";
				T.R_inorder(T.ret_root());	//INORDER DISPLAY
				break;
		case 2:

				cout<<"\nPREORDER TRAVERSAL:-";
				T.R_preorder(T.ret_root());		//PREORDER TRAVERSAL
				cout<<"\nINORDER TRAVERSAL:-";
				T.R_inorder(T.ret_root());		//INORDER TRAVERSAL
				cout<<"\nPOSTORDER TRAVERSAL:-";
				T.R_postorder(T.ret_root());	//POSTORDER TRAVERSAL
				cout<<"\nLEVELORDER TRAVERSAL:-";
				T.levelorder();					//LEVELORDER TRAVERSAL
				break;
		case 3:

				h=T.height(T.ret_root());	//CALLING HEIGHT FUNCTION
				if(h==-1)
				{
					h=h+1;		//EXCEPTION FOR HEIGHT=0
				}
				cout<<"\nTHE HEIGHT OF THE TREE IS:-\t"<<h;
				break;
		case 4:

				cout<<"\nCOPY OF THE TREE-->";		//COPY OF TREE
				temp=T.copy_btree(T.ret_root());	//CALLING COPY FUNCTION
				cout<<"\nPREORDER TRAVERSAL:-";
				T.R_preorder(temp);
				cout<<"\nINORDER TRAVERSAL:-";
				T.R_inorder(temp);
				cout<<"\nPOSTORDER TRAVERSAL:-";
				T.R_postorder(temp);

				break;
		case 5:

				cout<<"\nLEAF NODES ARE :-";
				T.display_leaf(T.ret_root());	//CALLING DISPLAY LEAF
				break;
		}
	}while(ch!=6);
}
/*output:-

---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-1

INORDER TRAVERSAL		1
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-2

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-1

INORDER TRAVERSAL		2	1
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-3

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-2

INORDER TRAVERSAL		2	1	3
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-4

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-2

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-1

INORDER TRAVERSAL		2	1	4	3
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-5

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-2

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-2

INORDER TRAVERSAL		2	1	4	3	5
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-1

ENTER THE DATA TO ENTER:-6

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-1

WHERE TO INSERT THE NODE:-
1.LEFT
2.RIGHT
ENTER UR CHOICE:-1

INORDER TRAVERSAL		6	2	1	4	3	5
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-2

PREORDER TRAVERSAL:-	1	2	6	3	4	5
INORDER TRAVERSAL:-	6	2	1	4	3	5
POSTORDER TRAVERSAL:-	6	2	4	5	3	1
LEVELORDER TRAVERSAL:-	1	2	3	6	4	5
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-3

THE HEIGHT OF THE TREE IS:-	2
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-4

COPY OF THE TREE-->
PREORDER TRAVERSAL:-	1	2	6	3	4	5
INORDER TRAVERSAL:-	6	2	1	4	3	5
POSTORDER TRAVERSAL:-	6	2	4	5	3	1
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-5

LEAF NODES ARE :-	6	4	5
---------BINARY TREE--------
MENU
1.INSERT
2.DISPLAY
3.HEIGHT
4.COPY TREE
5.DISPLAY LEAF NODES
6.EXIT
ENTER UR CHOICE:-7

 */