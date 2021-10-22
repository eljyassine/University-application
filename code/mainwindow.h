#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"tabgestion.h"
#include"changermdp.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT
public :
    QSqlDatabase db;
    void connClose()
    {
      db.close();
      db.removeDatabase(QSqlDatabase::defaultConnection);

    }


    bool connOpen()
    {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       db.setHostName("localhost");
       db.setDatabaseName("C:/Users/Yassine/Desktop/db/stage.db");

      if(db.open()){ qDebug()<<"open database";
                      return true;
                   }
      else {qDebug()<<"failed open database";
            return false;
            }


     }

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
       changermdp *changer;
};

#endif // MAINWINDOW_H
