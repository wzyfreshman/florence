#ifndef DBUSCLIENT_H
#define DBUSCLIENT_H
#include <QMainWindow>
#include <QMoveEvent>
#include "florence.h"

namespace Ui {
class DbusClient;
}

class DbusClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit DbusClient(QWidget *parent = 0);
    ~DbusClient();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DbusClient *ui;
    FlorenceInterface *florence;
};



#endif // DBUSCLIENT_H
