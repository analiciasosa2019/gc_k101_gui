#include "mainwindow.h"
#include <iostream>
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <windows.h>
#include <Windows.h>
#include <regex>
#include "ioapiset.h"
#include <QIODevice>
#include <QSerialPort>
#include "serialport.h"

char inputData[INPUT_BYTES];

char comport[] = "COM7";
char* port = comport;
SerialPort uart(port);

char lox[5] = {};
char fuel[5] = {};
char pneu[5] = {};
int m = 1;
int b_lox = 0;
int b_fuel = 0;
int b_pneu = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    if (uart.isConnected()) {
        std::cout << "Connected to " << port << std::endl;
    }
    else {
        std::cin.get();
    }

    QOverload<>::of(&MainWindow::uart_read);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::uart_read));
    timer->start(1000);

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
    /*if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }*/

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
    /*if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }*/
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
    /*if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }*/
}


void MainWindow::on_MVCloseBox_clicked()
{
    if (ui->MVCloseBox->checkState()) {
        ui->MV_indicator->setEnabled(false);
    }
    char szBuff[2] = {'4','\0'};
    DWORD dwBytesRead = 0;
    /*if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }*/
}


void MainWindow::on_MVOpenBox_clicked()
{
    if (ui->MVOpenBox->checkState()) {
        ui->MV_indicator->setEnabled(true);
    }
    char szBuff[2] = {'5','\0'};
    DWORD dwBytesRead = 0;
    /*if(!WriteFile(hSerial, szBuff, 1, &dwBytesRead, NULL)){
        std::cout << "Error Writing\n";
    }*/
}

void MainWindow::uart_read() {
    int lox_val, fuel_val, pneu_val;
    if (uart.ReadSerialPort(inputData, INPUT_BYTES) != 0) {
        std::string before_brace, after_brace;
        std::string inputValStr(inputData);
        size_t pos = inputValStr.find('}');

        if (pos != std::string::npos) {
            // Split the string
            before_brace = inputValStr.substr(0, pos);       // Everything before '}'
            after_brace = inputValStr.substr(pos+1);       // Everything after '}'

            // Combine the parts
            std::string result = after_brace + before_brace + '}';

            // Output the result
            std::cout << "Result: " << result << std::endl;
            lox_val = std::stoi(result.substr(1, 4));  // Extract 4 characters starting at position 1
            fuel_val = std::stoi(result.substr(6, 4)); // Extract 4 characters starting at position 6
            pneu_val = std::stoi(result.substr(11, 4));
        } else {
            std::cout << "No '}' found in the string!" << std::endl;
        }
        //std::cout << "recieved " << inputValStr.length() << " " << inputValStr << std::endl;
    }

    ui->lcdNumber->display(lox_val);
    ui->lcdNumber_2->display(fuel_val);
    ui->lcdNumber_3->display(pneu_val);
}

