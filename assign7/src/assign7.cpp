//============================================================================
// Name        : assign7.cpp
// Author      : PRAVIN SALUNKHE
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
struct sparse
{
	int start;
	int end;
	float value;
};
class graph
{
		struct sparse s[20];
public:
		void input(int row,int col);
		void display();
		void sort();
		void swap(int x,int y);
		void kruskal(int no);
};

void graph :: input(int row,int col)
{
	int i,j;
	float mat[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<"\nENTER THE WEIGHT BETWEEN VERTEX "<<i<<" AND "<<j<<" :-";
			cin>>mat[i][j];
		}
	}
	(s+0)->start=row;(s+0)->end=col;
	i=0;j=0;
	int k=1;
	for(i=0;i<row;i++)
		{
			for(j=i;j<col;j++)
			{
				if(mat[i][j]!=0)
				{
					(s+k)->start=i;
					(s+k)->end=j;
					(s+k)->value=mat[i][j];
					k++;
				}
			}
		}
	(s+0)->value=k-1;
}
void graph :: display()
{
	int i;
	cout<<"\nSTART\tEND\tVALUE";
	for(i=0;i<=(s+0)->value;i++)
	{
		cout<<"\n"<<(s+i)->start<<"\t"<<(s+i)->end
		<<"\t"<<(s+i)->value;
	}
}
void graph :: sort()
{
	int last,j,i,swaps=0;
	  	last=(int)(s+0)->value;

	 	for(i=1;i<=(s+0)->value;i++)
	 	{
	 		swaps=0;
	 		for(j=1;j<last;j++)
	 		{
	 			if((s+j)->value>(s+j+1)->value)
	 			{
	 				swap(j,j+1);
	 				swaps=swaps+1;
	 			}
	 		}
	 		if(swaps==0)
	 		{
	 			display();
	 			return;
	 		}
	 		else
	 			last=last-1;
	 	}
}
void graph :: swap(int x,int y)
{
	sparse t;
	t.start=(s+x)->start;
	(s+x)->start=(s+y)->start;
	(s+y)->start=t.start;
	t.value=(s+x)->value;
	(s+x)->value=(s+y)->value;
	(s+y)->value=t.value;
	t.end=(s+x)->end;
	(s+x)->end=(s+y)->end;
	(s+y)->end=t.end;
}

void graph :: kruskal(int no)
{
	int set[no];
	int u1,u2,i=1,count=0;
	for(int j=0;j<no;j++)
	{
		set[j]=j;
	}
	while(count<no-1)
	{
		u1=set[(s+i)->start];
		u2=set[(s+i)->end];
		if(u1!=u2)
		{
			cout<<"\n"<<(s+i)->start<<"\t"<<(s+i)->end<<"\t"<<(s+i)->value;
			for(int j=0;j<no;j++)
			{
				if(set[j]==u2)
					set[j]=u1;
			}
			count++;
		}
		i++;
	}
}
int main()
{
	graph g;
	int ch,no;
	do
	{
		cout<<"\n1.INPUT ADJACENCY MATRIX FOR GRAPH\n2.DISPLAY NON-ZERO EDGES\n"
				"3.MINIMUM SPANNING TREE\n4.EXIT\nENTER UR CHOICE:- ";
		cin>>ch;
		switch(ch)
		{
		case 1:
				cout<<"\nENTER THE NO OF VERTICES:- ";
				cin>>no;
				g.input(no,no);
				break;
		case 2:
				g.sort();
				break;
		case 3:
				cout<<"\nSTART\tEND\tVALUE";
				g.kruskal(no);
				break;
		}
	}while(ch!=4);

	return 0;
}
/*OUTPUT:-
 *
1.INPUT ADJACENCY MATRIX FOR GRAPH
2.DISPLAY NON-ZERO EDGES
3.MINIMUM SPANNING TREE
4.EXIT
ENTER UR CHOICE:- 1

ENTER THE NO OF VERTICES:- 4

ENTER THE WEIGHT BETWEEN VERTEX 0 AND 0 :-0

ENTER THE WEIGHT BETWEEN VERTEX 0 AND 1 :-8

ENTER THE WEIGHT BETWEEN VERTEX 0 AND 2 :-7

ENTER THE WEIGHT BETWEEN VERTEX 0 AND 3 :-10

ENTER THE WEIGHT BETWEEN VERTEX 1 AND 0 :-8

ENTER THE WEIGHT BETWEEN VERTEX 1 AND 1 :-0

ENTER THE WEIGHT BETWEEN VERTEX 1 AND 2 :-11

ENTER THE WEIGHT BETWEEN VERTEX 1 AND 3 :-0

ENTER THE WEIGHT BETWEEN VERTEX 2 AND 0 :-7

ENTER THE WEIGHT BETWEEN VERTEX 2 AND 1 :-11

ENTER THE WEIGHT BETWEEN VERTEX 2 AND 2 :-0

ENTER THE WEIGHT BETWEEN VERTEX 2 AND 3 :-9

ENTER THE WEIGHT BETWEEN VERTEX 3 AND 0 :-10

ENTER THE WEIGHT BETWEEN VERTEX 3 AND 1 :-0

ENTER THE WEIGHT BETWEEN VERTEX 3 AND 2 :-9

ENTER THE WEIGHT BETWEEN VERTEX 3 AND 3 :-0

1.INPUT ADJACENCY MATRIX FOR GRAPH
2.DISPLAY NON-ZERO EDGES
3.MINIMUM SPANNING TREE
4.EXIT
ENTER UR CHOICE:- 2

START	END	VALUE
4	4	5
0	2	7
0	1	8
2	3	9
0	3	10
1	2	11
1.INPUT ADJACENCY MATRIX FOR GRAPH
2.DISPLAY NON-ZERO EDGES
3.MINIMUM SPANNING TREE
4.EXIT
ENTER UR CHOICE:- 3

START	END	VALUE
0	2	7
0	1	8
2	3	9
1.INPUT ADJACENCY MATRIX FOR GRAPH
2.DISPLAY NON-ZERO EDGES
3.MINIMUM SPANNING TREE
4.EXIT
ENTER UR CHOICE:- 4

 */
