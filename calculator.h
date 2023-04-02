#ifndef CALCULATOR_H
#define CALCULATOR_H
using namespace std;



class calculator
{
private:
    vector <string> s;
    string read_string;
    stack <char> operators;
    stack <double> operands;
    double _result;


public:
    friend double expression_sum(calculator a,calculator b);
    void get_expression();
    int power(int x);
    double string2double (string x);
    bool isChar(string s);
    double solve(double op1, double op2, char ch);
    int preference( char ch);
    void show_solution();



};

#endif // CALCULATOR_H
