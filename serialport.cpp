#include "SerialPort.h"
#include <iostream>

SerialPort::SerialPort(char* portName) {
    // setup
    errors - 0;
    status = { 0 };
    connected = false;

    handleToCOM = CreateFileA(static_cast<LPCSTR>(portName),
                              GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
                              FILE_ATTRIBUTE_NORMAL, NULL);

    // check for errors
    DWORD errMsg = GetLastError();

    if (errMsg == 2) {
        printf("Device not plugged in\n");
    }
    else if (errMsg == 5) {
        printf("Device already in use\n");
    }
    // if no errors, configure
    else if (errMsg == 0) {
        DCB dcbSerialParameters = { 0 };

        if (!GetCommState(handleToCOM, &dcbSerialParameters)) {
            printf("Failed to get current serial parameters\n");
        }
        else {
            dcbSerialParameters.BaudRate = CBR_115200;
            dcbSerialParameters.ByteSize = 8;
            dcbSerialParameters.StopBits = ONESTOPBIT;
            dcbSerialParameters.Parity = NOPARITY;
            dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(handleToCOM, &dcbSerialParameters)) {
                printf("Could not set serial parameters\n");
            }
            else {
                connected = true;
                PurgeComm(handleToCOM, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(WAIT_TIME);
            }
        }
    }
}

SerialPort::~SerialPort(){
    if (connected == true) {
        connected = false;
        CloseHandle(handleToCOM);
    }
}

int SerialPort::ReadSerialPort(char* buffer, unsigned int buf_size) {
    DWORD bytesRead;
    unsigned int toRead = buf_size;
    //PurgeComm(handleToCOM, PURGE_RXABORT|PURGE_RXCLEAR);
    //Sleep(5);
    ClearCommError(handleToCOM, &errors, &status);
    if (status.cbInQue > 0) {
        if (status.cbInQue >= buf_size) {
            toRead = buf_size;
        }
        else toRead = status.cbInQue;
    }

    if (ReadFile(handleToCOM, buffer, toRead, &bytesRead, NULL)) {
        PurgeComm(handleToCOM, PURGE_RXABORT|PURGE_RXCLEAR);
        return bytesRead;
    }
    return 0;
}

bool SerialPort::isConnected() {
    return connected;
}
