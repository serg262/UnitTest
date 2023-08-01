
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>
enum{
    SUM,
    DIFF,
    MUL,
    DIV
};

class Calculator
{
public:
    Calculator(double a, double b){this->a = a, this->b = b;}


    double Sum() const { return a + b; }//сложение
    double Diff() const { return a - b; }//вычитание
    double Mult() const { return a * b; }//умножение
    double Div() const { if(fabs(b) != 0.0)return a / b; else return 0.0; }//деление

    double get_res(int action)
    {
        switch (action) {
        case SUM:
            return(Sum());
            break;

        case DIFF:
            return(Diff());
            break;

        case MUL:
            return(Mult());
            break;

        case DIV:
            return(Div());
            break;

        }

    return 0.0;
    }

private:
    double a, b;
};

#endif // CALCULATOR_H
