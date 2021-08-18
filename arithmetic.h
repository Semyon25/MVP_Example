#ifndef ARITHMETIC_H
#define ARITHMETIC_H

class IArithmetic
{
public:
    virtual double Result(double, double) = 0;
};

class Sum : public IArithmetic
{
public:
    double Result(double x, double y) override {
        return x + y;
    }
};

class Sub : public IArithmetic
{
public:
    double Result(double x, double y) override {
        return x - y;
    }
};

class Mult : public IArithmetic
{
public:
    double Result(double x, double y) override {
        return x * y;
    }
};

class Div : public IArithmetic
{
public:
    double Result(double x, double y) override {
        return x / y;
    }
};

#endif // ARITHMETIC_H
