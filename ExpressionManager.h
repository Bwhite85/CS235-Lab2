#pragma once
#include "ExpressionManagerInterface.h"
#include <sstream>

class ExpressionManager : public ExpressionManagerInterface {
public:
    ExpressionManager();
    ~ExpressionManager();

    bool isBalanced(string expression);
    string postfixToInfix(string postfixExpression);
    string postfixEvaluate(string postfixExpression);
    string infixToPostfix(string infixExpression);

private:
    
};