#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "arithmetic.h"

class IModel
{
public:
    virtual double Operation(double, double) = 0;
    virtual void SetModel(IArithmetic * arithmetic) = 0;
    virtual ~IModel() {}
};

class Model : public QObject, public IModel
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    ~Model() override;

    double Operation(double x, double y) override;
    void SetModel(IArithmetic * arithmetic) override;

private:
    IArithmetic * arithmetic;

};

#endif // MODEL_H
