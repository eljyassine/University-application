#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabgestion.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


         if(connOpen())  ui->label->setText("open");
         else ui->label->setText("close");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_login_clicked()
{
    QString user,password;
    user= ui-> lineEdit_user->text();
    password= ui->lineEdit_password->text();

 if(! connOpen())  {qDebug()<<"failed to open the database";
                     return; }
     connOpen();
     QSqlQuery qry;

     qry.prepare("select * from login where user=' "+user+"' and password='"+password+"'");
 if (qry.exec())

 { int count=0;
     while(qry.next())
     {
         count++;
     }
       if (count==1)
       {
            ui->label->setText("username et password is correct");
            connClose();
            this->hide();
            tabgestion ttabgestion;
            ttabgestion.setModal(true);
            ttabgestion.exec();


       }
       if (count > 1)
           ui->label->setText("dublicateuser  et password");
       if (count< 1)
           ui->label->setText("user or password is not correct");
 }


}



void MainWindow::on_pushButton_clicked()
{

    changer= new changermdp(this);
    changer -> show();
}
