#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stack>
using namespace std;

int prece(char c)
{
    if(c=='^')
    {
    return 3;
    }
    if(c=='*' || c=='/')
    {
        return 2;
    }
    if(c=='+'|| c=='-')
    {
        return 1;
    }
    else
    {
        return -1; //when not an operator
    }
}
string infixToPostfix(string s)
{
    stack<char>st;
    string res;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) //if operand, write in answer
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
           st.push('('); 
        }
        else if(s[i]==')') //pop and add in result
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prece(st.top())>prece(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }   
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string infix_expression, postfix_expression;  
    int ch;  
    do  {  
        cout << " Enter an infix expression: ";  
        cin >> infix_expression;  
        postfix_expression = infixToPostfix(infix_expression);  
        cout << "\n Your Infix expression is: " << infix_expression;  
        cout << "\n Postfix expression is: " << postfix_expression;  
        cout << "\n \t Do you want to enter infix expression (1/ 0)?";  
        cin >> ch;   
    } 
    while(ch == 1);  
    return 0; 
}