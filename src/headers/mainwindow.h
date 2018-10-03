#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class NumberAndPage;
/**
 * @brief The MainWindow class главного окна
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool scanImage(int number, int page);
    int lastPage;
    int lastNumber;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
  //void valueScannerChanged(const QString &text);
private slots:
    void on_actionFullScreen_triggered(bool checked);
    void on_action_Rescan_triggered();
    void on_action_About_triggered();
    void on_action_Select_scanner_triggered();
    void on_action_Next_Page_triggered();
    void on_actionNext_Namber_triggered();

    void on_checkBox_clicked(bool checked);

    void on_action_Path_triggered();
    void openLink(const QUrl &link);
private:
    Ui::MainWindow *ui;
    QString *path;
};

#endif // MAINWINDOW_H
