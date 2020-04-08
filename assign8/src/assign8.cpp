//============================================================================
// Name        : assign8.cpp
// Author      : Pravin Salunkhe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * SE-10
 * G-10
 * 23257
 * PROBLEM STATEMENT:- IMPLEMENT DJIKSTRAS ALGORITHM FOR A GIVEN GRAPH.
 */
#include <iostream>
#include <iomanip>
using namespace std;

class graph		//class declaration
{
	float **mat;	//double pointer for dynamic 2-D array allocation
public:
		void input(int row,int col);	//PUBLIC MEMBER FUNCTIONS
		void display();
		void djikstras(int n,int st);
};
void graph :: input(int row,int col)	//INPUT FUNCTION
{
	int i,j;
	mat = new float*[row];			//MEMORY ALLOCATION FOR 2-D ARRAY
	for(int i = 0; i < row; ++i)
	    mat[i] = new float[col];

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<"\nENTER THE WEIGHT BETWEEN CITY "<<i<<" AND CITY "<<j<<" :-";
			cin>>mat[i][j];			//GETTING COST BETWEEN LINKS
			if(mat[i][j]==0)
				mat[i][j]=32767;	//NO LINK BETWEEN THESE CITIES
		}
	}
}

void graph :: djikstras(int n,int st)		//PRIMS ALGORITHM
{
	float display[n];
	float visited[n];		//FOR CHECKING IF  NODE IS VISITED OR NOT
	float parent[n];		//FOR KEEPING TRACK OF PARENT
	float dist[n];			//FOR STORING DIST BETWEEN NODES
	float min=32767;
	int count,i,u,w,distance=0;
	for(i=0;i<n;i++)		//INITIALIZATION
	{
		visited[i]=0;
		parent[i]=-1;
		dist[i]=32767;
	}
	count=0;
	for(i=0;i<n;i++)
	{
		dist[i]=mat[st][i];		//INITIALIZE DISTANCES
		visited[i]=0;			//INITIALIZE VISITED
		if(mat[st][i]!=32767)
			parent[i]=st;		//INITIALIZE PARENT NODE
	}
	visited[st]=1;
	dist[st]=0;
	count=1;
	while(count<n)		//TILL ALL VERTICES ARE VISITED
	{
		min=32767;
		for(i=0;i<n;i++)
		{
			if(visited[i]!=1)		//IF NOT VISITED
			{
				if(dist[i]<min)		//FIND MIN DIST VERTEX
				{
					min=dist[i];
					u=i;
				}
			}
		}
		visited[u]=1;			//MARK AS VISITED
		for(w=0;w<n;w++)
		{
			if(mat[u][w]!=32767 && visited[w]!=1)
			{
				if(dist[w]>=dist[u]+mat[u][w])		//FIND MIN DIST BETWEEN VERTICES
				{
					dist[w]=dist[u]+mat[u][w];
					parent[w]=u;
				}
			}
		}
		count+=1;
	}

	cout<<"\n"<<setw(16)<<setiosflags(ios::left)<<"|SOURCE"<<setw(15)<<setiosflags(ios::left)<<"|DESTINATION"
			<<setw(16)<<setiosflags(ios::left)<<"|DISTANCE"
			<<setw(30)<<setiosflags(ios::left)<<"|PATH\n";
	for(i=0;i<n;i++)
	{
		if(i!=st)		//DISPLAY LOGIC
		{
			cout<<"\n|"<<setw(15)<<setiosflags(ios::left)<<st<<"|"<<setw(15)<<setiosflags(ios::left)<<i;
			int j=0,l=i;
			display[j]=i;
			j++;
			while(l!=st)
			{

				display[j]=parent[l];
				l=parent[l];
				j++;
			}
			cout<<setw(15)<<setiosflags(ios::left)<<dist[i];;
			j-=1;
			cout<<"|";
			while(j>=0)
			{
				cout<<display[j];
				if(j!=0)
					cout<<"->";
				j--;
			}
		}
	}
}
int main()
{
	int ch,n,s;
	graph g;	//DECLARE OBJECT OF GRAPH CLASS
	do
	{
	cout<<"\nAPPLICATION OF DJIKSTRA's ALGORITHM\n";
	cout<<"\nMENU\n1.ENTER DISTANCES BETWEEN VERTICES\n2.FIND SHORTEST CONNECTION-SINGLE SOURCE MULTIPLE DESTINATION"
			"\n3.FIND SHORTEST CONNECTION-MULTIPLE SOURCE MULTIPLE DESTINATION\n4.EXIT\nENTER UR CHOICE:- ";
	cin>>ch;
		switch(ch)
		{
		case 1:
				cout<<"\nENTER THE NO OF VERTICES IN THE BUSINESS HOUSE:- ";
				cin>>n;
				g.input(n,n);
				break;
		case 2:
				cout<<"\nENTER THE NUMBER OF THE SOURCE VERTEX::";
				cin>>s;
				g.djikstras(n,s);
				break;
		case 3:
				for(int i=0;i<n;i++)
				{
					g.djikstras(n,i);
					cout<<"\n";
				}
				break;
		}
	}while(ch!=4);
	return 0;
}
/*OUTPUT:-
 *
APPLICATION OF DJIKSTRA's ALGORITHM

MENU
1.ENTER DISTANCES BETWEEN VERTICES
2.FIND SHORTEST CONNECTION-SINGLE SOURCE MULTIPLE DESTINATION
3.FIND SHORTEST CONNECTION-MULTIPLE SOURCE MULTIPLE DESTINATION
4.EXIT
ENTER UR CHOICE:- 1

ENTER THE NO OF VERTICES IN THE BUSINESS HOUSE:- 7

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 0 :-0

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 1 :-9

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 2 :-1

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 3 :-0

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 4 :-0

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 5 :-0

ENTER THE WEIGHT BETWEEN CITY 0 AND CITY 6 :-0

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 0 :-9

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 1 :-0

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 2 :-5

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 3 :-19

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 4 :-17

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 5 :-0

ENTER THE WEIGHT BETWEEN CITY 1 AND CITY 6 :-0

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 0 :-1

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 1 :-5

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 2 :-0

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 3 :-0

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 4 :-13

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 5 :-0

ENTER THE WEIGHT BETWEEN CITY 2 AND CITY 6 :-0

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 0 :-0

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 1 :-19

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 2 :-0

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 3 :-0

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 4 :-25

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 5 :-2

ENTER THE WEIGHT BETWEEN CITY 3 AND CITY 6 :-0

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 0 :-0

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 1 :-17

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 2 :-13

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 3 :-25

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 4 :-0

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 5 :-14

ENTER THE WEIGHT BETWEEN CITY 4 AND CITY 6 :-21

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 0 :-0

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 1 :-0

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 2 :-0

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 3 :-2

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 4 :-14

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 5 :-0

ENTER THE WEIGHT BETWEEN CITY 5 AND CITY 6 :-8

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 0 :-0

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 1 :-0

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 2 :-0

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 3 :-0

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 4 :-21

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 5 :-8

ENTER THE WEIGHT BETWEEN CITY 6 AND CITY 6 :-0

APPLICATION OF DJIKSTRA's ALGORITHM

MENU
1.ENTER DISTANCES BETWEEN VERTICES
2.FIND SHORTEST CONNECTION-SINGLE SOURCE MULTIPLE DESTINATION
3.FIND SHORTEST CONNECTION-MULTIPLE SOURCE MULTIPLE DESTINATION
4.EXIT
ENTER UR CHOICE:- 2

ENTER THE NUMBER OF THE SOURCE VERTEX::3

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|3              |0              25             |3->1->2->0
|3              |1              19             |3->1
|3              |2              24             |3->1->2
|3              |4              16             |3->5->4
|3              |5              2              |3->5
|3              |6              10             |3->5->6
APPLICATION OF DJIKSTRA's ALGORITHM

MENU
1.ENTER DISTANCES BETWEEN VERTICES
2.FIND SHORTEST CONNECTION-SINGLE SOURCE MULTIPLE DESTINATION
3.FIND SHORTEST CONNECTION-MULTIPLE SOURCE MULTIPLE DESTINATION
4.EXIT
ENTER UR CHOICE:- 3

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|0              |1              6              |0->2->1
|0              |2              1              |0->2
|0              |3              25             |0->2->1->3
|0              |4              14             |0->2->4
|0              |5              27             |0->2->1->3->5
|0              |6              35             |0->2->1->3->5->6

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|1              |0              6              |1->2->0
|1              |2              5              |1->2
|1              |3              19             |1->3
|1              |4              17             |1->4
|1              |5              21             |1->3->5
|1              |6              29             |1->3->5->6

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|2              |0              1              |2->0
|2              |1              5              |2->1
|2              |3              24             |2->1->3
|2              |4              13             |2->4
|2              |5              26             |2->1->3->5
|2              |6              34             |2->1->3->5->6

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|3              |0              25             |3->1->2->0
|3              |1              19             |3->1
|3              |2              24             |3->1->2
|3              |4              16             |3->5->4
|3              |5              2              |3->5
|3              |6              10             |3->5->6

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|4              |0              14             |4->2->0
|4              |1              17             |4->1
|4              |2              13             |4->2
|4              |3              16             |4->5->3
|4              |5              14             |4->5
|4              |6              21             |4->6

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|5              |0              27             |5->3->1->2->0
|5              |1              21             |5->3->1
|5              |2              26             |5->3->1->2
|5              |3              2              |5->3
|5              |4              14             |5->4
|5              |6              8              |5->6

|SOURCE         |DESTINATION   |DISTANCE       |PATH

|6              |0              35             |6->5->3->1->2->0
|6              |1              29             |6->5->3->1
|6              |2              34             |6->5->3->1->2
|6              |3              10             |6->5->3
|6              |4              21             |6->4
|6              |5              8              |6->5

APPLICATION OF DJIKSTRA's ALGORITHM

MENU
1.ENTER DISTANCES BETWEEN VERTICES
2.FIND SHORTEST CONNECTION-SINGLE SOURCE MULTIPLE DESTINATION
3.FIND SHORTEST CONNECTION-MULTIPLE SOURCE MULTIPLE DESTINATION
4.EXIT
ENTER UR CHOICE:- 4

 */
