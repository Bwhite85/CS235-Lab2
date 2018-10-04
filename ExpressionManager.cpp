#include "ExpressionManager.h"

ExpressionManager::ExpressionManager(){
    
}

ExpressionManager::~ExpressionManager(){

}

bool ExpressionManager::isBalanced(string expression){
    stack<string> sStack;
    stringstream sStream;
    string input = "";
    bool balanced = true;

    sStream.str(expression);

    while(!sStream.fail()){
        
        sStream >> input;
        
        if(input == "(" || input == "[" || input == "{"){
            sStack.push(input);
        }
        
        if(sStack.empty()){
            break;
        }
        else{
            
            if(input == ")" || input == "]" || input == "}"){
                sStack.pop();
            }
        }
    }

    if(sStack.empty()){
        balanced = true;
    }
    else{
        balanced = false;
    }

    return balanced;
}

string ExpressionManager::postfixToInfix(string postfixExpression){
    

}

string ExpressionManager::postfixEvaluate(string postfixExpression){
    stack<string> sStack;
    stringstream sStreamInput;
    stringstream sStreamCalc;
    string input = "";
    string numOne = "";
    string numTwo = "";
    string finalNum = "";
    string answer = "";
    int numCalcOne = 0;
    int numCalcTwo = 0;
    int numCalcAnswer = 0;

    sStreamInput.str(postfixExpression);

    while(!sStreamInput.fail()){
        sStreamInput >> input;
        cout << "starting loop" << endl;
        if(input == "(" || input == ")" || input == "+" || input == "-" || input == "*" || input == "/" || input == "%" || input == "{" || input == "}" || input == "[" || input == "]"){
            cout << "did not add operator or bracket" << endl;
        }
        else{
            sStack.push(input);
            cout << "added " << input << " to the stack" << endl;
        }

        if(sStack.empty()){
            cout << "stack is empty" << endl;
            break;
        }
        else{
            if(input == "+" || input == "-" || input == "*" || input == "/" || input == "%"){
                if(sStack.size() >= 2){
                    cout << "enough operands for calculation" << endl;
                    numOne = sStack.top();
                    sStack.pop();

                    numTwo = sStack.top();
                    sStack.pop();

                    sStreamCalc << numTwo << numOne;

                    cout << numOne << " numOne" << endl;
                    cout << numTwo << " numTwo" << endl;
                    cout << input << " input" << endl;

                    sStreamCalc >> numCalcOne;
                    sStreamCalc >> numCalcTwo;
                    sStreamCalc.clear();

                    if(input == "+"){
                        numCalcAnswer = numCalcTwo + numCalcOne;
                    }
                    else if(input == "-"){
                        numCalcAnswer = numCalcTwo - numCalcOne;
                    }
                    else if(input == "*"){
                        numCalcAnswer = numCalcTwo * numCalcOne;
                    }
                    else if(input == "/"){
                        numCalcAnswer = numCalcTwo / numCalcOne;
                    }
                    else if(input == "%"){
                        numCalcAnswer = numCalcTwo % numCalcOne;
                    }

                    sStreamCalc << numCalcAnswer;
                    sStreamCalc >> answer;
                    //need to convert answer back into string to put it on the stack. Stack is for strings only.
                    sStack.push(answer);
                    cout << "placed " << numCalcAnswer << " on stack" << endl;

                }
                else{
                    cout << "expression is invalid. too few operands in stack to complete equation" << endl;
                    break;
                }
            }
        }

        if(sStack.size() == 1){
            cout << "stack only has one item in it" << endl;

            if(sStreamInput.fail()){
                cout << "One item in the stack and nothing left in sStreamIput, expression is good." << endl;
                break;
            }

            continue;

        }
    }
    return finalNum;
}

string ExpressionManager::infixToPostfix(string infixExpression){


}