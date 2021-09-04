/* Include the header file containing the class and member function definitions */
#include "eff_phase_sat_calc_diag.h"


/* Template code */
eff_phase_sat_calc_diag::eff_phase_sat_calc_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eff_phase_sat_calc_diag)
{
    ui->setupUi(this);
}

eff_phase_sat_calc_diag::~eff_phase_sat_calc_diag()
{
    delete ui;
}

