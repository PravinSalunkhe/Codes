/*
 * binarytree.h
 *
 *  Created on: 19-Jan-2019
 *      Author: admin1
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "queue.h"
#include "queue.cpp"
struct tnode			//DECLARING NODE STRUCTURE
{
	int data;		//DATA OF NODE
	struct tnode *lchild;		//LEFT POINTER
	struct tnode *rchild;		//RIGHT POINTER
};
class binary_tree		//CLASS DECLARATION
{
	tnode *root;	//PRIVATE MEMBER(ROOT)

public:
	binary_tree();			//PUBLIC MEMBERS
	virtual ~binary_tree();
	tnode *ret_root();
	tnode *maketree(int x);
	void insert(int a);
	void insert1(int a);
	tnode *Rec_insert(tnode *T,int a);
	void R_preorder(tnode *T);
	void R_inorder(tnode *T);
	void R_postorder(tnode *T);
	void levelorder();
	int height(tnode *T);
	tnode *copy_btree(tnode *T);
	void display_leaf(tnode *T);

};

#endif /* BINARYTREE_H_ */
