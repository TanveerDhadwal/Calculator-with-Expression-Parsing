//Binary_Expr_Node.cpp
#include "Binary_Expr_Node.h"

Binary_Expr_Node::Binary_Expr_Node(void) {}

Binary_Expr_Node::~Binary_Expr_Node(void){}

void Binary_Expr_Node::accept(Expr_Node_Visitor &vis){}
int Binary_Expr_Node::eval(void){
	throw "Attempt to evaluate generic binary command op";
}
