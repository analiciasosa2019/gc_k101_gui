#ifndef SERIALPORT_H
#define SERIALPORT_H

#define WAIT_TIME 2000
#define INPUT_BYTES 16

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class SerialPort
{
private:
    HANDLE handleToCOM;
    bool connected;
    COMSTAT status;
    DWORD errors;
public:
    SerialPort(char* portName);
    ~SerialPort();

    int ReadSerialPort(char* buffer, unsigned int buf_size);
    bool isConnected();
};

#endif // SERIALPORT_H
