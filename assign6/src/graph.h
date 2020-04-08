/*
 * graph.h
 *
 *  Created on: 11-Feb-2016
 *      Author: g10
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <string.h>
#include "queue.h"
#include <stack>
using namespace std;

struct data
{
	char name[30];
	int date;
	int month;
	int year;
	int ID;
};
struct user
{
	data d;
	struct user *dlink;
	struct link *next;
};
struct link
{
	char name[30];
	int comments;
	struct link *next;
	struct user *address;
};

class graph
{
		user *g_head;
		int i;
	public:
		user *getnode();
		link *getnode1();
		user *create(int v);
		int count();
		void display();
		void BFS();
		void DFS();
		void dfs1();
		void rec_dfs(user *temp,int v,int nodecount,int visited[50]);
		void add_user();
		void add_friend(char *name1,char *name2);
		link *insert_last(link *head1,char name[30],user *f);
		void max_friends();
		void max_comments();
		void dob(int month);
		graph();
		virtual ~graph();
};

#endif /* GRAPH_H_ */
