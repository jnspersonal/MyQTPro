#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //this->style(QString("/new/css"))
    //loadStyleSheet(QString("/new"));//在构造函数里添加这一句，加载stylesheet

    ui->setupUi(this);
    this->initMainWin();
//    QFile file("./styles/default.qss");
//    file.open(QFile::ReadOnly);
//    QString styleSheet = file.readAll();//QLatin1String(file.readAll());
//    a.setStyleSheet(styleSheet);
    ui->TabWidget->setCurrentIndex(0);
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
    //pGrabPixMap = new QPixmap();

    ui->PlayLabel->setMovie(pMainWinTitleMov);
    pMainWinTitleMov->start();
    //QLabel::styleSheet("");

    ui->TabWidget->setTabText(0, "Page1");
    ui->TabWidget->setTabText(1, "Page2");
    ui->TabWidget->setTabText(2, "Page3");

    this->setWindowIcon(*pMainWinTitleicon);
    this->setWindowTitle("RawDeep");
}

void MainWindow::mySleep(unsigned int msec)
{
    //currentTime返回当前时间，加上需要延时的时间，到达演示msec时间的效果
    QTime reachTime = QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime() < reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::on_ChangeButton_clicked()
{

}

void MainWindow::on_GrabAllButton_clicked()
{
    this->hide();

#ifdef MAINWINDOW_DELAY_BY_QTIMER
    QTimer timer = new QTimer(this);
    timer->start(200 + timeComBox->value() * 1000);
#elif MAINWINDOW_DELAY_BY_PROCESSEVENTS
    mySleep(200);
#endif
    QScreen *screen = QGuiApplication::primaryScreen();
    GrabPixMap = screen->grabWindow(0);

    GrabPixMap.scaled(QSize(400,400), Qt::KeepAspectRatio);
    //ui->GrabShowLabel->resize(QSize(800,480));
    ui->GrabShowLabel->setStyleSheet("background-color:black");
    ui->GrabShowLabel->setPixmap(GrabPixMap);
    this->show();
}

void MainWindow::on_GrabClearButton_clicked()
{
    ui->GrabShowLabel->clear();
}
