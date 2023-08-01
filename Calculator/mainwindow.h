
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *get_ui(){return ui;}


private slots:

void symbol_clicked(QAbstractButton *button);
void action_clicked(QAbstractButton *button);


void on_pushButton_res_clicked();

private:
    Ui::MainWindow *ui;

    QButtonGroup *symbol_group;
    QButtonGroup *action_group;

    double a, b;
    bool flag_input = false;
    int action = -1;

};

#endif // MAINWINDOW_H
