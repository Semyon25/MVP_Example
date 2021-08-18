#include "model.h"

Model::Model(QObject *parent)
    : QObject(parent)
{

}

Model::~Model()
{
}

double Model::Operation(double x, double y)
{
    if (arithmetic != nullptr)
        return arithmetic->Result(x,y);

    return 0.0;
}

void Model::SetModel(IArithmetic *_arithmetic)
{
    this->arithmetic = _arithmetic;
}

