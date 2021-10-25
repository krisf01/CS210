#include <iostream>
#include <string>
#include <sstream>

#include "Stack.h"

using namespace std;

bool isOperator(const string& input);
void performOp(const string& input, Stack<double>& calcStack);

bool isOperator(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};
    
    // for loop to cylce through the 4 ops
    for (int i = 0; i < 4; i++)
    {
        if (input == ops[i])
        {
            return true;
        }
    }
    return false;
}

void performOp(const string& input, Stack<double>& calcStack)
{
    double leftValue, rightValue, result;
    
    rightValue = calcStack.peek();
    calcStack.pop();
    
    leftValue = calcStack.peek();
    calcStack.pop();
    
    if (input == "-")
    {
        result = leftValue - rightValue;
    }
    
    else if (input == "+")
    {
        result = leftValue + rightValue;
    }
    
    else if (input == "*")
    {
        result = leftValue * rightValue;
    }
    
    else
    {
        result = leftValue / rightValue;
    }
    
    cout << result << endl;
    calcStack.push(result);
}

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    Stack<double> a;
    string input;
    
    cout << "Welcome to the RPN Calculator!" << endl;

    while(true)
    {
        // displays the prompt
        cout << "Enter: ";
        
        // get input
        cin >> input;
        
        // check for numeric values (if neg. or pos.)
        double num;
        if(istringstream(input) >> num)
        {
            a.push(num);
        }
        
        // check for operator
        else if (isOperator(input))
        {
            performOp(input, a);
        }
        // check for quit
        else if(input == "q"|| input =="Q")
        {
            return 0;
        }
        
        // invalid output
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}

