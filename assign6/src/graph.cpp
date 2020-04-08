/*
 * graph.cpp
 *
 *  Created on: 11-Feb-2016
 *      Author: g10
 */
#include "queue.h"
#include "queue.cpp"
#include "graph.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <stack>
using namespace std;

graph::graph()
{
	// TODO Auto-generated constructor stub
	g_head=NULL;
	i=0;
}

graph::~graph()
{
	// TODO Auto-generated destructor stub
}
int graph :: count()
{
	int v=0;
	user *temp=g_head;
	while(temp!=NULL)
	{
		v++;
		temp=temp->dlink;
	}
	return v;
}
user *graph :: getnode()
{
	user *temp=NULL;
	temp=new user();

	cout<<"\nENTER THE NAME OF THE USER:-";
	cin.ignore();
	cin.getline(temp->d.name,40);
	cout<<"\nENTER THE DOB OF THE USER:-\n1.DATE:- ";
	cin>>temp->d.date;
	while(temp->d.date<=0 || temp->d.date>31)
	{
		cout<<"\nENTER A VALID DATE";
		cin>>temp->d.date;
	}
	cout<<"\n2.MONTH:- ";
	cin>>temp->d.month;
	while(temp->d.month<=0 || temp->d.month>12)
	{
		cout<<"\nENTER A VALID MONTH";
		cin>>temp->d.month;
	}
	cout<<"\n3.YEAR:- ";
	cin>>temp->d.year;

	temp->next=NULL;
	return temp;

}
void graph :: display()
{
	user *temp=g_head;
	link *f=NULL;
	while(temp!=NULL)
	{
		cout<<"\n|"<<setw(10)<<setiosflags(ios::left)<<temp->d.ID+1;
		cout<<"|"<<setw(20)<<setiosflags(ios::left)<<temp->d.name;
		cout<<"|"<<setw(2)<<setiosflags(ios::left)<<temp->d.date<<"/";
		cout<<setw(2)<<setiosflags(ios::left)<<temp->d.month<<"/";
		cout<<setw(9)<<setiosflags(ios::left)<<temp->d.year;
		f=temp->next;
		while(f!=NULL)
		{
			cout<<"|"<<f->name<<"("<<f->comments<<")";
			if(f->next!=NULL)
			cout<<",";
			f=f->next;
		}
		temp=temp->dlink;
		cout<<"\n--------------------------------------------------------------------------------";
	}
}
link *graph :: getnode1()
{
	link *temp=NULL;
	temp=new link();
	temp->next=NULL;
	return temp;
}
user* graph :: create(int v)
{
	user *temp=NULL;
	g_head=getnode();
	g_head->d.ID=i;
	temp=g_head;
	i=i+1;
	while(i<v)
	{
		temp->dlink=getnode();
		temp=temp->dlink;
		temp->d.ID=i;
		i++;
	}
		return g_head;
}
void graph :: add_user()
{
	user *temp=g_head,*temp1=NULL;
	while(temp->dlink!=NULL)
	{
		temp=temp->dlink;
	}
	temp1=getnode();
	temp1->d.ID=i;
	i++;
	temp->dlink=temp1;
}
void graph :: add_friend(char name1[30],char name2[30])
{
	user *u=g_head;
	user *f=g_head;
	link *head1=NULL;
		while(u!=NULL && strcmp(u->d.name,name1)!=0)
		{
			u=u->dlink;
		}
		while(f!=NULL && strcmp(f->d.name,name2)!=0)
		{
			f=f->dlink;
		}
		if(u==NULL)
		{
			cout<<"\nUSER1 DOES NOT EXIST.";
			return;
		}
		if(f==NULL)
		{
			cout<<"\nUSER2 DOES NOT EXIST.";
			return;
		}
		if(u==f)
		{
			cout<<"\nUSER CANNOT BE FRIEND OF ITSELF.";
			return;
		}
		if(strcmp(u->d.name,name1)==0)
		{
				head1=u->next;
				head1=insert_last(head1,name2,f);
				u->next=head1;
				head1=f->next;
				head1=insert_last(head1,name1,u);
				f->next=head1;
		}
}

link *graph :: insert_last(link *head1,char name[30],user *f)
{
	link *temp2=NULL;
	link *temp=head1;
	if(temp==NULL)
	{
		temp=getnode1();
		temp->next=NULL;
		strcpy(temp->name,name);
		temp->address=f;
		cout<<"\nENTER THE NO. OF COMMENTS '"<<temp->name<<"' HAS  TO HIS FRIEND:- ";
		cin>>temp->comments;
		head1=temp;
		return head1;
	}
	if(strcmp(temp->name,name)==0)
	{
		cout<<"\nUSERS ARE ALREADY FRIENDS.";
		return head1;
	}
	while(temp->next!=NULL)
	{
		if(strcmp(temp->name,name)==0)
		{
			cout<<"\nUSERS ARE ALREADY FRIENDS.";
			return head1;
		}
		temp=temp->next;
	}
	if(strcmp(temp->name,name)==0)
	{
		cout<<"\nUSERS ARE ALREADY FRIENDS.";
		return head1;
	}
	temp2=getnode1();
	temp->next=temp2;
	strcpy(temp2->name,name);
	temp2->address=f;
	cout<<"\nENTER THE NO. OF COMMENTS '"<<temp2->name<<"' HAS GIVEN TO HIS FRIEND:- ";
	cin>>temp2->comments;
	return head1;

}

