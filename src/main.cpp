#include "headers/mainwindow.h"
#include <QApplication>
#include <QTranslator>

//! @todo Добавить иконку

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QTranslator qtTranslator;
//       qtTranslator.load("untitled_ru.ts");
//       app.installTranslator(&qtTranslator);


    MainWindow w;
//    app.setWindowIcon(QIcon(":/icons/scanner.png"));
    w.show();

    return app.exec();
}
