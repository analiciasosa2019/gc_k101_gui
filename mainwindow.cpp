#include "mainwindow.h"
#include <iostream>
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <windows.h>
#include <regex>

HANDLE hSerial;

// variables declared here
std::string inputBuffer;
char lox[5] = {};
char fuel[5] = {};
char pneu[5] = {};
int m = 4;
int b_lox = -1800;
int b_fuel = -2200;
int b_pneu = -2400;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    hSerial = CreateFile(L"COM7",
                                GENERIC_READ | GENERIC_WRITE,
                                0,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);

    ui->setupUi(this);
    if (hSerial==INVALID_HANDLE_VALUE){
        if(GetLastError()==ERROR_FILE_NOT_FOUND){
            std::cout << "File doesn't exist";
        }
        std::cout << "Error opening but file exists";
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        //error getting state
    }
    dcbSerialParams.BaudRate=CBR_115200;
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    if(!SetCommState(hSerial, &dcbSerialParams)){
        //error setting serial port state
    }

    COMMTIMEOUTS timeouts={0};
    timeouts.ReadIntervalTimeout=50;
    timeouts.ReadTotalTimeoutConstant=50;
    timeouts.ReadTotalTimeoutMultiplier=10;
    timeouts.WriteTotalTimeoutConstant=50;
    timeouts.WriteTotalTimeoutMultiplier=10;
    if(!SetCommTimeouts(hSerial, &timeouts)){
        //error occureed. Inform user
    }
    QOverload<>::of(&MainWindow::uart_read);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::uart_read));
    timer->start(25);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ventLoxBox_clicked()
{
    if (ui->ventLoxBox->checkState()) {
        ui->LV_indicator->setEnabled(true);
    }
    else {
        ui->LV_indicator->setEnabled(false);
    }
    char szBuff[2] = {'1','\0'};
    DWORD dwBytesRead = 0;
    if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }

}


void MainWindow::on_ventFuelBox_clicked()
{
    if (ui->ventFuelBox->checkState()) {
        ui->FV_indicator->setEnabled(true);
    }
    else {
        ui->FV_indicator->setEnabled(false);
    }
    char szBuff[2] = {'2','\0'};
    DWORD dwBytesRead = 0;
    if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }
}


void MainWindow::on_igniteBox_clicked()
{
    if (ui->igniteBox->checkState()) {
        ui->Ign_indicator->setEnabled(true);
    }
    else {
        ui->Ign_indicator->setEnabled(false);
    }
    char szBuff[2] = {'3','\0'};
    DWORD dwBytesRead = 0;
    if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }
}


void MainWindow::on_MVCloseBox_clicked()
{
    if (ui->MVCloseBox->checkState()) {
        ui->MV_indicator->setEnabled(false);
    }
    char szBuff[2] = {'4','\0'};
    DWORD dwBytesRead = 0;
    if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }
}


void MainWindow::on_MVOpenBox_clicked()
{
    if (ui->MVOpenBox->checkState()) {
        ui->MV_indicator->setEnabled(true);
    }
    char szBuff[2] = {'5','\0'};
    DWORD dwBytesRead = 0;
    if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }
}

void MainWindow::uart_read() {
    int len=1;
    char input[50] = {};
    DWORD dwBytesRead = 0;

    // Read from serial port
    if(!ReadFile(hSerial, input, len, &dwBytesRead, NULL)) {
        std::cout << "Error Reading\n";
        return;
    }

    input[dwBytesRead] = '\0';  // Null-terminate the string based on actual bytes read
    std::cout << "Received: " << input << std::endl;

    // Accumulate the received data in the inputBuffer
    inputBuffer += input;

    // Check if there's a complete message with '{' and '}'
    size_t start = inputBuffer.find('{');
    size_t end = inputBuffer.find('}', start);

    // If both '{' and '}' are found, extract the message between them
    if (start != std::string::npos && end != std::string::npos && end > start) {
        std::string message = inputBuffer.substr(start + 1, end - start - 1); // Extract content between '{' and '}'
        std::cout << "Extracted data: " << message << std::endl;

        // Clear processed part of the buffer
        inputBuffer = inputBuffer.substr(end + 1);
        std::strncpy(lox, &message[0], 4);
        lox[4] = '\0';  // Null-terminate the extracted string

        std::strncpy(fuel, &message[5], 4);
        fuel[4] = '\0';  // Null-terminate the extracted string

        std::strncpy(pneu, &message[10], 4);
        pneu[4] = '\0';  // Null-terminate the extracted string
    }
    int lox_val = (std::atoi(lox) + b_lox) / m;
    int fuel_val = (std::atoi(fuel) +b_fuel)*m;
    int pneu_val = (std::atoi(pneu) + b_pneu);


    //std::cout << output << '\t' << input << std::endl;

    ui->lcdNumber->display(lox_val);
    ui->lcdNumber_2->display(fuel_val);
    ui->lcdNumber_3->display(pneu_val);
}

