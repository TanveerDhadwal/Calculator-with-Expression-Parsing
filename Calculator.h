#ifndef _CALCULATOR_H
#define _CALCULATOR_H
#include <string>
#include "Expr_Tree.h"
#include "Expr_Builder.h"
class Calculator{
public:
	Calculator(Expr_Builder & b);
	bool parse_expr(const std::string & infix);
	int evaluate(const std::string & infix);
	void concatonate(std::string infix,std::string &v);

private:
 	Expr_Builder & builder_;

};
#endif
