#include "presenter.h"

Presenter::Presenter(IModel *_model, IMainWindow *_view, QObject *parent)
    : QObject(parent), model(_model), view(_view)
{
    QObject* obj = dynamic_cast<QObject*>(view);
    QObject::connect(obj, SIGNAL(clickButton()), SLOT(execute()));
    QObject::connect(obj, SIGNAL(first_line_changed(double)),
                     SLOT(set_first_number(double)));
    QObject::connect(obj, SIGNAL(second_line_changed(double)),
                     SLOT(set_second_number(double)));
    QObject::connect(obj, SIGNAL(selectionChanged(QString)),
                     SLOT(arithmeticChanged(QString)));
    QObject::connect(this, SIGNAL(resultChanged(QString)),
                     obj, SLOT(setResult(QString)));

    view->setArithmetics(arithmetics.keys());
}

Presenter::~Presenter()
{
    delete model;
    delete view;
}

void Presenter::execute()
{
    double result = model->Operation(first_number, second_number);
    emit resultChanged(QString::number(result));
}

void Presenter::arithmeticChanged(const QString &value)
{
    if (arithmetics.contains(value))
        model->SetModel(arithmetics[value]);
}
