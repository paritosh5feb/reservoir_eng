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

void rel_per_calc_diag::on_oil_water_rel_per_calc_clicked()
{
    double sw_star,swc, sw, so, sg,kro, krw;
    QString out;
    bool ok = false;
    struct MyData
    {
        double sw;
        double sw_star;
        double kro;
        double krw;
    };
    swc = ui->t1_sw->toPlainText().toDouble(&ok);
    so =ui->t2_so->toPlainText().toDouble(&ok);
    sg = ui->tg->toPlainText().toDouble(&ok);
    int i = 0;
    QVector<MyData> data;
    QList<QStandardItem*> rowData;
    if(sand_type==1)
    {
        sw = swc;
        ui->lbl_out->clear();
        ui->lbl_out->append(QString("sw    sw_star    kro    krg"));
        while(i<7)
        {
            sw_star = (sw-swc)/(1-swc);
            kro = std::pow((1-sw_star),3.0);
            krw = std::pow(sw_star,3.0);
            ui->lbl_out->append(QString::number(sw)+"   "+QString::number(sw_star)+"    "+QString::number(kro)+"    "+QString::number(krw)+"\n");
            data.append({sw,sw_star,kro,krw});
            sw += 0.05;
            i = i+1;
        }

    }
    if(sand_type==2)
    {
        double so_star;
        ui->lbl_out->clear();
        ui->lbl_out->append(QString("sw    sw_star    kro    krg"));
        sw = swc;
        while(i<7)
        {
            so_star = so/(1-sw);
            sw_star = (sw-swc)/(1-swc);
            kro = std::pow((1-sw_star),2.0)*(1-std::pow(sw_star,1.5));
            krw = std::pow(so_star,3.5);
            ui->lbl_out->append(QString::number(sw)+"   "+QString::number(sw_star)+"    "+QString::number(kro)+"    "+QString::number(krw)+"\n");
            data.append({sw,sw_star,kro,krw});
            sw += 0.05;
            i = i+1;
        }
    }
    if(sand_type==3)
    {
        double so_star;
        ui->lbl_out->clear();
        ui->lbl_out->append(QString("sw    sw_star    kro    krg"));
        sw = swc;
        while(i<7)
        {
            so_star = so/(1-sw);
            sw_star = (sw-swc)/(1-swc);
            kro = std::pow((1-sw_star),2.0)*(1-std::pow(sw_star,2.0));
            krw = std::pow(so_star,4.0);
            ui->lbl_out->append(QString::number(sw)+"   "+QString::number(sw_star)+"    "+QString::number(kro)+"    "+QString::number(krw)+"\n");
            data.append({sw,sw_star,kro,krw});
            sw += 0.05;
            i = i+1;
        }
    }

}

void rel_per_calc_diag::on_gas_oil_rel_per_calc_clicked()
{
    double sw_star,swc, sw, so, sg,kro, krw;
    QString out;
    bool ok = false;
    struct MyData
    {
        double sw;
        double sw_star;
        double kro;
        double krw;
    };
    swc = ui->t1_sw->toPlainText().toDouble(&ok);
    so =ui->t2_so->toPlainText().toDouble(&ok);
    sg = ui->tg->toPlainText().toDouble(&ok);
    int i = 0;
    QVector<MyData> data;
    QList<QStandardItem*> rowData;
    if(sand_type==1)
    {
        sw = swc;
        double so_star;
        ui->lbl_out->clear();
        ui->lbl_out->append(QString("sg    so    so_star    kro    krg"));
        while(i<7)
        {
            so = 1-sg-swc;
            so_star = so/(1-swc);
            kro = std::pow(so_star,3.0);
            krw = std::pow((1-so_star),3.0);
            ui->lbl_out->append(QString::number(sg)+"   "+QString::number(so)+"    "+QString::number(so_star)+"    "+QString::number(kro)+"    "+QString::number(krw)+"\n");

            data.append({sw,sw_star,kro,krw});
            sg += 0.05;
            i = i+1;
        }

    }
    if(sand_type==2)
    {
        sw = swc;
        double so_star;
        ui->lbl_out->clear();
        ui->lbl_out->append(QString("sg    so    so_star    kro    krg"));
        while(i<7)
        {
            so = 1-sg-swc;
            so_star = so/(1-swc);
            kro = std::pow(so_star,3.5);
            krw = std::pow((1-so_star),2.0)*(1-std::pow(so_star,1.5));
            ui->lbl_out->append(QString::number(sg)+"   "+QString::number(so)+"    "+QString::number(so_star)+"    "+QString::number(kro)+"    "+QString::number(krw)+"\n");

            data.append({sw,sw_star,kro,krw});
            sg += 0.05;
            i = i+1;
        }
    }
    if(sand_type==3)
    {
        sw = swc;
        double so_star;
        ui->lbl_out->clear();
        ui->lbl_out->append(QString("sg    so    so_star    kro    krg"));
        while(i<7)
        {
            so = 1-sg-swc;
            so_star = so/(1-swc);
            kro = std::pow(so_star,4.0);
            krw = std::pow((1-so_star),2.0)*(1-std::pow(so_star,2.0));
            ui->lbl_out->append(QString::number(sg)+"   "+QString::number(so)+"    "+QString::number(so_star)+"    "+QString::number(kro)+"    "+QString::number(krw)+"\n");

            data.append({sw,sw_star,kro,krw});
            sg += 0.05;
            i = i+1;
        }
    }
}

