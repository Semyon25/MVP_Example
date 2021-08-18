#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::selectionChanged);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::clickButton);
    QObject::connect(ui->first_line_edit, &QLineEdit::textEdited, this, &MainWindow::first_line_changed);
    QObject::connect(ui->second_line_edit, &QLineEdit::textEdited, this, &MainWindow::second_line_changed);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setResult(const QString &result)
{
    ui->result_line_edit->setText(result);
}

void MainWindow::setArithmetics(const QStringList &items)
{
    ui->comboBox->clear();
    ui->comboBox->addItems(items);
    if (items.count() > 0)
        ui->comboBox->setCurrentText(items.at(0));
}


