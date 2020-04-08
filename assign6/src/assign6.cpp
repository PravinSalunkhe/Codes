//============================================================================
// Name        : assign6.cpp
// Author      : Pravin Salunkhe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 SE-10
 G-10
 23257
 PROBLEM STATEMENT:- CONSIDER A FREINDS NETWORK ON FACEBOOK.MODEL IT AS A GRAPH TO REPRESENT EACH NODE
 AS A USER AND A LINK TO REPRESENT THE FRIEND RELATIONSHIP BETWEEN THEM. STORE DATA SUCH AS DOB/NO.OF COMMENTS
 FOR EACH USER.
 USE ADJACENCY LIST REPRESENTATION TO PERFORM DFS AND BFS TRAVERSAL.
 */
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

#include "graph.h"


int main()
{
	graph g;
	char name1[30],name2[30];
	int ch,v,month;
	do
	{
		cout<<"\nGRAPH\n1.CREATE A GRAPH\n2.ADD USER\n3.ADD A FRIEND\n4.DISPLAY\n5.DFS TRAVERSAL\n6.BFS TRAVERSAL"
				"\n7.FIND USER WITH MAXIMUM FRIENDS\n8.FIND USER WHO HAS GOT MAXIMUM COMMENTS\n9.FIND USERS WITH"
				" DOB IN THIS MONTH\n10.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
		case 1:
				cout<<"\nENTER THE NO OF VERTICES:-";
				cin>>v;
				g.create(v);
				break;
		case 2:
				g.add_user();
				break;
		case 3:
				cout<<"\nENTER THE NAME OF THE USER1:-";
				cin.ignore();
				cin.getline(name1,30);
				cout<<"\nENTER THE NAME OF THE USER2:-";
				cin.getline(name2,30);
				g.add_friend(name1,name2);
				break;
		case 4:
				cout<<"\n**************************FACEBOOK PROTOTYPE*****************************\n";
				cout<<"-----------------------------------------------------------------"
						"---------------";
				cout<<"\n|"<<setw(10)<<setiosflags(ios::left)<<"USER ID"<<"|"
				<<setw(20)<<setiosflags(ios::left)<<"NAME"<<"|"<<setw(15)<<setiosflags(ios::left)<<"DATE OF BIRTH"<<"|"<<setw(20)
				<<setiosflags(ios::left)<<"FRIENDS(COMMENTS GIVEN)\n"
				"--------------------------------------------------------------------------------";
				g.display();
				break;
		case 5:
				cout<<"\n1]RECURSIVE\n2]NON-RECURSIVE\nENTER UR CHOICE:-";
				cin>>ch;
				switch(ch)
				{

				case 1:
						cout<<"\nDEPTH FIRST TRAVERSAL:- ";
						g.dfs1();
						break;
				case 2:
						cout<<"\nDEPTH FIRST TRAVERSAL:- ";
						g.DFS();
						break;
				}
				break;
		case 6:
				cout<<"\nBREADTH FIRST TRAVERSAL:-  ";
				g.BFS();
				break;
		case 7:
				g.max_friends();
				break;
		case 8:
				g.max_comments();
				break;
		case 9:
				cout<<"\nENTER THE CURRENT MONTH";
				cin>>month;
				while(month<=0 || month>12)
				{
					cout<<"\nENTER A VALID MONTH";
					cin>>month;
				}
				cout<<"\nUSER WITH DOB IN THIS MONTH ARE:-";
				g.dob(month);
		}

	}while(ch!=10);
	return 0;
}
/*OUTPUT:-
 *
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-1

ENTER THE NO OF VERTICES:-5

ENTER THE NAME OF THE USER:-abc

ENTER THE DOB OF THE USER:-
1.DATE:- 23

2.MONTH:- 3

3.YEAR:- 1999

ENTER THE NAME OF THE USER:-def

ENTER THE DOB OF THE USER:-
1.DATE:- 1

2.MONTH:- 1

3.YEAR:- 2111

ENTER THE NAME OF THE USER:-mno

ENTER THE DOB OF THE USER:-
1.DATE:- 30

2.MONTH:- 12

3.YEAR:- 2311

ENTER THE NAME OF THE USER:-pqr

ENTER THE DOB OF THE USER:-
1.DATE:- 5

2.MONTH:- 5

3.YEAR:- 2312

ENTER THE NAME OF THE USER:-xyz

ENTER THE DOB OF THE USER:-
1.DATE:- 21

2.MONTH:- 12

3.YEAR:- 1988

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-4

**************************FACEBOOK PROTOTYPE*****************************
--------------------------------------------------------------------------------
|USER ID   |NAME                |DATE OF BIRTH  |FRIENDS(COMMENTS GIVEN)
--------------------------------------------------------------------------------
|1         |abc                 |23/3 /1999
--------------------------------------------------------------------------------
|2         |def                 |1 /1 /2111
--------------------------------------------------------------------------------
|3         |mno                 |30/12/2311
--------------------------------------------------------------------------------
|4         |pqr                 |5 /5 /2312
--------------------------------------------------------------------------------
|5         |xyz                 |21/12/1988
--------------------------------------------------------------------------------
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-3

ENTER THE NAME OF THE USER1:-abc

ENTER THE NAME OF THE USER2:-pqr

ENTER THE NO. OF COMMENTS 'pqr' HAS  TO HIS FRIEND:- 44

ENTER THE NO. OF COMMENTS 'abc' HAS  TO HIS FRIEND:- 33

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-3

ENTER THE NAME OF THE USER1:-def

ENTER THE NAME OF THE USER2:-xyz

ENTER THE NO. OF COMMENTS 'xyz' HAS  TO HIS FRIEND:- 12

ENTER THE NO. OF COMMENTS 'def' HAS  TO HIS FRIEND:- 22

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-3

ENTER THE NAME OF THE USER1:-abc

ENTER THE NAME OF THE USER2:-xyz

ENTER THE NO. OF COMMENTS 'xyz' HAS GIVEN TO HIS FRIEND:- 11

ENTER THE NO. OF COMMENTS 'abc' HAS GIVEN TO HIS FRIEND:- 9

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-3

ENTER THE NAME OF THE USER1:-mno

ENTER THE NAME OF THE USER2:-pqr

ENTER THE NO. OF COMMENTS 'pqr' HAS  TO HIS FRIEND:- 4

ENTER THE NO. OF COMMENTS 'mno' HAS GIVEN TO HIS FRIEND:- 5

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-4

**************************FACEBOOK PROTOTYPE*****************************
--------------------------------------------------------------------------------
|USER ID   |NAME                |DATE OF BIRTH  |FRIENDS(COMMENTS GIVEN)
--------------------------------------------------------------------------------
|1         |abc                 |23/3 /1999     |pqr(44),|xyz(11)
--------------------------------------------------------------------------------
|2         |def                 |1 /1 /2111     |xyz(12)
--------------------------------------------------------------------------------
|3         |mno                 |30/12/2311     |pqr(4)
--------------------------------------------------------------------------------
|4         |pqr                 |5 /5 /2312     |abc(33),|mno(5)
--------------------------------------------------------------------------------
|5         |xyz                 |21/12/1988     |def(22),|abc(9)
--------------------------------------------------------------------------------
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-5

1]RECURSIVE
2]NON-RECURSIVE
ENTER UR CHOICE:-1

DEPTH FIRST TRAVERSAL:- 	abc	pqr	mno	xyz	def
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-5

1]RECURSIVE
2]NON-RECURSIVE
ENTER UR CHOICE:-2

DEPTH FIRST TRAVERSAL:- 	abc	xyz	def	pqr	mno
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-6

BREADTH FIRST TRAVERSAL:-  	abc	pqr	xyz	mno	def
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-7

USER WITH MAXIMUM FRIENDS IS 'abc' WITH 2 FRIENDS.

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-8

USER WHO HAS RECIEVED MAXIMUM COMMENTS IS 'abc' WITH 55 COMMENTS.

GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-9

ENTER THE CURRENT MONTH12

USER WITH DOB IN THIS MONTH ARE:-
mno-->	30/12/2311
xyz-->	21/12/1988
GRAPH
1.CREATE A GRAPH
2.ADD USER
3.ADD A FRIEND
4.DISPLAY
5.DFS TRAVERSAL
6.BFS TRAVERSAL
7.FIND USER WITH MAXIMUM FRIENDS
8.FIND USER WHO HAS GOT MAXIMUM COMMENTS
9.FIND USERS WITH DOB IN THIS MONTH
10.EXIT
ENTER UR CHOICE:-10

 */





