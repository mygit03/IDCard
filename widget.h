#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QNetworkAccessManager;
class QNetworkReply;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void init();

private slots:
    void on_btn_search_clicked();

    void replyFinished(QNetworkReply* reply);

private:
    Ui::Widget *ui;

    QNetworkAccessManager *manager;
};

#endif // WIDGET_H
