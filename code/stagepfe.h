#ifndef STAGEPFE_H
#define STAGEPFE_H
#include<QString>
#include<QDate>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
class stagepfe
{
private:
    QString id_stagepfe;
    QString intitule;
    QString description;
    QString mot_cle;
    QString note_pfe;
    QString date_fin;
public:
     stagepfe();
     stagepfe(QString ,QString,QString , QString  , QString , QString);
    QString get_intitule() {return intitule;}
    QString get_description() {return description;}
    QString get_mot_cle() {return mot_cle;}
    QString get_note_pfe() {return note_pfe;}
    QString get_date_fin() {return date_fin;}
   bool ajouter();
   bool modifier();
 //QSqlQueryModel * afficher();
  bool supprimer(QString);
};

#endif // STAGEPFE_H
