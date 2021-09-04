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

/* Implementation of all the member functions in the class defined in the header file */
void eff_phase_sat_calc_diag::on_effective_phase_saturation_sog_calc_button_clicked()
{
    double sog;
    double swc;
    double output;
    bool ok = false;
    QString out;
    sog = ui->t1_s_og->toPlainText().toDouble(&ok);
    swc = ui->t2_s_wc->toPlainText().toDouble(&ok);
    output = sog/(1-swc);
    out = QString::number(output);
    ui->output->setText(out);
}

void eff_phase_sat_calc_diag::on_effective_phase_saturation_sw_calc_button_clicked()
{
    double swc;
    double sw;
    double output;
    bool ok = false;
    QString out;
    sw = ui->t3_s_w->toPlainText().toDouble(&ok);
    swc = ui->t4_s_wc->toPlainText().toDouble(&ok);
    output = (sw-swc)/(1-swc);
    out = QString::number(output);
    ui->output->setText(out);
}

void eff_phase_sat_calc_diag::on_close_clicked()
{
    eff_phase_sat_calc_diag::close();
}
