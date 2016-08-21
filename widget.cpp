#include "widget.h"
#include "ui_widget.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    manager = new QNetworkAccessManager;

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void Widget::on_btn_search_clicked()
{
    QString idcard = ui->lineEdit->text();
    if(idcard.isEmpty()){
        QMessageBox::warning(this, tr("警告"), tr("请输入身份证号码!"));
        return;
    }
    ui->label_id->clear();
    ui->label_addr->clear();
    ui->label_birth->clear();
    ui->label_sex->clear();
    ui->label_animal->clear();
    ui->label_star->clear();

    QNetworkRequest request;
    request.setUrl(QString("http://apis.baidu.com/chazhao/idcard/idcard?idcard=%1").arg(idcard));
    request.setRawHeader("apikey", "b446bb51d329b1098b008568231a772b");

    manager->get(request);
}

void Widget::replyFinished(QNetworkReply *reply)
{
    QJsonObject data = QJsonDocument::fromJson(reply->readAll()).object();
    QJsonObject info = data.value("data").toObject();
    QString msg = data.value("msg").toString();
    int ret = msg.compare("succeed");
    qDebug() << "ret:" << ret << msg;
    if(ret != 0){
        QMessageBox::warning(this, tr("警告"), msg);
        return;
    }

    QString IDCard = info.value("idcard").toString();
    QString addr = info.value("address").toString();
    QString birth = info.value("birthday").toString();
    QString sex = info.value("gender").toString();
    QString animal = info.value("zodiac").toString();
    QString star = info.value("constellation").toString();

    ui->label_id->setText(IDCard);
    ui->label_addr->setText(addr);
    ui->label_birth->setText(birth);
    ui->label_sex->setText(sex);
    ui->label_animal->setText(animal);
    ui->label_star->setText(star);
}
