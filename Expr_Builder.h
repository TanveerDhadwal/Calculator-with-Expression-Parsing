#ifndef _EXPR_BUILDER_H
#define _EXPR_BUILDER_H

#include "Expr_Tree.h"
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Num_Expr_Node.h"

class Expr_Builder{
public:
	Expr_Builder(void){}
	virtual void start_expression(void) = 0;
	virtual void build_number(int n) = 0;
	virtual void build_add_operator(void) = 0;
	virtual void build_subtract_operator(void) = 0;
	virtual void build_multiply_operator(void) = 0;
	virtual void build_divide_operator(void) = 0;
	virtual void build_mod_operator(void) = 0;
	virtual Expr_Tree * getTree(void) = 0;
        virtual void endExpression(void) = 0;

//	virtual void build_open_paranthesis(void) = 0;
//	virtual void build_close_paranthsesis(void) = 0;
	//virtual void Expr_Tree * get_Expression(void) = 0;	

};

#endif

