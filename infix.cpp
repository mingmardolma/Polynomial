#include <iostream>
#include <stack> 
#include <string>
using namespace std;

int infixProcess(string s);
int findPrecedence(char r);
int calculate(int a,char symbol, int b);

int main()
{
    string infix = " 2 *3+2-6";
    cout << infixProcess(infix) << endl;

    infix = "2 + 3 * 5 - 6 ";
    cout << infixProcess(infix) << endl;

    infix = "1 - 2 - 3 * 5 / 6 + 6";
    cout << infixProcess(infix) << endl;

    infix = "1 + 2 * 3 + 5 - 6 / 2";
    cout << infixProcess(infix) << endl;

}
int findPrecedence(char r)
{
    if(r == '+' || r == '-')
        return 1;
    else if(r == '*' || r == '/')
        return 2;
    return 0;
}
int calculate(int a,char symbol, int b)
{
    switch(symbol)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
int infixProcess(string s)
{
    stack<int> operands;
    stack<char> operators;
    int numR, numL, curr;
    char root;
    curr = 0;
    int i;
    int size = s.size();
    for(i =0; i< size; i++)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        else if(isdigit(s[i])) 
        {
            curr = 0;
            while(i < size && isdigit(s[i]))
            {
                curr = (curr*10) + (s[i]-'0');
                i++;
            }
            operands.push(curr);
            i--;        
        }
        else 
        {
            while(!operators.empty() && findPrecedence(operators.top()) >= findPrecedence(s[i]))
            {
                numR = operands.top();
                operands.pop();
                numL = operands.top();
                operands.pop();
                root = operators.top();
                operators.pop();    

                operands.push(calculate(numL, root, numR));
            }
            operators.push(s[i]);
        }
    }
    while(!operators.empty())
    {
        numR = operands.top();
        operands.pop();
                                
        numL = operands.top();
        operands.pop();
                                
        root = operators.top();
        operators.pop();
                                
        operands.push(calculate(numL, root, numR));
    
    }
    return operands.top();
}