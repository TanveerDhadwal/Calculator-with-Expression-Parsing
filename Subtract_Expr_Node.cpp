//Subtract_Expr_Node.cpp

#include "Subtract_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Subtract_Expr_Node::Subtract_Expr_Node(void){
	left_ = 0;
	right_ = 0;
}
Subtract_Expr_Node::Subtract_Expr_Node(Expr_Node &n1,Expr_Node &n2){
	left_ = &n1;
	right_ = &n2;
}
Subtract_Expr_Node::~Subtract_Expr_Node(void){
	delete left_;
	delete right_;
}

int Subtract_Expr_Node::eval(){
	return left_->eval() - right_->eval();
}

void Subtract_Expr_Node::setLeft(Expr_Node *n){
	this->left_ = n;
}

void Subtract_Expr_Node::setRight(Expr_Node *n){
	this->right_ = n;
}

Expr_Node * Subtract_Expr_Node::getLeft(){
	return left_; 
}
Expr_Node * Subtract_Expr_Node::getRight(){
	return right_;	
}
void Subtract_Expr_Node::accept(Expr_Node_Visitor &vis){
	vis.Visit_Subtraction_Node(*this);
}

