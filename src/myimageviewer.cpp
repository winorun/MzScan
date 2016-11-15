#include "myimageviewer.h"
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

MyImageViewer::MyImageViewer(QWidget *parent):QWidget(parent)
{

}

void MyImageViewer::loadImage(QString fileName)
{
    QPixmap pmap;
    pmap.load(fileName);
    pix = pmap;
}

void MyImageViewer::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    if (pix.isNull())
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int w=event->rect().width();

    QPixmap scaledPix = pix.scaledToWidth(w,
                                   Qt::FastTransformation);

    this->setFixedHeight(scaledPix.size().height());

    painter.drawPixmap(QPoint(), scaledPix);

}

void MyImageViewer::setPixmap(QPixmap &pixmap){
    pix = pixmap;
}
