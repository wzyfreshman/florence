#include "dbusclient.h"
#include "ui_dbusclient.h"
#include <QDebug>

DbusClient::DbusClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DbusClient)
{
    ui->setupUi(this);
    florence = new FlorenceInterface;

    ui->lineEdit->installEventFilter(this);
    this->installEventFilter(this);
}

DbusClient::~DbusClient()
{
    delete ui;
}

bool DbusClient::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::FocusIn) {
        if (obj->inherits("QLineEdit")) {
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(obj);
            if (lineEdit) {
                florence->show();
            }
        }
    }
    if (event->type() == QEvent::FocusOut) {
        if (obj->inherits("QLineEdit")) {
            QLineEdit *lineEdit = qobject_cast<QLineEdit*>(obj);
            if (lineEdit) {
                florence->hide();
            }
        }
    }
    if (event->type() == QEvent::Move) {
                if (obj->inherits("QMainWindow")) {
                    // 当主窗口移动时，调整键盘位置
                    florence->move(this->x(),this->y());
                }
            }
    return QObject::eventFilter(obj, event);
}

void DbusClient::on_pushButton_clicked()
{
    florence->show();
}

void DbusClient::on_pushButton_2_clicked()
{
    florence->hide();
}
