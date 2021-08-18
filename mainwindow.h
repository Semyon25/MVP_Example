#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QObject>

class IMainWindow
{
public:
    virtual void setArithmetics(const QStringList &items) = 0;
    virtual ~IMainWindow() {}

public:
    virtual void show() = 0;
    virtual void setResult(const QString &result) = 0;
    virtual void clickButton() = 0;
    virtual void selectionChanged(const QString &) = 0;
    virtual void first_line_changed(double) = 0;
    virtual void second_line_changed(double) = 0;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

Q_DECLARE_INTERFACE(IMainWindow, "IMainWindow")

class MainWindow : public QMainWindow, public IMainWindow
{
    Q_OBJECT
    Q_INTERFACES(IMainWindow)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void setArithmetics(const QStringList &items) override;
    void show() override {
        this->QMainWindow::show();
    }

public slots:
    void setResult(const QString &) override;

signals:
    void clickButton() override;
    void selectionChanged(const QString &) override;
    void first_line_changed(double) override;
    void second_line_changed(double) override;

private slots:
    void onLineEditTextChanged(const QString &text);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
