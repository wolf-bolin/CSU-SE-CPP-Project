#ifndef RANKBROWSER_H
#define RANKBROWSER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

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

private slots:
    void getRankFinishedSlot(QNetworkReply *reply);

private:
    Ui::rankBrowser *ui;

    std::vector<gameinfo> gameRecord;//历史游戏记录
    std::vector<gameinfo> globalRecord;
    QNetworkAccessManager *manager;
    int globalRank;

    void getGlobalRank(int maxScore);
    void showLocalMessage();
};

#endif // RANKBROWSER_H