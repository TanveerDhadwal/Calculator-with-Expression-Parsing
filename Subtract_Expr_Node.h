#ifndef _SUBTRACT_EXPR_NODE_H
#define _SUBTRACT_EXPR_NODE_H

#include "Binary_Expr_Node.h"

class Subtract_Expr_Node :public Binary_Expr_Node{
public:
	Subtract_Expr_Node(void);
	Subtract_Expr_Node(Expr_Node &n1, Expr_Node &n2);
	virtual ~Subtract_Expr_Node(void);
	virtual int eval(void);
	virtual Expr_Node * getRight();
	virtual Expr_Node * getLeft();
	virtual void setLeft(Expr_Node * n);
	virtual void setRight(Expr_Node * n);
	void accept(Expr_Node_Visitor &vis);


};
#endif
