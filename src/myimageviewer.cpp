//MzScan Magazine Scaner
//MzScan Copyright@2017 winorun

//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program.  If not, see http://www.gnu.org/licenses/

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
//    QPixmap pmap;
//    if(pmap.load(fileName))pix = pmap;
    pix.load(fileName);
    this->repaint();
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
