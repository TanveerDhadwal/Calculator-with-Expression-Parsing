//Expr_Tree_Builder.cpp

#include "Expr_Tree_Builder.h"
#include "Stack.h"
#include <iostream>

Expr_Tree_Builder::Expr_Tree_Builder(void){}

Expr_Tree_Builder::~Expr_Tree_Builder(void){
	delete tree_;
}

void Expr_Tree_Builder::start_expression(void){
	this->tree_ = new Expr_Tree();
}


void Expr_Tree_Builder::build_number(int n){
	Num_Expr_Node * tempn = new Num_Expr_Node(n);
	numStack.push(tempn);
	
}

// COMMENT It seems like you have a LOT of code duplication in this method. Please
// refactor your design so you remove this code smell.
//
// SOLUTION Created a new method which holds duplicated code.
void Expr_Tree_Builder::build_add_operator(void){
	Add_Expr_Node * a = new Add_Expr_Node();
	if(opStack.is_empty()){
		opStack.push(a);
		prec.push(1);
	}else{
		this->assignPrec(1,a);
	}
}


// COMMENT It seems like you have a LOT of code duplication in this method. Please
// refactor your design so you remove this code smell.
//
// SOLUTION Created a new method which holds duplicated code.

void Expr_Tree_Builder::build_subtract_operator(void){
	Subtract_Expr_Node * s = new Subtract_Expr_Node();
	if(opStack.is_empty()){
		opStack.push(s);
		prec.push(1);
		
	}else{
		this->assignPrec(1,s);
	}
}


// COMMENT It seems like you have a LOT of code duplication in this method. Please
// refactor your design so you remove this code smell.
//
// SOLUTION Created a new mthod which hodls duplicated code.

void Expr_Tree_Builder::build_multiply_operator(void){
	Multiply_Expr_Node *m = new Multiply_Expr_Node();
	if(opStack.is_empty()){
		opStack.push(m);
		prec.push(2);
	}else{
		this->assignPrec(2,m);

	}
}


// COMMENT It seems like you have a LOT of code duplication in this method. Please
// refactor your design so you remove this code smell.
//
// SOLUTION Created a new method whic hholds duplicated code 

void Expr_Tree_Builder::build_divide_operator(void){
	Divide_Expr_Node * divider = new Divide_Expr_Node();
	if(opStack.is_empty()){
		opStack.push(divider);
		prec.push(2);
	}
	else{
		this->assignPrec(2,divider);
	
	}
}


// COMMENT It seems like you have a LOT of code duplication in this method. Please
// refactor your design so you remove this code smell.
//
// SOLUTION Created a new method which holds duplicated code 

void Expr_Tree_Builder::build_mod_operator(void){
	Mod_Expr_Node * mo = new Mod_Expr_Node();
	if(opStack.is_empty()){
		opStack.push(mo);
		prec.push(2);
	}
	else{
		this->assignPrec(2,mo);

	}
}

//void Expr_Tree_Builder::build_open_paranthesis(void){

//}

//void Expr_Tree_Builder::build_close_paranthesis(void){

//}

void Expr_Tree_Builder::assignPrec(int val,Binary_Expr_Node * op){

	Binary_Expr_Node * temp = opStack.top();
	int t = prec.top();
	if(t >= val){
		opStack.pop();
		prec.pop();
		Expr_Node * num1 = numStack.top();
		numStack.pop();
		Expr_Node * num2 = numStack.top();
		numStack.pop();
		temp->setRight(num1);
		temp->setLeft(num2);
		numStack.push(temp);
		opStack.push(op);
		prec.push(val);
			
				
	}
	else if (t < val){
		opStack.push(op);
		prec.push(val);
	}


}
void Expr_Tree_Builder::endExpression(void){
	Binary_Expr_Node * temp;
	int t;
	while(!opStack.is_empty()){
		temp = opStack.top();
		t = prec.top();
		opStack.pop();
		prec.pop();
		Expr_Node * num1 = numStack.top();
		numStack.pop();
		Expr_Node * num2 = numStack.top();
		numStack.pop();
		temp->setRight(num1);
		temp->setLeft(num2);
		numStack.push(temp);				
	}
	this->tree_->setRoot(numStack.top());
	numStack.pop();		
		
}
Expr_Tree * Expr_Tree_Builder::getTree(void){
	return this->tree_;
}
