#include "tabgestion.h"
#include "ui_tabgestion.h"
#include<QMessageBox>
#include <QtSql>
#include<QFileInfo>
#include<QtDebug>
#include <QDebug>
#include<QWidget>
#include<QString>
#include"mainwindow.h"
#include"stagepfe.h"
tabgestion::tabgestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tabgestion)
{
    ui->setupUi(this);
}

tabgestion::~tabgestion()
{
    delete ui;
}

void tabgestion::on_pushButton_ajouter_3_clicked()
{
MainWindow conn;
    QString Nom,Prenom,Sexe,CIN,Email,Adresse,Tel,ID_Etudiant,Groupe;
    ID_Etudiant=ui->lineEdit_id_etd->text();
    Nom=ui->lineEdit_nom->text();
  Prenom=ui->lineEdit_prenom->text();
  Sexe=ui->lineEdit_sexe->text();
  CIN=ui->lineEdit_CIN->text();
  //Date_de_Naissance=ui->
  Tel=ui->lineEdit_tel->text();
  Email=ui->lineEdit_email->text();
 Adresse=ui->lineEdit_adresse->text();
  Groupe=ui->lineEdit_groupe->text();
 // Filiere=ui->comboBox_filiere->currentText();
  //Niveau=ui->radioButton_ing->text();
  //Niveau=ui->radioButton_master->text();
   Groupe=ui->lineEdit_groupe->text();
 if(!conn.connOpen())  {
   qDebug()<<"failed to open the database";
  return; }
  conn.connOpen();
    QSqlQuery query;
  query.prepare("insert into espace_admin (ID_Etudiant,Nom,Prenom,CIN,Sexe,Email,Adresse,Tel,Groupe) values ('"+ID_Etudiant+"','"+Nom+"','"+Prenom+"','"+CIN+"','"+Sexe+"','"+Email+"','"+Adresse+"','"+Tel+"','"+Groupe+"')");

 if(query.exec())
  {
    QMessageBox::critical(this,tr("Save"),tr("Saved"));
    conn.connClose();
}
else
    QMessageBox::critical(this,tr("error::"),query.lastError().text());
}



void tabgestion::on_pb_ajoute_stage_clicked()

{    MainWindow conn;

    QString id_stagepfe =ui->line_id_stage-> text();
    QString intitule =ui->line_intitule_stage-> text();
     QString description=ui->line_description_stage-> text();
     QString mot_cle=ui->line_mot_stage-> text();
     QString  note_pfe=ui->line_note_pfe-> text();
     QString date_fin=ui->line_date_pfe-> text();
      if(! conn.connOpen())  {
          qDebug()<<"failed to open the database";
                          return; }
          conn.connOpen();

    stagepfe stage(id_stagepfe,intitule,description,mot_cle,note_pfe,date_fin);

   QSqlQuery query;

   bool test =stage.ajouter();

  if(test)
{
QMessageBox::critical(this,tr("Save"),tr("Saved"));
   conn.connClose();

}
  else
      QMessageBox::critical(this,tr("error::"),query.lastError().text());

}



void tabgestion::on_pb_modifier_stage_clicked()
{
    MainWindow conn;

         QString id_stagepfe =ui->line_id_stage-> text();
         QString intitule =ui->line_intitule_stage-> text();
         QString description=ui->line_description_stage-> text();
         QString mot_cle=ui->line_mot_stage-> text();
         QString  note_pfe=ui->line_note_pfe-> text();
         QString date_fin=ui->line_date_pfe-> text();
          if(! conn.connOpen())  {
              qDebug()<<"failed to open the database";
                              return; }
              conn.connOpen();
         QSqlQuery query;
       stagepfe stage(id_stagepfe,intitule,description,mot_cle,note_pfe,date_fin);

       bool test1 =stage.modifier();

       if(test1)
    {
    QMessageBox::critical(this,tr("edit"),tr("update"));
       conn.connClose();

    }
      else
          QMessageBox::critical(this,tr("error::"),query.lastError().text());

  }

void tabgestion::on_pb_supprimer_stage_clicked()
{
    MainWindow conn;

       QString id_stagepfe =ui->le_idstage_recherche-> text();

        if(! conn.connOpen())  {
            qDebug()<<"failed to open the database";
                            return; }
            conn.connOpen();

      stagepfe stage;
     QSqlQuery query;

     bool test =stage.supprimer(id_stagepfe);

    if(test)
  {
  QMessageBox::critical(this,tr("Delete"),tr("deleted"));
     conn.connClose();

  }
    else
        QMessageBox::critical(this,tr("error::"),query.lastError().text());

}




















