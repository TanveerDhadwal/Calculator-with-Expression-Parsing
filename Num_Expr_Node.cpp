//Num_Expr_Node.cpp
#include "Num_Expr_Node.h"

Num_Expr_Node::Num_Expr_Node(int n){
	this->num = n;
}
Num_Expr_Node::~Num_Expr_Node(void){}
int Num_Expr_Node::eval(void){
	return this->num;
}
void Num_Expr_Node::setNum(int n){
	this->num = n;
}
int Num_Expr_Node::getNum(){
	return this->num;
} 
void Num_Expr_Node::accept(Expr_Node_Visitor &vis){
	vis.Visit_Num_Node(*this);
}
