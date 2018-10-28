#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent* ev) override;
    void mousePressEvent(QMouseEvent* ev) override;

public slots:
    void onNewConnection();
    void onConnected();
    void onData();
    void onDisconnected();

private:
    Ui::MainWindow *ui;
    quint32 currentSize = 0;

    int posX = 100, posY = 150;

    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
};

#endif // MAINWINDOW_H
