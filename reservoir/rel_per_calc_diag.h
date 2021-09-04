#ifndef REL_PER_CALC_DIAG_H
#define REL_PER_CALC_DIAG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QStyle>
namespace Ui {
class rel_per_calc_diag;
}

class rel_per_calc_diag : public QDialog
{
    Q_OBJECT

public:
    explicit rel_per_calc_diag(QWidget *parent = nullptr);
    ~rel_per_calc_diag();

private slots:
    void on_oil_water_rel_per_calc_clicked();

    void on_gas_oil_rel_per_calc_clicked();

    void on_rel_per_when_one_is_given_calc_clicked();

    void on_kro_from_krg_calc_clicked();

    void on_rb1_imbibition_clicked();

    void on_rb2_drainage_clicked();

    void on_rb3_calc_for_wetting_clicked();

    void on_kr_wetting_non_wetting_calc_clicked();

    void on_rel_diag_close_clicked();

    void on_rb1_usws_clicked();

    void on_rb2_usps_clicked();

    void on_rb3_csol_clicked();



    void on_rb1_kro_is_given_clicked();

    void on_radioButton_clicked();

private:
    Ui::rel_per_calc_diag *ui;
    int sand_type;
    int kro_or_krw_is_given;
    int dec_imbibition_or_drainage;
    QStandardItemModel *model;
};

#endif // REL_PER_CALC_DIAG_H
