#ifndef _EXPR_NODE_VISITOR_H
#define _EXPR_NODE_VISITOR_H
class Add_Expr_Node;
class Subtract_Expr_Node;
class Multiply_Expr_Node;
class Divide_Expr_Node;
class Mod_Expr_Node;
class Num_Expr_Node;

class Expr_Node_Visitor{
public:
	Expr_Node_Visitor(void){}
	virtual ~Expr_Node_Visitor(void){}
	virtual void Visit_Addition_Node(Add_Expr_Node & node) = 0;
	virtual void Visit_Subtraction_Node(Subtract_Expr_Node & node) = 0;
	virtual void Visit_Multiply_Node(Multiply_Expr_Node & node) = 0;
	virtual void Visit_Divide_Node(Divide_Expr_Node & node) = 0;
	virtual void Visit_Mod_Node(Mod_Expr_Node & node) = 0;
	virtual void Visit_Num_Node(Num_Expr_Node & node) = 0;

};

#endif
