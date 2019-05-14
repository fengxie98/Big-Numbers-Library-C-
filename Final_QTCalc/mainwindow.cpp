#include "mainwindow.h"
#include "ui_mainwindow.h"

int firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_PosNeg, SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_Percent, SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_Add, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Subtract, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Multiply, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Divide, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Mod, SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_Add->setCheckable(true);
    ui->pushButton_Subtract->setCheckable(true);
    ui->pushButton_Multiply->setCheckable(true);
    ui->pushButton_Divide->setCheckable(true);
    ui->pushButton_Mod->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    int labelNumber;
    QString newLabel;

    if((ui->pushButton_Add->isChecked() || ui->pushButton_Subtract->isChecked()
            || ui->pushButton_Multiply->isChecked() || ui->pushButton_Divide->isChecked() || ui->pushButton_Mod->isChecked()) && (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toInt();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g', 999);
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toInt();
            newLabel = ui->label->text() + button->text();
        }
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_Decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    int labelNumber;
    QString newLabel;

    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toInt();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newLabel);
    }

    if(button->text() == "%")
    {
        labelNumber = ui->label->text().toInt();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_Clear_released()
{
    ui->pushButton_Add->setChecked(false);
    ui->pushButton_Subtract->setChecked(false);
    ui->pushButton_Multiply->setChecked(false);
    ui->pushButton_Divide->setChecked(false);
    ui->pushButton_Mod->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_Equals_released()
{
    int labelNumber, secondNum;
    QString newlabel;
    secondNum = ui->label->text().toInt();

    if(ui->pushButton_Add->isChecked())
    {
        labelNumber =  firstNum + secondNum;
        newlabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newlabel);
        ui->pushButton_Add->setChecked(false);
    }

    else if(ui->pushButton_Subtract->isChecked())
    {
        labelNumber =  firstNum - secondNum;
        newlabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newlabel);
        ui->pushButton_Subtract->setChecked(false);
    }

    else if(ui->pushButton_Multiply->isChecked())
    {
        labelNumber =  firstNum * secondNum;
        newlabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newlabel);
        ui->pushButton_Multiply->setChecked(false);
    }

    else if(ui->pushButton_Divide->isChecked())
    {
        labelNumber =  firstNum / secondNum;
        newlabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newlabel);
        ui->pushButton_Divide->setChecked(false);
    }

    else if(ui->pushButton_Mod->isChecked())
    {
        labelNumber =  firstNum % secondNum;
        newlabel = QString::number(labelNumber, 'g', 999);
        ui->label->setText(newlabel);
        ui->pushButton_Mod->setChecked(false);
    }

    userIsTypingSecondNumber =  false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();

    firstNum = ui->label->text().toInt();

    button->setChecked(true);
}

