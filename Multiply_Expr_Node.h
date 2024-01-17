#ifndef _MULTIPLY_EXPR_NODE_H
#define _MULTIPLY_EXPR_NODE_H
#include "Binary_Expr_Node.h"

class Multiply_Expr_Node : public Binary_Expr_Node{
public:
	Multiply_Expr_Node(void);
	Multiply_Expr_Node(Expr_Node &n1,Expr_Node &n2);
	virtual ~Multiply_Expr_Node(void);
	virtual int eval(void);
	virtual void setLeft(Expr_Node * n);
	virtual void setRight(Expr_Node * n);
	virtual Expr_Node * getLeft();
	virtual Expr_Node * getRight();
	void accept(Expr_Node_Visitor &vis);

};
#endif
