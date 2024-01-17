#ifndef _NUM_EXPR_NODE_H
#define _NUM_EXPR_NODE_H

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"
class Num_Expr_Node: public Expr_Node{
public:
	Num_Expr_Node(int n);
	virtual ~Num_Expr_Node(void);
	virtual int eval(void);
	virtual void setNum(int n);
	virtual int getNum();
	virtual void accept(Expr_Node_Visitor &vis);
private:
	int num;
};
#endif 
