//Add_Expr_Node.cpp

#include "Add_Expr_Node.h"
#include "Expr_Node_Visitor.h"

Add_Expr_Node::Add_Expr_Node(void){
	left_ = 0;
	right_ = 0;
}
Add_Expr_Node::Add_Expr_Node(Expr_Node *n1,Expr_Node *n2){
	left_ = n1;
	right_ = n2;
}

Add_Expr_Node::~Add_Expr_Node(void){
	delete left_;
	delete right_;
}
int Add_Expr_Node::eval(void){
	return left_->eval() + right_->eval();

}
Expr_Node * Add_Expr_Node::getLeft(){
	return this->left_;
}
Expr_Node * Add_Expr_Node::getRight(){
	return this->right_;
}
void Add_Expr_Node::setLeft(Expr_Node *n){
	left_ = n;
}
void Add_Expr_Node::setRight(Expr_Node *n){
	right_= n;
}
void Add_Expr_Node::accept(Expr_Node_Visitor &vis){
	vis.Visit_Addition_Node(*this);
}

