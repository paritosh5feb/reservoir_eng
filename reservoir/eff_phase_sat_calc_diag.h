#ifndef EFF_PHASE_SAT_CALC_DIAG_H
#define EFF_PHASE_SAT_CALC_DIAG_H

#include <QDialog>

namespace Ui {
class eff_phase_sat_calc_diag;
}


/* This file contains the class definition of the dialog box for effective phase saturation calculations.
 * The member functions are as per the UI.
*/

class eff_phase_sat_calc_diag : public QDialog
{
    Q_OBJECT

public:
    explicit eff_phase_sat_calc_diag(QWidget *parent = nullptr);
    ~eff_phase_sat_calc_diag();

private slots:
    void on_effective_phase_saturation_sog_calc_button_clicked();

    void on_effective_phase_saturation_sw_calc_button_clicked();

    void on_close_clicked();

private:
    Ui::eff_phase_sat_calc_diag *ui;
    int dec_imbibition_or_drainage;
};

#endif // EFF_PHASE_SAT_CALC_DIAG_H
