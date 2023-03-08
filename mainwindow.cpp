#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getPacketAndPrintHeaders();
}

MainWindow::~MainWindow()
{
    delete rawSocketService;
    delete ipPrinter;
    delete ui;
}

void MainWindow::getPacketAndPrintHeaders()
{
    auto source = this->findChild<QLineEdit*>("lineEdit");

    auto data = rawSocketService->getPacket();

    auto headersString = ipPrinter->getPrettyHeaderStr(data);
    auto protocolInstanceCode = std::to_integer<short>(data.value()[9]);
    data->erase(data->begin(), data->begin() + 56);
    std::wstring contentHeader;


    switch (protocolInstanceCode)
    {
        case 6:
        {
            contentHeader = TcpPrinter().getPrettyHeaderStr(data);
            break;
        }
        case 17:
        {
            contentHeader = UdpPrinter().getPrettyHeaderStr(data);
            break;
        }
        case 1:
        {
            contentHeader = IcmpPrinter().getPrettyHeaderStr(data);
            break;
        }
        default:
        {
            contentHeader = L"Protocol number " + std::to_wstring(std::to_integer<short>(data.value()[9]));
        }
    }

    headersString.append(L"\n\n");
    headersString.append(contentHeader);
    printHeader(headersString);
}

void MainWindow::printHeader(std::wstring header)
{
    auto textBrowser = this->findChild<QTextBrowser*>("textBrowser");
    textBrowser->setText(QString::fromWCharArray(header.c_str()));
}

void MainWindow::on_pushButton_clicked()
{
    getPacketAndPrintHeaders();
}
