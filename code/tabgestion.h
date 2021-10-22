#ifndef TABGESTION_H
#define TABGESTION_H

#include <QDialog>

namespace Ui {
class tabgestion;
}

class tabgestion : public QDialog
{
    Q_OBJECT

public:
    explicit tabgestion(QWidget *parent = nullptr);
    ~tabgestion();
private slots:
        void on_pushButton_ajouter_3_clicked();
        void on_pushButton_supprimer_clicked();
        void on_load_etd_accepted();
        void on_pushButton_modifier_clicked();
        void on_pushButton_chercher_clicked();

        void on_buttonBox_affiche_groupe_accepted();
        void on_buttonBox_groupe_accepted();

        void on_pushButton_ajouter_N_clicked();
        void on_buttonBox_load_N_accepted();

        void on_pb_professeur_ajouter_2_clicked();

        void on_pb_professeur_supprimer_clicked();


        void on_loadtable_clicked();

        void on_pb_professeur_modifier_clicked();

        void on_table_professeur_activated(const QModelIndex &index);

        void on_pb_professeur_rech_clicked();


        void on_ajoute_salle_clicked();

        void on_modifier_salle_clicked();

        void on_supprimer_salle_clicked();

        void on_afficher_salle_clicked();

        void on_table_salle_activated(const QModelIndex &index);

        void on_lineEditrechercher_textEdited(const QString &arg1);



           void on_pb_ajoute_stage_clicked();
           void on_pb_modifier_stage_clicked();
           void on_pb_supprimer_stage_clicked();
private:
    Ui::tabgestion *ui;
};

#endif // TABGESTION_H
