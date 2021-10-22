#include "stagepfe.h"
#include<QString>
#include<QDate>
#include <QDebug>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
stagepfe::stagepfe()
{   id_stagepfe="";
    intitule ="";
    description ="";
     mot_cle="";
     note_pfe= "";
     date_fin="";
}

stagepfe::stagepfe(QString id_stagepf,QString intitul,QString descriptio,QString mot_cl,QString note_pf, QString date_fi)
{ id_stagepfe=id_stagepf;
  intitule=intitul;
   description = descriptio ;
    mot_cle= mot_cl;
    note_pfe = note_pf;
   date_fin=date_fi;


}
bool stagepfe::ajouter()
{
    QSqlQuery query;
    query.prepare("insert into stagepfe (intitule,description,mot_cle,note_pfe,date_fin) values ('"+intitule+"','"+description+"','"+mot_cle+"','"+note_pfe+"','"+date_fin+"')");
    return  query.exec();

}

bool stagepfe::modifier()
{
    QSqlQuery query;
   query.prepare("update stagepfe set id_stagepfe='"+id_stagepfe+"',intitule='"+intitule+"',description='"+description+",mot_cle='"+mot_cle+"',note_pfe='"+note_pfe+"',date_fin='"+date_fin+"' where id_stagepfe='"+id_stagepfe+"'");
    return  query.exec();

}
bool stagepfe::supprimer(QString x)
{
    QSqlQuery query;
   query.prepare("Delete from stagepfe where id_stagepfe='"+x+"' ");
    return  query.exec();

}



