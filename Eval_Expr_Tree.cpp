//Expr_Eval_Tree.cpp
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"
#include <stdexcept>
#include "Add_Expr_Node.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Num_Expr_Node.h"
Eval_Expr_Tree::Eval_Expr_Tree(void){}

Eval_Expr_Tree::~Eval_Expr_Tree(void){}

void Eval_Expr_Tree::Visit_Addition_Node(Add_Expr_Node & node){
	Expr_Node * r = node.getRight();
	Expr_Node * l = node.getLeft();
	l->accept(*this);
	int num = this->result();
	r->accept(*this);
	int num2 = this->result();
	this->result_ = num + num2;	
 
}

void Eval_Expr_Tree::Visit_Subtraction_Node(Subtract_Expr_Node & node){
	Expr_Node * r = node.getRight();
	Expr_Node * l = node.getLeft();
	l->accept(*this);
	int num = this->result();
	r->accept(*this);
	int num2 = this->result();
	this->result_ = num - num2;

}

void Eval_Expr_Tree::Visit_Multiply_Node(Multiply_Expr_Node & node){
	Expr_Node * r = node.getRight();
	Expr_Node * l = node.getLeft();
	l->accept(*this);
	int num = this->result();
	r->accept(*this);
	int num2 = this->result();
	this->result_ = num * num2;
}

void Eval_Expr_Tree::Visit_Divide_Node(Divide_Expr_Node & node){
	Expr_Node * r = node.getRight();
	Expr_Node * l = node.getLeft(); 
	l->accept(*this);
	int num = this->result();
	r->accept(*this);
	int num2 = this->result();
	if(num2 == 0){
		throw std::runtime_error("Divide by zero error");
	}
	this->result_ = num/num2;
}

void Eval_Expr_Tree::Visit_Mod_Node(Mod_Expr_Node & node){
	Expr_Node * r = node.getRight();
	Expr_Node * l = node.getLeft(); 
	l->accept(*this);
	int num = this->result();
	r->accept(*this);
	int num2 = this->result();
	this->result_ = num % num2;
}

void Eval_Expr_Tree::Visit_Num_Node(Num_Expr_Node & node){
	this->result_ = node.getNum();
}

int Eval_Expr_Tree::result(void) const{
	return this->result_;
}