void tabgestion::on_pushButton_supprimer_clicked()
{MainWindow conn;
    QString Nom,Prenom,Sexe,CIN,Email,Adresse,Tel,ID_Etudiant,Groupe;
    ID_Etudiant=ui->lineEdit_id_etd->text();
    Nom=ui->lineEdit_nom->text();
  Prenom=ui->lineEdit_prenom->text();
  Sexe=ui->lineEdit_sexe->text();
  CIN=ui->lineEdit_CIN->text();
  //Date_de_Naissance=ui->
  Tel=ui->lineEdit_tel->text();
  Email=ui->lineEdit_email->text();
 Adresse=ui->lineEdit_adresse->text();
  Groupe=ui->lineEdit_groupe->text();
  //Niveau=ui->radioButton_ing->text();
  //Niveau=ui->radioButton_master->text();
  Groupe=ui->lineEdit_groupe->text();
 if(!conn.connOpen())  {
   qDebug()<<"failed to open the database";
  return; }
   conn.connOpen();
    QSqlQuery query;
    query.prepare("delete from espace_admin where ID_Etudiant='"+ID_Etudiant+"'");
    if(query.exec())
     {
       QMessageBox::critical(this,tr("delete"),tr("deleted"));
       conn.connClose();
   }
   else
       QMessageBox::critical(this,tr("error::"),query.lastError().text());
}



void tabgestion::on_load_etd_accepted()
{MainWindow conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* q=new QSqlQuery(conn.db);
    q->prepare("select * from espace_admin");
    q->exec();
    modal->setQuery(*q);
    ui->table_etudiant_2->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());

}


void tabgestion::on_pushButton_modifier_clicked()
{MainWindow conn;
    QString Nom,Prenom,Sexe,CIN,Email,Adresse,Tel,ID_Etudiant,Groupe;
    ID_Etudiant=ui->lineEdit_id_etd->text();
    Nom=ui->lineEdit_nom->text();
  Prenom=ui->lineEdit_prenom->text();
  Sexe=ui->lineEdit_sexe->text();
  CIN=ui->lineEdit_CIN->text();
  //Date_de_Naissance=ui->
  Tel=ui->lineEdit_tel->text();
  Email=ui->lineEdit_email->text();
 Adresse=ui->lineEdit_adresse->text();
  Groupe=ui->lineEdit_groupe->text();
 if(!conn.connOpen())  {
   qDebug()<<"failed to open the database";
  return; }
   conn.connOpen();
    QSqlQuery query;
  query.prepare("UPDATE espace_admin set ID_Etudiant='"+ID_Etudiant+"',Nom='"+Nom+"',Prenom='"+Prenom+"',Sexe='"+Sexe+"',CIN='"+CIN+"',Tel='"+Tel+"',Email='"+Email+"',Adresse='"+Adresse+"',Groupe='"+Groupe+"' where ID_Etudiant='"+ID_Etudiant+"' ");

 if(query.exec())
  {
    QMessageBox::critical(this,tr("Edit"),tr("Updated"));
    conn.connClose();
}
else
    QMessageBox::critical(this,tr("error::"),query.lastError().text());
}




void tabgestion::on_pushButton_chercher_clicked()
{MainWindow conn;
    QString ID_Etudiant,CIN;
    ID_Etudiant=ui->lineEdit_id_etd_rechercher->text();
    CIN=ui->lineEdit_cin_recherche->text();
    if(!conn.connOpen())  {
      qDebug()<<"failed to open the database";
     return; }
      conn.connOpen();
       QSqlQuery query;
       query.prepare("select * from espace_admin where ID_Etudiant='"+ID_Etudiant+"' or CIN='"+CIN+"'");
       if(query.exec())
        {
           while(query.next())
           {
               ui->lineEdit_id_etd->setText(query.value(0).toString());
               ui->lineEdit_nom->setText(query.value(1).toString());
             ui->lineEdit_prenom->setText(query.value(2).toString());
             ui->lineEdit_sexe->setText(query.value(3).toString());
              ui->lineEdit_CIN->setText(query.value(4).toString());
             ui->lineEdit_tel->setText(query.value(5).toString());
             ui->lineEdit_email->setText(query.value(6).toString());
            ui->lineEdit_adresse->setText(query.value(7).toString());
             ui->lineEdit_groupe->setText(query.value(8).toString());
          }
             conn.connClose();
      }
      else
          QMessageBox::critical(this,tr("error::"),query.lastError().text());
   }




