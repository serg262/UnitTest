
#include "mainwindow.h"
#include "calculator.h"
#include "ui_mainwindow.h"

#include <QFontDatabase>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setFixedSize(QSize(350, 400));
    setWindowTitle("Калькулятор");


    int id = QFontDatabase::addApplicationFont(":/fonts/MyFont.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);



    QFont my_font(family);
    my_font.setPixelSize(70);
    ui->lineEdit->setFont(my_font);


    symbol_group = new QButtonGroup(this);

    symbol_group->addButton(ui->pushButton);
    symbol_group->addButton(ui->pushButton_2);
    symbol_group->addButton(ui->pushButton_3);
    symbol_group->addButton(ui->pushButton_4);
    symbol_group->addButton(ui->pushButton_5);
    symbol_group->addButton(ui->pushButton_6);
    symbol_group->addButton(ui->pushButton_7);
    symbol_group->addButton(ui->pushButton_8);
    symbol_group->addButton(ui->pushButton_9);
    symbol_group->addButton(ui->pushButton_0);
    symbol_group->addButton(ui->pushButton_point);

    connect(symbol_group, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, QOverload<QAbstractButton *>::of(&MainWindow::symbol_clicked));

    action_group = new QButtonGroup(this);

    action_group->addButton(ui->pushButton_plus);
    action_group->addButton(ui->pushButton_minus);
    action_group->addButton(ui->pushButton_mul);
    action_group->addButton(ui->pushButton_div);


    connect(action_group, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, QOverload<QAbstractButton *>::of(&MainWindow::action_clicked));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::symbol_clicked(QAbstractButton *button)
{
    char symbol = button->text().toLocal8Bit().at(0);

    if(!flag_input)
    ui->lineEdit->clear();

    ui->lineEdit->setText(ui->lineEdit->text().append(symbol));

    flag_input = true;

}

void MainWindow::action_clicked(QAbstractButton *button)
{
    char symbol = button->text().toLocal8Bit().at(0);


    a = ui->lineEdit->text().toDouble();
    button->setStyleSheet("background-color: green;");
    flag_input = false;

    switch (symbol) {
    case '+':
        action = SUM;
        break;

    case '-':
        action = DIFF;
        break;

    case 'X':
        action = MUL;
        break;

    case '/':
        action = DIV;
        break;

    }

}


void MainWindow::on_pushButton_res_clicked()
{
    b = ui->lineEdit->text().toDouble();
    ui->lineEdit->clear();

    Calculator calc(a,b);
    double res = calc.get_res(action);
    ui->lineEdit->setText(QString::number(res));


    ui->pushButton_plus->setStyleSheet("");
    ui->pushButton_minus->setStyleSheet("");
    ui->pushButton_mul->setStyleSheet("");
    ui->pushButton_div->setStyleSheet("");

    flag_input = false;
}

