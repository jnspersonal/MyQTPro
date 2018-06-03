#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //this->style(QString("/new/css"))
    //loadStyleSheet(QString("/new"));//在构造函数里添加这一句，加载stylesheet

    ui->setupUi(this);
    this->initMainWin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_QuitButton_clicked()
{
    this->close();
}

void MainWindow::initMainWin()
{

    pMainWinTitleicon = new QIcon(":/new/background/02 earthicon.png");
    pMainWinTitleMov = new QMovie(":/new/background/03 pokebiome.gif");

    ui->PlayLabel->setMovie(pMainWinTitleMov);
    pMainWinTitleMov->start();
    //QLabel::styleSheet("");

    ui->TabWidget->setTabText(0, "Page1");
    ui->TabWidget->setTabText(1, "Page2");
    ui->TabWidget->setTabText(2, "Page3");

    this->setWindowIcon(*pMainWinTitleicon);
    this->setWindowTitle("RawDeep");
}

void MainWindow::on_ChangeButton_clicked()
{

}
