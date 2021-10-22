#include "utilisateurr.h"
#include "ui_utilisateurr.h"
#include"mainwindow.h"
Utilisateurr::Utilisateurr(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Utilisateurr)
{
    ui->setupUi(this);
}

Utilisateurr::~Utilisateurr()
{
    delete ui;
}

void Utilisateurr::on_pushButton_admin_clicked()
{
    hide();
   mainWindow= new MainWindow(this);
    mainWindow -> show();
}
