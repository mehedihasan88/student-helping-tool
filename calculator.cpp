#include<bits/stdc++.h>
#include "calculator.h"
using namespace std;


void calculator::get_expression()
{
    cout<<"Enter your expression (Put space between every operator and operand)"<<endl;
    while(1)
    {
        cin>>read_string;
        char ch =getchar();
        s.push_back(read_string);
        if(ch=='\n')
            break;
    }
}
int calculator::power(int x)
{
    int mul=1;
    while(x--)
    {
        mul*=10;
    }
    return mul;
}
double calculator::string2double (string x)
{
    int l=x.length();
    int num=0;
    int dot=-1;
    for(int i=0; i<l; i++)
    {
        if(isdigit(x[i])==1)
        {
            num=num*10+x[i]-'0';
        }
        else
        {
            dot=i;
        }

    }
    double d;
    if(dot!=-1)
    {
        d=(double)num/power(l-dot-1);

    }
    else
    {
        d=(double)num;

    }


    return d;
}
bool calculator::isChar(string s)
{
    if(s.size() >1 )
        return false;

    switch (s[0])
    {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    case '(':
        return true;
    case ')':
        return true;
    case '^':
        return true;
    default:
        return false;
    }
}
double calculator::solve(double op1, double op2, char ch)
{
    switch(ch)
    {
    case '+':
        return (op1+op2);
    case '-':
        return (op1-op2);
    case '*':
        return (op1*op2);
    case '/':
        return (op1/op2);
    case '^':
        return pow(op1,op2);

    }
}
int calculator::preference( char ch)
{
    switch(ch)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return -1;
    }
}
void calculator::show_solution()
{
    int l=s.size();
    int i=0;
    while(l--)
    {
        if(isChar(s[i]))
        {
            if(s[i]=="(")
                operators.push('(');
            else if(s[i]==")")
            {
                while(operators.top()!='(')
                {
                    char ch=operators.top();
                    operators.pop();
                    double op2=operands.top();
                    operands.pop();
                    double op1=operands.top();
                    operands.pop();

                    operands.push(solve(op1,op2,ch));
                }
                operators.pop();
            }
            else
            {
                while(!operators.empty() &&   preference(s[i][0]) <= preference(operators.top()))
                {
                    char ch=operators.top();
                    operators.pop();
                    double op2=operands.top();
                    operands.pop();
                    double op1=operands.top();
                    operands.pop();

                    operands.push(solve(op1,op2,ch));

                }

                operators.push(s[i][0]);
            }

        }
        else
        {
            double op= (double) string2double(s[i]);

            operands.push(op);
        }


        i++;

    }

    while(!operators.empty())
    {
        char ch=operators.top();
        operators.pop();
        double op2=operands.top();
        operands.pop();
        double op1=operands.top();
        operands.pop();

        operands.push(solve(op1,op2,ch));
    }
    cout<<"-------------------------"<<endl;

    for(int i=0; i<s.size(); i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<"= "<<operands.top()<<endl;

    cout<<"-------------------------"<<endl;
    _result=operands.top();
}
