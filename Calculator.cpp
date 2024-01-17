//Calculator.cpp
#include "Calculator.h"
#include "Expr_Tree_Builder.h"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>
Calculator::Calculator(Expr_Builder &b)
	:builder_(b){
	
}
int Calculator::evaluate(const std::string &infix){
	if(!this->parse_expr(infix)){
		throw std::runtime_error("Bad expression");
	}
	//if(nullptr == expr.get()){
	//	throw std::runtime_exception("No expression");
	//}
	Expr_Tree * expr = this->builder_.getTree();
	return expr->evaluate();
	
}
bool Calculator::parse_expr(const std::string &infix){
	std::istringstream input(infix);
	std::string token;
	bool isParenth = false;
	int counter;
	int parencheck;
	std::string val = "";
		
	builder_.start_expression();	
	
	while(!input.eof()){
		input>>token; 

			if(token == "+"){
				if(isParenth == true){
					this->concatonate(token,val);	
				}else{
					this->builder_.build_add_operator();
				}
			}
			else if(token == "-"){
				if(isParenth == true){
					this->concatonate(token,val);
				}else{
					this->builder_.build_subtract_operator();
				}
			}
			else if(token == "*"){
				if(isParenth == true){
					this->concatonate(token,val);
				}else{
					this->builder_.build_multiply_operator();
				}
			}
			else if(token == "/"){
				if(isParenth == true){
					this->concatonate(token,val);
				}else{
					this->builder_.build_divide_operator();
				}
			}
			else if(token == "%"){
				if(isParenth == true){
					this->concatonate(token,val);
				}else{
					this->builder_.build_mod_operator();
				}
			}
			else if(token == "("){
				if(isParenth == true){
					this->concatonate(token,val);
					counter++;
				}else{
					isParenth = true;
					counter++;
				}
			}
			else if(token == ")"){
				if(isParenth == true){
					counter--;
					if(counter == 0){
						isParenth = false;
						Expr_Tree_Builder thebuilder;
						Calculator theCalculator(thebuilder);
						int t = theCalculator.evaluate(val);
						this->builder_.build_number(t);
						val = "";
						
							
					}else{
						this->concatonate(token,val);
					}
				}
			} 
			else{
				if(isParenth == true){
					this->concatonate(token,val);
				}else{
					int tempint = 0;
					tempint = std::stoi(token);
					this->builder_.build_number(tempint);
				}
			} 

	}
	builder_.endExpression();
return true;


}
void Calculator::concatonate(std::string infix,std::string &v){
	v = v + " " + infix;

}
