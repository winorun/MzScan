#ifndef MYIMAGEVIEWER_H
#define MYIMAGEVIEWER_H

#include <QWidget>

class QString;
class MyImageViewer : public QWidget
{

    Q_OBJECT

public:
    explicit MyImageViewer(QWidget *parent=0);
public slots:
    void loadImage(QString fileName);
    void setPixmap(QPixmap &pixmap);
protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap pix;

};

#endif // MYIMAGEVIEWER_H
