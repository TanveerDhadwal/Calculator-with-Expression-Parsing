//Mod_Expr_Node.cpp
#include "Mod_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Mod_Expr_Node::Mod_Expr_Node(void){
	left_ = 0;
	right_ = 0;
}
Mod_Expr_Node::Mod_Expr_Node(Expr_Node &n1,Expr_Node &n2){
	left_ = &n1;
	right_ = &n2;
}
Mod_Expr_Node::~Mod_Expr_Node(void){
	delete left_;
	delete right_;
}
int Mod_Expr_Node::eval(){
	return left_->eval() % right_->eval();
}
void Mod_Expr_Node::setLeft(Expr_Node *n){
	left_ = n;
}
void Mod_Expr_Node::setRight(Expr_Node * n){
	right_ = n;
}
Expr_Node * Mod_Expr_Node::getLeft(){
	return this->left_;
}
Expr_Node * Mod_Expr_Node::getRight(){
	return this->right_;
}
void Mod_Expr_Node::accept(Expr_Node_Visitor &vis){
	vis.Visit_Mod_Node(*this);
}	
