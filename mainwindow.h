#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMovie>
#include <QIcon>
#include <QPixmap>
#include <QScreen>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <QTimer>

#define MAINWINDOW_DELAY_BY_PROCESSEVENTS 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_QuitButton_clicked();

    void on_ChangeButton_clicked();

    void on_GrabAllButton_clicked();

    void on_GrabClearButton_clicked();

private:
    Ui::MainWindow *ui;
    QMovie *pMainWinTitleMov;
    QIcon  *pMainWinTitleicon;
    QPixmap GrabPixMap;

private:
    void initMainWin();
    void mySleep(unsigned int msec);
};

#endif // MAINWINDOW_H
