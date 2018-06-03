#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QIcon>

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

private:
    Ui::MainWindow *ui;
    QMovie *pMainWinTitleMov;
    QIcon  *pMainWinTitleicon;

private:
    void initMainWin();
};

#endif // MAINWINDOW_H
