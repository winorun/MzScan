#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QtWinExtras/QtWin>
#include <QClipboard>
#include <QFileDialog>

#include "Eztwain.h"
/**
 * @brief MainWindow::MainWindow
 * Конструктор. Соннектим кнопки, рескан, следующая страница и следующий номер.
 * @param parent
 */
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
    path = new QString(QDir::homePath());
    }

MainWindow::~MainWindow()
{
    delete path;
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
/**
 * @brief MainWindow::on_action_Rescan_triggered
 * основной слод, срабатывает при ресканане,
 * @node тут костыль
 */
void MainWindow::on_action_Rescan_triggered()
{
    if (TWAIN_OpenDefaultSource()) {
        if(ui->hideSetting->isChecked())TWAIN_SetHideUI(1); // ask for no user interface
        if(TWAIN_AcquireToClipboard(0,0x0002/*TWAIN_GRAY*/)){
            QClipboard *cl=QApplication::clipboard();
            QPixmap qpx = cl->pixmap();
            ui->label->setPixmap(qpx);

            if(qpx.save(*path+QString::asprintf("/%03i_%02i.tif",ui->spinBoxNumber->value(),
                                          ui->spinBoxPage->value()))){
                ui->textEdit->append("Image "+ *path + QString::asprintf("/%03i_%02i.tif save",
                                                       ui->spinBoxNumber->value(),
                                                       ui->spinBoxPage->value()));
            }else{
                ui->textEdit->append(QString::asprintf("Image not save"));
            }
        }else{
           ui->textEdit->append(QString::asprintf("Image not scan"));
        }
    }
}

void MainWindow::on_action_About_triggered()
{
    QString str="Программа предназначена для сканирования журналов и газет.\n каталог по умолчанию" + QDir::currentPath();
    QMessageBox::about(this, "О программе", str);
}

void MainWindow::on_action_Select_scanner_triggered()
{
    TWAIN_SelectImageSource(0);
    //static QString select= "";//QString(TWAIN_SourceName());
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
       if(ui->spinBoxPage->value()>ui->spinBoxMax->value()){
           ui->spinBoxNumber->stepUp();
           ui->spinBoxPage->setValue(1);
       }
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

void MainWindow::on_action_Path_triggered()
{
    *path=QFileDialog::getExistingDirectory(this, tr("Open Directory"),*path,
             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
}
