#ifndef _EXPR_TREE_H
#define _EXPR_TREE_H
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"
class Expr_Tree{
public:
	Expr_Tree(void);
	Expr_Node * getRoot();
	void setRoot(Expr_Node * node);
	int evaluate(void);
private:
	Expr_Node * root;
};
#endif
