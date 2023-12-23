#ifndef FLORENCE_H
#define FLORENCE_H
#include <QObject>
#include <QDBusConnection>
#include <QDBusInterface>

class FlorenceInterface : public QObject {
    Q_OBJECT
public:
    explicit FlorenceInterface(QObject *parent = nullptr) : QObject(parent) {
        // 创建一个表示 Florence 键盘的 D-Bus 接口对象
        m_florenceInterface = new QDBusInterface("org.florence.Keyboard",
                                                 "/org/florence/Keyboard",
                                                 "org.florence.Keyboard",
                                                 QDBusConnection::sessionBus(),
                                                 this);
    }
    ~FlorenceInterface(){delete m_florenceInterface;}

    // 隐藏 Florence 键盘
    void hide() {if (m_florenceInterface) m_florenceInterface->call("hide");}
    // 显示 Florence 键盘
    void show() {if (m_florenceInterface) m_florenceInterface->call("show");}
    // 移动 Florence 键盘
    void move(uint x, uint y) {
        if (m_florenceInterface)
            m_florenceInterface->call("move", x, y);
    }
    // 移动 Florence 键盘并设置宽和高，ratio：1 保持宽高比例; 0 不保持宽高比例
    void move_to(uint x, uint y, uint h, uint w, uint ratio) {
        if (m_florenceInterface)
            m_florenceInterface->call("moveto", x, y, w, h, ratio);
    }
    // 移动florence悬浮图标
    void move_icon(uint x, uint y) {
        if (m_florenceInterface)
            m_florenceInterface->call("icon_move", x, y);
    }

private:
    QDBusInterface *m_florenceInterface;
};

#endif // FLORENCE_H
