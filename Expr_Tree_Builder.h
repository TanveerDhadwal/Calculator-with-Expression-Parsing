#ifndef _EXPR_TREE_BUILDER
#define _EXPR_TREE_BUILDER
#include "Expr_Builder.h"

#include "Expr_Tree.h"
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Stack.h"


class Expr_Tree_Builder : public Expr_Builder{
public:
	Expr_Tree_Builder(void);
	virtual ~Expr_Tree_Builder(void);
	virtual void start_expression(void);
	virtual void build_number(int n);
	virtual void build_add_operator(void);
	virtual void build_subtract_operator(void); 
	virtual void build_multiply_operator(void);
	virtual void build_divide_operator(void);
	virtual void build_mod_operator(void);
	virtual void assignPrec(int val, Binary_Expr_Node * op);
	//virtual void build_open_paranthesis(void);
	//virtual void build_close_paranthesis(void);
	virtual Expr_Tree * getTree(void);
	virtual void endExpression(void);
private:
	Stack<Binary_Expr_Node*> opStack;
	Stack<Expr_Node*> numStack;
	Stack<int> prec;
	Expr_Tree * tree_;
};

#endif 