void tabgestion::on_buttonBox_affiche_groupe_accepted()
{MainWindow conn;
    QString groupe,ID_groupe;
    groupe=ui->lineEdit_groupe_2->text();
    ID_groupe=ui->lineEdit_id_groupe->text();
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* q=new QSqlQuery(conn.db);
    q->prepare("select ID_Etudiant, nom, prenom from espace_admin where groupe='"+groupe+"'");
    q->exec();
    modal->setQuery(*q);
    ui->tableView_groupe_etd->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

void tabgestion::on_buttonBox_groupe_accepted()
{
MainWindow conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* q=new QSqlQuery(conn.db);
    q->prepare("select distinct groupe from espace_admin ");
    q->exec();
    modal->setQuery(*q);
    ui->tableView_groupe->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

////////////////////lamis////////////////////
void tabgestion::on_pb_professeur_ajouter_2_clicked()
{MainWindow conn;
    QString id_personne= ui->lineEdit_professeur_id_personne->text();
    QString Nom=ui->lineEdit_professeur_nom->text();
    QString Prenom=ui->lineEdit_professeur_prenom->text();
    QString CIN=ui->lineEdit_professeur_CIN->text();

     QString Tel=ui->lineEdit_professeur_tel->text();
     QString Mail=ui->lineEdit_professeur_mail->text();
     QString Civilite=ui->lineEdit_professeur_civilite->text();
     QString Sexe =ui->lineEdit_professeur_sexe->text();
     QString Date_de_naissance=ui->dateEdit_professeur->text();


     QString Adresse=ui->lineEdit_professeur_adresse->text();
      QString Ssn=ui->lineEdit_professeur_ssn->text();
     QString Grade=ui->lineEdit_professeur_grade->text();
     QString Fonction_actuelle=ui->lineEdit_professeur_fonction->text();
     if(! conn.connOpen())  {
               qDebug()<<"failed to open the database";
                               return; }
               conn.connOpen();

QSqlQuery q;
q.prepare("insert into personne(id_personne, nom ,prenom,CIN,Num_tel,Mail, Civilite,adresse,ssn,grade,fonction_actuelle,sexe,date_de_naissance) values('"+id_personne+"','"+Nom+"','"+Prenom+"','"+CIN+"','"+Tel+"','"+Mail+"','"+Civilite+"','"+Adresse+"','"+Ssn+"','"+Grade+"','"+Fonction_actuelle+"','"+Sexe+"','"+Date_de_naissance+"')");
if(q.exec())
{
QMessageBox::critical(this,tr("Save"),tr("Saved"));
  conn.connClose();

}
  else
      QMessageBox::critical(this,tr("error::"),q.lastError().text());

}





void tabgestion::on_pb_professeur_supprimer_clicked()
{MainWindow conn;

    QString id_personne= ui->lineEdit_professeur_id_personne->text();
        QString Nom=ui->lineEdit_professeur_nom->text();
        QString Prenom=ui->lineEdit_professeur_prenom->text();
        QString CIN=ui->lineEdit_professeur_CIN->text();

         QString Tel=ui->lineEdit_professeur_tel->text();
         QString Mail=ui->lineEdit_professeur_mail->text();
         QString Civilite=ui->lineEdit_professeur_civilite->text();
         QString Sexe =ui->lineEdit_professeur_sexe->text();
         QString Date_de_naissance=ui->dateEdit_professeur->text();


         QString Adresse=ui->lineEdit_professeur_adresse->text();
          QString Ssn=ui->lineEdit_professeur_ssn->text();
         QString Grade=ui->lineEdit_professeur_grade->text();
         QString Fonction_actuelle=ui->lineEdit_professeur_fonction->text();
         if(! conn.connOpen())  {
                   qDebug()<<"failed to open the database";
                                   return; }
                   conn.connOpen();

    QSqlQuery q;
    q.prepare("delete from personne where nom='"+Nom+"'");
    if(q.exec())

        {
        QMessageBox::critical(this,tr("Suppression"),tr("Supprimé"));
          conn.connClose();

        }
          else
              QMessageBox::critical(this,tr("error::"),q.lastError().text());

        }

void tabgestion::on_loadtable_clicked()
{MainWindow conn;
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* q=new QSqlQuery(conn.db);
    q->prepare("select * from personne");
    q->exec();
    modal->setQuery(*q);
    ui->table_professeur->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());


}


void tabgestion::on_pb_professeur_modifier_clicked()
{MainWindow conn;
    QString id_personne= ui->lineEdit_professeur_id_personne->text();
         QString Nom=ui->lineEdit_professeur_nom->text();
         QString Prenom=ui->lineEdit_professeur_prenom->text();
         QString CIN=ui->lineEdit_professeur_CIN->text();
         QString Tel=ui->lineEdit_professeur_tel->text();
         QString Mail=ui->lineEdit_professeur_mail->text();
         QString Civilite=ui->lineEdit_professeur_civilite->text();
         QString Sexe =ui->lineEdit_professeur_sexe->text();
         QString Date_de_naissance=ui->dateEdit_professeur->text();
         QString Adresse=ui->lineEdit_professeur_adresse->text();
          QString Ssn=ui->lineEdit_professeur_ssn->text();
         QString Grade=ui->lineEdit_professeur_grade->text();
         QString Fonction_actuelle=ui->lineEdit_professeur_fonction->text();
         if(! conn.connOpen())  {
                   qDebug()<<"failed to open the database";
                                   return; }
                   conn.connOpen();

    QSqlQuery q;
    q.prepare("update personne set id_personne='"+id_personne+"',nom='"+Nom+"',prenom='"+Prenom+"',CIN='"+CIN+"',Num_tel='"+Tel+"',Mail='"+Mail+"',Civilite='"+Civilite+"',adresse='"+Adresse+"',ssn='"+Ssn+"',grade='"+Grade+"',fonction_actuelle='"+Fonction_actuelle+"',sexe='"+Sexe+"', date_de_naissance='"+Date_de_naissance+"' where id_personne='"+id_personne+"' ");
    if(q.exec())
    {
    QMessageBox::critical(this,tr("modification"),tr("modifié"));
      conn.connClose();
    }
      else
          QMessageBox::critical(this,tr("error::"),q.lastError().text());

}

void tabgestion::on_table_professeur_activated(const QModelIndex &index)
{MainWindow conn;
    QString val=ui->table_professeur->model()->data(index).toString();
    if(! conn.connOpen())  {
              qDebug()<<"failed to open the database";
                              return; }
              conn.connOpen();

QSqlQuery q;
q.prepare("select * from personne where id_personne='"+val+"'or nom='"+val+"'or prenom='"+val+"'or CIN='"+val+"'or Num_tel='"+val+"'or Mail='"+val+"'or Civilite='"+val+"'or adresse='"+val+"' or ssn='"+val+"'or grade='"+val+"'or fonction_actuelle='"+val+"' or sexe='"+val+"' or date_de_naissance='"+val+"' ");

if(q.exec())
{while(q.next())

       {
        ui->lineEdit_professeur_id_personne->setText(q.value(0).toString());
        ui->lineEdit_professeur_nom->setText(q.value(1).toString());
        ui->lineEdit_professeur_prenom->setText(q.value(2).toString());
        ui->lineEdit_professeur_sexe->setText(q.value(3).toString());
        ui->lineEdit_professeur_CIN->setText(q.value(4).toString());
        ui->lineEdit_professeur_ssn->setText(q.value(5).toString());
        ui->dateEdit_professeur->setDate(q.value(6).toDate());
        ui->lineEdit_professeur_tel->setText(q.value(7).toString());
        ui->lineEdit_professeur_mail->setText(q.value(8).toString());
        ui->lineEdit_professeur_adresse->setText(q.value(9).toString());
        ui->lineEdit_professeur_civilite->setText(q.value(10).toString());
        ui->lineEdit_professeur_grade->setText(q.value(11).toString());

        ui->lineEdit_professeur_fonction->setText(q.value(12).toString());
    } conn.connClose();

}
 else
     QMessageBox::critical(this,tr("error::"),q.lastError().text());


}


void tabgestion::on_pb_professeur_rech_clicked()
{MainWindow conn;
    QString val1=ui->rech_cin->text();
    QString val2 =ui->rech_ssn->text();

    if(! conn.connOpen())  {
              qDebug()<<"failed to open the database";
                              return; }
              conn.connOpen();

QSqlQuery q;
q.prepare("select * from personne where CIN='"+val1+"' or ssn='"+val2+"'");

if(q.exec())
{while(q.next())

       {
        ui->lineEdit_professeur_id_personne->setText(q.value(0).toString());
        ui->lineEdit_professeur_nom->setText(q.value(1).toString());
        ui->lineEdit_professeur_prenom->setText(q.value(2).toString());
        ui->lineEdit_professeur_sexe->setText(q.value(3).toString());
        ui->lineEdit_professeur_CIN->setText(q.value(4).toString());
        ui->lineEdit_professeur_ssn->setText(q.value(5).toString());
        ui->dateEdit_professeur->setDate(q.value(6).toDate());
        ui->lineEdit_professeur_tel->setText(q.value(7).toString());
        ui->lineEdit_professeur_mail->setText(q.value(8).toString());
        ui->lineEdit_professeur_adresse->setText(q.value(9).toString());
        ui->lineEdit_professeur_civilite->setText(q.value(10).toString());
        ui->lineEdit_professeur_grade->setText(q.value(11).toString());
        ui->lineEdit_professeur_fonction->setText(q.value(12).toString());
    } conn.connClose();

}
 else
     QMessageBox::critical(this,tr("error::"),q.lastError().text());


}

void tabgestion::on_pushButton_ajouter_N_clicked()
{
  MainWindow conn;
  QString Nom,Prenom,ID_Etudiant,ID_Matiere,nom_matiere,noteCC,noteEX,groupe;
  ID_Etudiant=ui->lineEdit_id_etd_N->text();
  Nom=ui->lineEdit_nom_N->text();
  Prenom=ui->lineEdit_prenom_N->text();
  ID_Matiere=ui->lineEdit_id_matiere_N->text();
  nom_matiere=ui->lineEdit_nom_matiere_N->text();
  noteCC=ui->lineEdit_noteCC_N->text();
  noteEX=ui->lineEdit_noteEX_N->text();
  groupe=ui->lineEdit_groupe_N->text();
 if(!conn.connOpen())  {
   qDebug()<<"failed to open the database";
  return; }
   conn.connOpen();
    QSqlQuery query;
  query.prepare("insert into notes (ID_Etudiant,Nom,Prenom,groupe,ID_Matiere,nom_matiere,noteCC,noteEX) values ('"+ID_Etudiant+"','"+Nom+"','"+Prenom+"','"+groupe+"','"+ID_Matiere+"','"+nom_matiere+"','"+noteCC+"','"+noteEX+"')");

 if(query.exec())
  {
    QMessageBox::critical(this,tr("Save"),tr("Saved"));
    conn.connClose();
}
else
    QMessageBox::critical(this,tr("error::"),query.lastError().text());
}

void tabgestion::on_buttonBox_load_N_accepted()
{
    MainWindow conn;
    QString groupe,ID_Matiere,nom_matiere;
    groupe=ui->lineEdit_groupe_N_2->text();
    ID_Matiere=ui->lineEdit_id_matiere_N_2->text();
    nom_matiere=ui->lineEdit_nom_matiere_N_2->text();
    QSqlQueryModel* modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* q=new QSqlQuery(conn.db);
    q->prepare("select * from notes where groupe='"+groupe+"'and nom_matiere='"+nom_matiere+"'");
    q->exec();
    modal->setQuery(*q);
    ui->tableView_N->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

//////////////////malek /////////////////////////////////////////
void tabgestion::on_ajoute_salle_clicked()
{
MainWindow conn;

        QString  ID_salle=ui->text_ID_salle->text();
        QString Nb_place=ui->text_Nb_place->text();
        QString Num_salle=ui->text_num_salle->text();
        QString type=ui->text_type->text();
        QString Materiel=ui->text_Materiel->text();

        if(!conn.connOpen())
        {

                  qDebug()<<"failed to open the database";
                                  return; }
                  conn.connOpen();
        QSqlQuery qry ;
        qry.prepare("insert into salle(ID_salle,Num_salle,Nb_place,Materiel,type)values('"+ID_salle+"','"+Num_salle+"','"+Nb_place+"','"+Materiel+"','"+type+"')");
        if(qry.exec())
        {
              QMessageBox::critical(this,tr("Save"),tr("saved"));
              conn.connClose();
        }
        else
        {
              QMessageBox::critical(this,tr("Error ::"),qry.lastError().text() );
        }

}



void tabgestion::on_modifier_salle_clicked()
{MainWindow conn;
  QString  ID_salle=ui->text_ID_salle->text();
  QString Nb_place=ui->text_Nb_place->text();
  QString Num_salle=ui->text_num_salle->text();
  QString type=ui->text_type->text();
  QString Materiel=ui->text_Materiel->text();

  if(!conn.connOpen())
  {

            qDebug()<<"failed to open the database";
                            return; }
            conn.connOpen();
  QSqlQuery qry ;
  qry.prepare("update salle set ID_salle='"+ID_salle+"',Nb_place='"+Nb_place+"',Num_salle='"+Num_salle+"', type='"+ type+"', Materiel='"+ Materiel+"'where ID_salle='"+ID_salle+"' ");
  if(qry.exec())
  {
        QMessageBox::critical(this,tr("Edit"),tr("updated"));
        conn.connClose();
  }
  else
  {
        QMessageBox::critical(this,tr("Error ::"),qry.lastError().text() );
  }
}

void tabgestion::on_supprimer_salle_clicked()
{MainWindow conn;
  QString  ID_salle=ui->text_ID_salle->text();
 // QString Nb_place=ui->text_Nb_place->text();
  //QString Num_salle=ui->text_num_salle->text();
 // QString type=ui->text_type->text();
  //QString Materiel=ui->text_Materiel->text();

  if(!conn.connOpen())
  {

            qDebug()<<"failed to open the database";
                            return; }
            conn.connOpen();
  QSqlQuery qry ;
  qry.prepare("Delete from salle where ID_salle='"+ID_salle+"' ");
  if(qry.exec())
  {
        QMessageBox::critical(this,tr("delete"),tr("deleted"));
        conn.connClose();
  }
  else
  {
        QMessageBox::critical(this,tr("Error ::"),qry.lastError().text() );
  }
}

void tabgestion::on_afficher_salle_clicked()
{MainWindow conn;

  QSqlQueryModel * modal= new QSqlQueryModel();
  conn.connOpen();
  QSqlQuery* qry= new QSqlQuery(conn.db) ;

  qry->prepare("select * from salle");
  qry->exec();
  modal->setQuery(*qry);
  ui->table_salle->setModel(modal);
  conn.connClose();
  qDebug() <<(modal->rowCount());


}





void tabgestion::on_table_salle_activated(const QModelIndex &index)
{MainWindow conn;
  QString  val =ui->table_salle->model()->data(index).toString();
     if(!conn.connOpen())
  {

            qDebug()<<"failed to open the database";
                            return; }
            conn.connOpen();
  QSqlQuery qry ;
  qry.prepare("select * from salle where Num_salle='"+val+"'or ID_salle='"+val+"' or Materiel='"+val+"' or type='"+val+"' or Nb_place='"+val+"' ");
  if(qry.exec())
  { while (qry.next())
      {
         ui->text_ID_salle->setText(qry.value(0).toString());
         ui->text_num_salle->setText(qry.value(1).toString());
         ui->text_type->setText(qry.value(2).toString());
         ui->text_Materiel->setText(qry.value(3).toString() );
         ui->text_Nb_place->setText(qry.value(4).toString());



      }


        conn.connClose();
  }
  else
  {
        QMessageBox::critical(this,tr("Error ::"),qry.lastError().text() );
  }


}





void tabgestion::on_lineEditrechercher_textEdited(const QString &arg1)
{MainWindow conn;
  QString  Num_salle =ui->lineEditrechercher->text();
     if(!conn.connOpen())
  {

            qDebug()<<"failed to open the database";
                            return; }
            conn.connOpen();
  QSqlQuery qry ;
  qry.prepare("select * from salle where Num_salle='"+Num_salle+"' ");
  if(qry.exec())
  { while (qry.next())
      {
         ui->text_ID_salle->setText(qry.value(0).toString());
         ui->text_Nb_place->setText(qry.value(4).toString());
         ui->text_num_salle->setText(qry.value(1).toString());
         ui->text_type->setText(qry.value(2).toString());
         ui->text_Materiel->setText(qry.value(3).toString() );
      }


        conn.connClose();
  }
  else
  {
        QMessageBox::critical(this,tr("Error ::"),qry.lastError().text() );
  }


}
