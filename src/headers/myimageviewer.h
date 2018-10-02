#ifndef MYIMAGEVIEWER_H
#define MYIMAGEVIEWER_H

#include <QWidget>

class QString;
/**
 * @brief Просмотр картинок с правильным маштабированием
 *
 */
class MyImageViewer : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief MyImageViewer конструктор
     * @param parent родительский элемент
     */
    explicit MyImageViewer(QWidget *parent=nullptr);
public slots:
    /**
     * @brief loadImage Загружаем изображение
     * @param fileName имя загружаемого файла
     */
    void loadImage(QString fileName);
    /**
     * @brief setPixmap
     * @param pixmap in Set QPixmap
     */
    void setPixmap(QPixmap &pixmap);
protected:
    /**
     * @brief paintEvent перегружпем отрисовку
     */
    void paintEvent(QPaintEvent *);

private:
    QPixmap pix;

};

#endif // MYIMAGEVIEWER_H
