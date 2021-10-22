#ifndef CHANGERMDP_H
#define CHANGERMDP_H

#include <QDialog>

namespace Ui {
class changermdp;
}

class changermdp : public QDialog
{
    Q_OBJECT

public:
    explicit changermdp(QWidget *parent = nullptr);
    ~changermdp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::changermdp *ui;
};

#endif // CHANGERMDP_H
