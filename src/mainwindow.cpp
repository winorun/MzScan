#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
//#include <QtWin>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

//#include "Eztwain.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    {
//        QLabel *lbl=&QLabel(" ");//new QLabel(QString(TWAIN_SourceName()),this);
//        ui->statusBar->addWidget(lbl);
//        this->connect(this,SIGNAL(valueScannerChanged(QString)),lbl,SLOT(setText(QString)));
    }
    this->connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(on_action_Next_Page_triggered()));
    this->connect(ui->pushButton_NextNumber,SIGNAL(clicked(bool)),this,SLOT(on_actionNext_Namber_triggered()));
    this->connect(ui->pushButton_Rescan,SIGNAL(clicked(bool)),this,SLOT(on_action_Rescan_triggered()));

    }

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @todo убрать Scan->Input. Функция которая ее вызывает вызывается при первом вызове любой другой на скан.
 * Не убирать todo отменен
 */
void MainWindow::on_actionFullScreen_triggered(bool checked)
{
    if(checked)this->showFullScreen();
    else this->showNormal();
}

void MainWindow::on_actionRusssia_triggered()
{

}

void MainWindow::on_action_Rescan_triggered()
{/*
//    static HBITMAP data;
    if (TWAIN_OpenDefaultSource()) {
        TWAIN_SetHideUI(1); // ask for no user interface
//        TWAIN_SetResolution(300); // ask for 300 DPI
//        TWAIN_SetPixelType(TWPT_GRAY);
        HANDLE hdib = TWAIN_AcquireNative(0,0);

//      data =
//        TWAIN_FreeNative(hdib);
//    QPixmap qpx = QtWin::fromHBITMAP(data);
//    ui->label->setPixmap(qpx);
      HWND hwnd = (HWND)ui->label->winId();
      HDC hDC = GetDC(hwnd);
      int Width=TWAIN_DibWidth(hdib);
      // Width of DIB, in pixels (columns)
      int Height=TWAIN_DibHeight(hdib);
      // Height of DIB, in lines (rows)

//    TWAIN_CreateDibPalette(hdib);
      TWAIN_DrawDibToDC(hDC,0,0,Width,Height,hdib,0,0);
    }
//    if(qpx.save(QDir::currentPath()+QString::asprintf("/%03i_%02i.tif",ui->spinBoxNumber->value(),
//                                  ui->spinBoxPage->value()))){
//        ui->textEdit->append(QString::asprintf("Image %03i_%02i.tif save",
//                                               ui->spinBoxNumber->value(),
//                                               ui->spinBoxPage->value()));
//    }else{
//        ui->textEdit->append(QString::asprintf("Image not save"));
//    }*/
}

void MainWindow::on_action_About_triggered()
{
    QString str="Программа предназначена для сканирования журналов и газет.\n каталог по умолчанию" + QDir::currentPath();
    QMessageBox::about(this, "О программе", str);
}

void MainWindow::on_action_Select_scanner_triggered()
{
    //TWAIN_SelectImageSource(0);
    static QString select= "";//QString(TWAIN_SourceName());
    //emit valueScannerChanged(select);
}


void MainWindow::on_action_Next_Page_triggered()
{
    if(!ui->checkBox->isChecked()){
        ui->spinBoxPage->stepDown();
        if(ui->spinBoxPage->value()==0)
        {
            ui->spinBoxNumber->stepDown();
            ui->spinBoxPage->setValue(ui->spinBoxMax->value());
        }
    }else{
       ui->spinBoxPage->stepUp();
    }
    this->on_action_Rescan_triggered();
}

void MainWindow::on_actionNext_Namber_triggered()
{
    if(!ui->checkBox->isChecked()){
       ui->spinBoxNumber->stepDown();
       ui->spinBoxPage->setValue(ui->spinBoxMax->value());
    }else{
        ui->spinBoxNumber->stepUp();
        ui->spinBoxPage->setValue(1); // 1 - this is fist page
    }

    this->on_action_Rescan_triggered();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
        ui->spinBoxMax->setEnabled(!checked);
}
