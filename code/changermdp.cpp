#include "changermdp.h"
#include "ui_changermdp.h"
#include "mainwindow.h"
#include<QMessageBox>
changermdp::changermdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changermdp)
{
    ui->setupUi(this);
}

changermdp::~changermdp()
{
    delete ui;
}



void changermdp::on_pushButton_clicked()
{
    MainWindow conn;
        QString ancient,nouveau1,nouveau2,username;
      ancient=ui->LE_ancient->text();
      nouveau2=ui->lineEdit_n2->text();
    nouveau1=ui->lineEdit_n1->text();
      username=ui->lineEdit_user->text();
     if(!conn.connOpen())  {
       qDebug()<<"failed to open the database";
      return; }
       conn.connOpen();
        QSqlQuery query;
        if(nouveau1!=nouveau2){
             QMessageBox::critical(this,tr("les deux nouveaux mot de passe sont incompatible ::"),query.lastError().text());
        }else {
      query.prepare("UPDATE login set password='"+nouveau1+"', where user='"+username+"'");

     if(query.exec())
      {
        QMessageBox::critical(this,tr("Edit"),tr("Updated"));
        conn.connClose();
    }
    else
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }


}
