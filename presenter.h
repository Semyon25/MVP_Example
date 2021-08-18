#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>
#include <QMap>
#include "model.h"
#include "mainwindow.h"
#include "arithmetic.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(IModel *_model, IMainWindow *_view, QObject *parent = nullptr);
    ~Presenter() override;
    void run(){
        view->show();
    }


signals:
    void resultChanged(const QString &);

private:
    IModel *model;
    IMainWindow *view;

private:
    double first_number;
    double second_number;
    const QMap<QString, IArithmetic*> arithmetics =
    {
        {"Сложить", new Sum},
        {"Вычесть", new Sub},
        {"Умножить", new Mult},
        {"Разделить", new Div}
    };

private slots:
    void set_first_number(const QString &value){
        first_number = value.toDouble();
    }
    void set_second_number(const QString &value){
        second_number = value.toDouble();
    }
    void execute();
    void arithmeticChanged(const QString & value);
};

#endif // PRESENTER_H
