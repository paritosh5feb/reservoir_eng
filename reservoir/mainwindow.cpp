#include "mainwindow.h"
#include "ui_mainwindow.h"

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

/*
 * Implementation of the member functions defined in mainwindow.h
*/
void MainWindow::on_rb1_effective_phase_calcs_clicked()
{
    per_calcs = 1;
}

void MainWindow::on_rb2_2_phase_rel_per_calcs_clicked()
{
    per_calcs = 2;
}
