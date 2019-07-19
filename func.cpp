#include "func.h"
#include <iostream>
#include "fstream"
#include <QApplication>
#include <winsock2.h>
#include <iostream>

using namespace std;

bool Func(char type, int cof, bool milk, int milkcon, bool choc, int choccon, bool sugar, int sugarcon, bool serv, int size){
    fstream file("result.txt", ios::in | ios::out | ios::app);
    int i = 1;



    struct cofya {
    char type = ' '; //сюда заносится наименование кофя
    int size = 0; //размер
    int cof = 0; //крепкость
    bool milk = false; //необходимость молока
    int milkcon = 0; //концентрация молока
    bool choc = false; //необходимость шоколада
    int choccon = 0; //концентрация шоколада
    bool sugar = false; //наличие сахара
    int sugarcon = 0; //концентрация сахара
    bool serv = false; //проверка на обслуживание
    }sended;
    bool res;
    sended.type = type;
    sended.size = size;
    sended.cof = cof;
    sended.milk = milk;
    sended.milkcon = milkcon;
    sended.choc = choccon;
    sended.sugar = sugar;
    sended.sugarcon = sugarcon;
    sended.serv = serv;
    WSAData wsaData;
        WORD DLLVersion = MAKEWORD(2, 1);
        if (WSAStartup(DLLVersion, &wsaData) != 0) {
            std::cout << "Error" << std::endl;
            system("pause");
            exit(1);
        }
        SOCKADDR_IN addr;
        int sizeofaddr = sizeof(addr);
        addr.sin_addr.s_addr = inet_addr("192.168.43.66");
        addr.sin_port = htons(80);
        addr.sin_family = AF_INET;

        SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
        if (connect(Connection, (SOCKADDR*)& addr, sizeof(addr)) != 0) {
            return false;
        }

       send(Connection, (char*)&sended, sizeof(sended), NULL);
        recv(Connection, (char*)&res, sizeof(res), NULL);
        return res;

}
