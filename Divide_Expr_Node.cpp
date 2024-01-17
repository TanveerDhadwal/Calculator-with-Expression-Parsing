//Divide_Expr_Node.cpp
#include "Divide_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Divide_Expr_Node::Divide_Expr_Node(void){
	left_ = 0;
	right_ = 0;
}
Divide_Expr_Node::Divide_Expr_Node(Expr_Node &n1,Expr_Node &n2){
	left_ = &n1;
	right_ = &n2;
}
Divide_Expr_Node::~Divide_Expr_Node(void){
	delete left_;
	delete right_;
}
int Divide_Expr_Node::eval(){
	if(right_->eval() == 0){
		throw "Attempt to Divide by 0";
	}
	return left_->eval() / right_->eval();
}
void Divide_Expr_Node::setLeft(Expr_Node *n){
	left_ = n;
}
void Divide_Expr_Node::setRight(Expr_Node *n){
	right_ = n;
}
Expr_Node * Divide_Expr_Node::getLeft(){
	return left_;
}
Expr_Node * Divide_Expr_Node::getRight(){
	return right_;
}
void Divide_Expr_Node::accept(Expr_Node_Visitor &vis){
	vis.Visit_Divide_Node(*this);
}
