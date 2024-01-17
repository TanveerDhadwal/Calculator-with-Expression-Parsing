#ifndef _EVAL_EXPR_TREE_H
#define _EVAL_EXPR_TREE_H

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor{
public:
	Eval_Expr_Tree(void);
	virtual ~Eval_Expr_Tree(void);
	virtual void Visit_Addition_Node(Add_Expr_Node & node);
	virtual void Visit_Subtraction_Node(Subtract_Expr_Node & node);
	virtual void Visit_Multiply_Node(Multiply_Expr_Node & node);
	virtual void Visit_Divide_Node(Divide_Expr_Node & node);
	virtual void Visit_Mod_Node(Mod_Expr_Node & node);
	virtual void Visit_Num_Node(Num_Expr_Node & node);
	int result(void) const;
private:
	int result_; 

};

#endif
