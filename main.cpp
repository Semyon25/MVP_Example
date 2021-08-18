#include "mainwindow.h"

#include <QApplication>
#include "model.h"
#include "presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Presenter presenter(new Model(), new MainWindow());
    presenter.run();

    return a.exec();
}