void graph :: BFS()
{
	queue <user*> q;
	user *temp=g_head,*temp1=NULL;
	link *f=NULL;
	int visited[50]={-1};
	int nodecount=0;
	int v=count();

	q.enqueue(temp);
	while(!q.isEmpty() && nodecount<v)
	{
		temp1=q.dequeue();
		if(visited[temp1->d.ID]!=1)
		{
			cout<<"\t"<<temp1->d.name;
			visited[temp1->d.ID]=1;
			nodecount++;
		}
		f=temp1->next;
		while(f!=NULL)
		{
			if(visited[f->address->d.ID]!=1)
			q.enqueue(f->address);
			f=f->next;
		}
	}
}

void graph :: DFS()
{
	stack <user*> s;
	user *temp=g_head,*temp1=NULL;
	link *f=NULL;
	int visited[50]={-1};
	int nodecount=0;
	int v=count();

	s.push(temp);
	while(!s.empty() && nodecount<v)
	{
		temp1=s.top();
		s.pop();
		if(visited[temp1->d.ID]!=1)
		{
			cout<<"\t"<<temp1->d.name;
			visited[temp1->d.ID]=1;
			nodecount++;
		}
		f=temp1->next;
		while(f!=NULL)
		{
			if(visited[f->address->d.ID]!=1)
				s.push(f->address);
			f=f->next;
		}
	}
}
void graph :: dfs1()
{
	user *temp=g_head;
	link *f=NULL;
	int v=count();
	int nodecount=0;
	int visited[50]={-1};

	cout<<"\t"<<temp->d.name;
	visited[temp->d.ID]=1;
	nodecount+=1;
	f=temp->next;

	while(f!=NULL)
	{
		if(visited[f->address->d.ID]!=1 )
		{
			rec_dfs(f->address,v,nodecount,visited);
		}
		f=f->next;
	}

}

void graph :: rec_dfs(user *temp,int v,int nodecount,int visited[50])
{
	link *f=NULL;

	cout<<"\t"<<temp->d.name;

	visited[temp->d.ID]=1;
	nodecount+=1;

	f=temp->next;

	if(nodecount==v)
	return;

	while(f!=NULL)
	{
		if(visited[f->address->d.ID]!=1 )
		{
			rec_dfs(f->address,v,nodecount,visited);
		}
		f=f->next;
	}

}
void graph :: max_friends()
{
	user *temp=g_head;
	link *f=NULL;
	int count[50]={0};
	char max_friend[40];
	int i=0,max=-1;

	while(temp!=NULL)
	{
		f=temp->next;
		while(f!=NULL)
		{
			count[i]+=1;
			f=f->next;
		}
		if(max<count[i])
		{
			max=count[i];
			strcpy(max_friend,temp->d.name);
		}

		temp=temp->dlink;
		i++;
	}
	cout<<"\nUSER WITH MAXIMUM FRIENDS IS '"<<max_friend<<"' WITH "<<max<<" FRIENDS.\n";

}

void graph :: max_comments()
{
	user *temp=g_head;
	link *f=NULL;
	int count[50]={0};
	char max_comments[40];
	int i=0,max=-1;

	while(temp!=NULL)
	{
		f=temp->next;
		while(f!=NULL)
		{
			count[i]+=f->comments;
			f=f->next;
		}
		if(max<count[i])
		{
			max=count[i];
			strcpy(max_comments,temp->d.name);
		}

		temp=temp->dlink;
		i++;
	}
	cout<<"\nUSER WHO HAS RECIEVED MAXIMUM COMMENTS IS '"<<max_comments<<"' WITH "<<max<<" COMMENTS.\n";

}
void graph :: dob(int month)
{
	user *temp=g_head;
	int count=0;
	while(temp!=NULL)
	{
		if(temp->d.month==month)
		{
			cout<<"\n"<<temp->d.name<<"-->\t"<<temp->d.date<<"/"<<temp->d.month<<"/"<<temp->d.year;
			count++;
		}
		temp=temp->dlink;
	}
	if(count==0)
	{
		cout<<"\nSORRY,NO USERS WITH DOB IN THIS MONTH";
	}
}
