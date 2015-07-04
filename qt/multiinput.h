#ifndef MULTIINPUT_H
#define MULTIINPUT_H

#include <QWidget>
#include <QtGui>
#include <QKeyEvent>
#include <QTcpSocket>
#include <unordered_map>

using std::unordered_map;


class QTcpSocket;
class QNetworkSession;

namespace Ui {
class MultiInput;
}

class MultiInput : public QWidget
{
    Q_OBJECT

public:
    explicit MultiInput(QWidget *parent = 0);
    ~MultiInput();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void readStream();
    void socketConnected();

    void on_connectButton_clicked();

private:
    void enableConnect();
    void enableDisconnect();
    void updatePressedKeys(QKeyEvent *event);
    int QtToDirectInput(qint64 key);

    Ui::MultiInput *ui;
    unordered_map<int, bool> keys;
    unordered_map<qint64, int> keyRemap;
    QTcpSocket *tcpSocket;
    quint16 blockSize;

    QNetworkSession *networkSession;
};

#endif // MULTIINPUT_H
