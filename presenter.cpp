#include "presenter.h"

Presenter::Presenter(IModel *_model, IMainWindow *_view, QObject *parent)
    : QObject(parent), model(_model), view(_view)
{
    QObject::connect(dynamic_cast<MainWindow*>(view), &MainWindow::clickButton, this, &Presenter::execute);
    QObject::connect(dynamic_cast<MainWindow*>(view), &MainWindow::first_line_changed, this, &Presenter::set_first_number);
    QObject::connect(dynamic_cast<MainWindow*>(view), &MainWindow::second_line_changed, this, &Presenter::set_second_number);
    QObject::connect(dynamic_cast<MainWindow*>(view), &MainWindow::selectionChanged, this, &Presenter::arithmeticChanged);
    QObject::connect(this, &Presenter::resultChanged, dynamic_cast<MainWindow*>(view), &MainWindow::setResult);

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
