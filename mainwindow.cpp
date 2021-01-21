#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interplist.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonPick_clicked()
{
    QFile file (":/pick.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::critical(this, "Error", "Cannot open pick.json file!");
       return;
    }

    QTextStream in(&file);
    QString str = in.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(str.toUtf8());

    Pick pick;
    //!!!!
    pick.fromJson(d);

    QString info;
    info = QString("Pick name: ") + pick.getPickName() + "\n";
    info += QString("Color: ") + pick.getColor() + "\n";
    info += QString("Visible: ") + (pick.getVisible() ? "true" : "false") + QString ("\n");
    QMessageBox::information(this, "Pick", info);
}

void MainWindow::on_pushButtonReadGrid_clicked()
{
    QFile file (":/grid.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::critical(this, "Error", "Cannot open grid.json file!");
       return;
    }

    QTextStream in(&file);
    QString str = in.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(str.toUtf8());

    Grid grid;
    //!!!!
    grid.fromJson(d);

    QString info;
    info = QString("Grid name: ") + grid.getGridName() + "\n";
    info += QString("Color: ") + grid.getColor() + "\n";
    info += QString("ID: ") + QString::number(grid.getId()) + QString ("\n");
    QMessageBox::information(this, "Grid", info);
}

void MainWindow::on_pushButtonReadInterpList_clicked()
{
    QFile file (":/interp_list.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::critical(this, "Error", "Cannot open interp_list.json file!");
       return;
    }

    QTextStream in(&file);
    QString str = in.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument d = QJsonDocument::fromJson(str.toUtf8(),&error);

    if(QJsonParseError::NoError != error.error){
        QMessageBox::critical(this, "Error", error.errorString());
        return;
    }

    InterpList list;
    //!!!!
    list.fromJson(d);

    QString info;
    info = "---- GRID -----\n";
    info += QString("Grid name: ") + list.getGrid().getGridName() + "\n";
    info += QString("Color: ") + list.getGrid().getColor() + "\n";
    info += QString("ID: ") + QString::number(list.getGrid().getId()) + QString ("\n");
    info += "---- PICK -----\n";
    info += QString("Pick name: ") + list.getPick().getPickName() + "\n";
    info += QString("Color: ") + list.getPick().getColor() + "\n";
    info += QString("Visible: ") + (list.getPick().getVisible() ? "true" : "false") + QString ("\n");
    QMessageBox::information(this, "Interp List", info);
}
