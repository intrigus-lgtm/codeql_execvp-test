#include <winsock2.h> // Include the necessary header file

#include <stddef.h>
#include <process.h>

void func()
{
    char dataBuffer[100] = "dir ";
    char *data = dataBuffer;
    size_t dataLen = strlen(data);
    int recvResult;

    SOCKET conn = INVALID_SOCKET;

    do
    { // setup socket and receive user input
        conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        recvResult = recv(conn, (char *)(data + dataLen), sizeof(char) * (100 - dataLen - 1), 0);
        // missing validation of recvResult
        data[dataLen + recvResult / sizeof(char)] = '\0';
    } while (0);
    char *args[] = {"%WINDIR%\\system32\\cmd.exe", "/c", data, NULL};
    _execvp("cmd.exe", args);
}
