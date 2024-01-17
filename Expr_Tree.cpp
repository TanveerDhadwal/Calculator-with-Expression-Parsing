//Expr_Tree.cpp

#include "Expr_Tree.h"

Expr_Tree::Expr_Tree(void){}

Expr_Node * Expr_Tree::getRoot(){
	return this->root;
}

void Expr_Tree::setRoot(Expr_Node *node){
	this->root = node;
}

int Expr_Tree::evaluate(){
	Eval_Expr_Tree calc;
	this->root->accept(calc);
	return calc.result();

}
