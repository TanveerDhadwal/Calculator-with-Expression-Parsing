//driver.cpp
#include <iostream>
#include <string>
#include<stdexcept>
#include "Expr_Builder.h"
#include "Expr_Tree_Builder.h"
#include "Add_Expr_Node.h"
#include "Calculator.h"
#include "Subtract_Expr_Node.h"
#include "Multiply_Expr_Node.h"
#include "Divide_Expr_Node.h"
#include "Mod_Expr_Node.h"
#include "Num_Expr_Node.h"

int main(){
	
	Expr_Tree_Builder builder; 
	Calculator calc(builder);
	std::string input;
	bool sentry = true;
	while(sentry == true){
		std::cout<<"Please enter expression or QUIT to exit program"<<std::endl;
		std::getline(std::cin,input);
		if(input == "QUIT"){
			sentry = false;
		}else{
			try{
				std::cout<<calc.evaluate(input)<<std::endl;				
			}catch(const std::runtime_error & error){
				std::cout<<error.what()<<std::endl;
			}
			catch(const std::invalid_argument &i){
				std::cout<<"Bad Expression"<<std::endl;
			}
			

		}
	}
	

}
