#include "rel_per_calc_diag.h"
#include <cmath>
#include <QItemDelegate>
#include <QObject>
#include <QModelIndex>
rel_per_calc_diag::rel_per_calc_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rel_per_calc_diag)
{
    ui->setupUi(this);

}

rel_per_calc_diag::~rel_per_calc_diag()
{
    delete ui;
}
