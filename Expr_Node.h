#ifndef _EXPR_NODE_H
#define _EXPR_NODE_H
class Expr_Node_Visitor;
class Expr_Node{
public:
	Expr_Node(void);
	virtual void accept(Expr_Node_Visitor &vis) = 0;
	virtual ~Expr_Node(void);
	virtual int eval (void) = 0;
};

#endif
