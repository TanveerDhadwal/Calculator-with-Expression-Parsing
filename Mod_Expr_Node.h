#ifndef _MOD_EXPR_NODE_H
#define _MOD_EXPR_NODE_H
#include "Binary_Expr_Node.h"

class Mod_Expr_Node : public Binary_Expr_Node{
public:
	Mod_Expr_Node(void);
	Mod_Expr_Node(Expr_Node &n1,Expr_Node &n2);
	virtual ~Mod_Expr_Node(void);
	virtual int eval(void);
	void setLeft(Expr_Node * n);
	void setRight(Expr_Node * n);
	Expr_Node * getLeft();
	Expr_Node * getRight();
	void accept(Expr_Node_Visitor &vis);
};
#endif
