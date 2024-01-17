#ifndef _ADD_EXPR_NODE_H
#define _ADD_EXPR_NODE_H

#include "Binary_Expr_Node.h"


class Add_Expr_Node : public Binary_Expr_Node{
public:
	Add_Expr_Node(void);
	Add_Expr_Node(Expr_Node * n1,Expr_Node *n2);
	virtual ~Add_Expr_Node(void);
	virtual int eval(void);
	virtual Expr_Node * getLeft();
	virtual Expr_Node * getRight();
	virtual void setLeft(Expr_Node *n);
	virtual void setRight(Expr_Node *n);
	void accept(Expr_Node_Visitor & vis); 

};
#endif
