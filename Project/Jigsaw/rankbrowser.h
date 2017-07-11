#ifndef RANKBROWSER_H
#define RANKBROWSER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QFontDatabase>
#include <QString>
#include <QFont>

#include "gamelogic.h"

namespace Ui {
class rankBrowser;
}

class rankBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit rankBrowser(QWidget *parent = 0);
    void loadData();
    ~rankBrowser();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void getRankFinishedSlot(QNetworkReply *reply);

    void on_sureButton_clicked();

private:
    Ui::rankBrowser *ui;

    std::vector<gameinfo> gameRecord;//历史游戏记录
    std::vector<gameinfo> globalRecord;
    QNetworkAccessManager *manager;
    int globalRank;

    void getGlobalRank(int maxScore);
    void showLocalMessage();

    QString ButtonStyle = "QPushButton{background-color:#907B63;"

                            "color: white;   border-radius: 10px;  border: 2px groove gray;"

                            "border-style: outset;}"

                            "QPushButton:hover{background-color:white; color: black;}"

                            "QPushButton:pressed{background-color:rgb(85, 170, 255);"

                            "border-style: inset; }";
};

#endif // RANKBROWSER_H
