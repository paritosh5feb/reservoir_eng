#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Include the required headers
#include <QMainWindow>
#include <QtCore>
#include <QDialog>
#include <QtGui>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rb1_effective_phase_calcs_clicked();

    void on_rb2_2_phase_rel_per_calcs_clicked();

    void on_proceed_clicked();

private:
    Ui::MainWindow *ui;
    int per_calcs;
};
#endif // MAINWINDOW_H