void rel_per_calc_diag::on_rel_per_when_one_is_given_calc_clicked()
{
    bool ok = false;
    QString out;
    double ans;
    double sw = ui->t1_sw->toPlainText().toDouble(&ok);
    double so = ui->t2_so->toPlainText().toDouble(&ok);
    double swc = ui->tswc->toPlainText().toDouble(&ok);
    double in = ui->t3_krw->toPlainText().toDouble(&ok);
    double sw_star = (sw-swc)/(1-swc);
    double so_star = so/(1-swc);
    if(kro_or_krw_is_given==1)
    {
        ans = std::pow(sw_star,2.0) - in*(sw_star/(1-sw_star));
    }
    if(kro_or_krw_is_given==2)
    {
        ans = std::pow(so_star,2.0) - in*(so_star/(1-so_star));
    }
    out = QString::number(ans);
    ui->ans->clear();
    ui->ans->appendPlainText(out);
}

void rel_per_calc_diag::on_kro_from_krg_calc_clicked()
{
    double krg, so, kro;
    QString out;
    bool ok = false;
    so = ui->t2_so->toPlainText().toDouble(&ok);
    krg = ui->t5_krg->toPlainText().toDouble(&ok);
    kro = krg*((std::pow(so, 4.0))/(std::pow((1-so),2.0)*(1-std::pow(so,2.0))));
    out = QString::number(kro);
    ui->lbl_kro->setText(out);
}

void rel_per_calc_diag::on_rb1_imbibition_clicked()
{
    dec_imbibition_or_drainage = 1;
}

void rel_per_calc_diag::on_rb2_drainage_clicked()
{
    dec_imbibition_or_drainage = 2;
}

void rel_per_calc_diag::on_rb3_calc_for_wetting_clicked()
{
    dec_imbibition_or_drainage = 3;
}

void rel_per_calc_diag::on_kr_wetting_non_wetting_calc_clicked()
{
    double kr, sw, swc, snw;
    QString out;
    bool ok = false;
    double sw_star = 0;
    sw = ui->t6_sw->toPlainText().toDouble(&ok);
    swc = ui->t8_swc->toPlainText().toDouble(&ok);
    snw = ui->t7_snw->toPlainText().toDouble(&ok);
    if(dec_imbibition_or_drainage == 1)
    {
        kr = std::pow((1-((sw-swc)/(1-sw-swc))), 2.0);
        out = QString::number(kr);
        ui->lbl_kr_wetting_non_wetting->setText(out);
    }
    if(dec_imbibition_or_drainage==2)
    {
        sw_star = (sw-swc)/(1-swc);
        kr = (1-sw_star)*std::pow((1-std::pow(sw_star,0.25))*std::pow(sw,0.5), 0.5);
        out = QString::number(kr);
        ui->lbl_kr_wetting_non_wetting->setText(out);
    }
    if(dec_imbibition_or_drainage==3)
    {
        sw_star = (sw-swc)/(1-swc);
        kr = std::pow(sw_star,0.5)*std::pow(sw,3.0);
        out = QString::number(kr);
        ui->lbl_kr_wetting_non_wetting->setText(out);
    }
}

void rel_per_calc_diag::on_rel_diag_close_clicked()
{
    rel_per_calc_diag::close();
}

void rel_per_calc_diag::on_rb1_usws_clicked()
{
    sand_type = 1;
}

void rel_per_calc_diag::on_rb2_usps_clicked()
{
    sand_type = 2;
}

void rel_per_calc_diag::on_rb3_csol_clicked()
{
    sand_type = 3;
}



void rel_per_calc_diag::on_rb1_kro_is_given_clicked()
{
    kro_or_krw_is_given = 1;
}

void rel_per_calc_diag::on_radioButton_clicked()
{
    kro_or_krw_is_given = 2;
}
