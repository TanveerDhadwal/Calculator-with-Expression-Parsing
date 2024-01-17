//Multiply_Expr_Node.cpp
#include "Multiply_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Multiply_Expr_Node::Multiply_Expr_Node(void){
	left_ = 0;
	right_ = 0;
}
Multiply_Expr_Node::Multiply_Expr_Node(Expr_Node &n1,Expr_Node &n2){
	left_ = &n1;
	right_ = &n2;
}
Multiply_Expr_Node::~Multiply_Expr_Node(void){
	delete left_;
	delete right_;
}
int Multiply_Expr_Node::eval(){
	return left_->eval() * right_->eval();
}
void Multiply_Expr_Node::setLeft(Expr_Node *n){
	left_ = n;
}
void Multiply_Expr_Node::setRight(Expr_Node *n){
	right_ = n;
}
Expr_Node * Multiply_Expr_Node::getLeft(){
	return this->left_;
}
Expr_Node * Multiply_Expr_Node::getRight(){
	return this->right_;
}
void Multiply_Expr_Node::accept(Expr_Node_Visitor &vis){
	vis.Visit_Multiply_Node(*this);
}
