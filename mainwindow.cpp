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
    QObject::connect(ui->first_line_edit, &QLineEdit::textChanged, this, &MainWindow::onLineEditTextChanged);
    QObject::connect(ui->second_line_edit, &QLineEdit::textChanged, this, &MainWindow::onLineEditTextChanged);

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

void MainWindow::onLineEditTextChanged(const QString &text)
{
    QLineEdit* lEdit = (QLineEdit*)sender();
    bool ok;
    double value = text.toDouble(&ok);
    if (ok)
    {
        if (lEdit == ui->first_line_edit)
            emit first_line_changed(value);
        else if (lEdit == ui->second_line_edit)
            emit second_line_changed(value);
    }
}

