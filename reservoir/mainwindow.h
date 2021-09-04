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

/*
 * This file defines the class for the parent executable. The UI has the following components and their respective functions.
 * Radio_button 1
 * Radio_button 2
 * Proceed Button
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /* This function sets the global valirable "per_calcs" to 1 to launch the first dialog box, upon clicking the radio button 1 in the UI */
    void on_rb1_effective_phase_calcs_clicked();I

    /* This function sets the global valirable "per_calcs" to 2 to launch the second dialog box, upon clicking the radio button 2 in the UI */
    void on_rb2_2_phase_rel_per_calcs_clicked();

    void on_proceed_clicked(); //This function launches the dialog box as per the radio button selected in the previous step.

private:
    Ui::MainWindow *ui;
    int per_calcs;
};
#endif // MAINWINDOW_H
