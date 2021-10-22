#ifndef UTILISATEURR_H
#define UTILISATEURR_H
#include"mainwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Utilisateurr; }
QT_END_NAMESPACE

class Utilisateurr : public QMainWindow
{
    Q_OBJECT


public:
    Utilisateurr(QWidget *parent = nullptr);
    ~Utilisateurr();
private slots:
    void on_pushButton_admin_clicked();
private:
    Ui::Utilisateurr *ui;
    MainWindow *mainWindow;
};
#endif // UTILISATEURR_H
