#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QLineEdit>
#include <QString>
#include "rawSocketService.h"
#include "prettyPrinter.h"
#include "icmpPrinter.h"
#include "ipPrinter.h"
#include "tcpPrinter.h"
#include "udpPrinter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void getPacketAndPrintHeaders();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    RawSocketService* rawSocketService = new RawSocketService();
    PrettyPrinter* ipPrinter = (PrettyPrinter*) new IpPrinter();

    void printHeader(std::wstring header);
};
#endif // MAINWINDOW_H
