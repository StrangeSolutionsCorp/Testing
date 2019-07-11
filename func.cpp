#include "func.h"
#include <iostream>
#include "fstream"
#include <QApplication>

using namespace std;

bool Func(QString type, int cof, bool milk, int milkcon, bool choc, int choccon, bool sugar, int sugarcon, bool serv, int size){
    fstream file("result.txt", ios::in | ios::out | ios::app);
    int i = 1;
    if (serv == true) {
        file << "1) Обслуживание начато!\n2) Успешно!\n\n";
        file.close();
        return true;
    }

    if (type != "latte" && type != "kapuchino" && type != "espresso" && type != "makachino" && type != "cofe")
        type = "cofe";

    if (size > 3)
        size = 3;
    if (size < 1)
        size = 1;

    if (cof < 1)
        cof = 1;
    if (cof > 10)
        cof = 10;

    if (milk == true) {
        if (milkcon < 1)
            milkcon = 1;
        if (milkcon > 10)
            milkcon = 10;
    }

    if (choc == true) {
        if (choccon < 1)
            choccon = 1;
        if (choccon > 10)
            choccon = 10;
    }

    if (sugar == true) {
        if (sugarcon < 1)
            sugarcon = 1;
        if (sugarcon > 10)
            sugarcon = 10;
    }

    if (type == "latte") {
        file << i << ") Начато приготовление кофе.\n" << i+1 << ") Тип - Латте.\n";
        i += 2;

        if (size == 1)
            file << i << ") Размер - Маленький\n";
        if (size == 2)
            file << i << ") Размер - Средний\n";
        if (size == 3) {
            file << i << ") Столько нет.\n" << i + 1 << ") Программа завершила работу неккоректно!\n\n";
            file.close();
            return false;
        }

        i++;
        file << i << ") Крепкость - " << cof << "\n";

        i++;
        if (milk == true)
            file << i << ") Наличие молока - да, " << "кол-во молока - " << milkcon << "\n";
        else
            file << i << ") Наличие молока - нет\n";

        i++;
        if (sugar == true)
            file << i << ") Наличие сахара - да, " << "кол-во сахара - " << sugarcon << "\n";
        else
            file << i << ") Наличие сахара - нет\n";

        i++;
        file << i << ") Программа завершила работу корректно!\n\n";
        file.close();
        return true;
    }

    if (type == "kapuchino") {
        file << i << ") Начато приготовление кофе.\n" << i + 1 << ") Тип - Капучино.\n";

        i += 2;
        if (size == 1)
            file << i << ") Размер - Маленький\n";
        if (size == 2)
            file << i << ") Размер - Средний\n";
        if (size == 3) {
            file << i << ") Столько нет.\n" << i + 1 << ") Прорамма завершила работу неккоректно!\n\n";
            file.close();
            return false;
        }

        i++;
        file << i << ") Крепкость - " << cof << "\n";

        i++;
        if (milk == true) {
            file << i << ") Наличие молока - да, " << "кол-во молока - " << milkcon << "\n";
            if (milkcon == 10) {
                file << i + 1 << ") Молока нет.\n" << i + 2 << ") Программа завершила работу неккоректно!\n\n";
                file.close();
                return false;
            }
        }
        else
            file << i << ") Наличие молока - нет\n";

        i++;
        if (sugar == true)
            file << i << ") Наличие сахара - да, " << "кол-во сахара - " << sugarcon << "\n";
        else
            file << i << ") Наличие сахара - нет\n";

        i++;
        file << i << ") Программа завершила работу корректно!\n\n";
        return true;
    }

    if (type == "espresso") {
        file << i << ") Начато приготовление кофе.\n" << i + 1 << ") Тип - Эспрессо.\n";

        i += 2;
        if (size == 1)
            file << i << ") Размер - Маленький\n";
        if (size == 2)
            file << i << ") Размер - Средний\n";
        if (size == 3)
            file << i << ") Размер - Большой\n";

        i++;
        file << i << ") Крепкость - " << cof << "\n";
        if (cof == 10) {
            file << i << ") Нет зерен!\n" << i + 1 << ") Программа завершила работу неккоректно!\n\n";
            file.close();
            return false;
        }

        i++;
        if (sugar == true)
            file << i << ") Наличие сахара - да, " << "кол-во сахара - " << sugarcon << "\n";
        else
            file << i << ") Наличие сахара - нет\n";

        i++;
        file << i << ") Программа завершила работу корректно!\n\n";
        file.close();
        return true;
    }

    if (type == "makachino") {
        file << i << ") Начато приготовление кофе.\n" << i + 1 << ") Тип - Макаччино.\n";
        i += 2;

        if (size == 1)
            file << i << ") Размер - Маленький\n";
        if (size == 2)
            file << i << ") Размер - Средний\n";
        if (size == 3)
            file << i << ") Размер - Большой\n";

        i++;
        file << i << ") Крепкость - " << cof << "\n";

        i++;
        if (milk == true)
            file << i << ") Наличие молока - да, " << "кол-во молока - " << milkcon << "\n";
        else
            file << i << ") Наличие молока - нет\n";

        i++;
        if (sugar == true)
            file << i << ") Наличие сахара - да, "<< "кол-во сахара - " << sugarcon << "\n";
        else
            file << i << ") Наличие сахара - нет\n";

        i++;
        if (choc == true) {
            file << i << ") Наличие шоколада - да, " << "кол-во шоколада - " << choccon << "\n";
            file << i + 1 << ") Шоколада нет\n" << i + 2 << ") Программа завершила работу неккоректно!\n\n";
            file.close();
            return false;
        }
        else
            file << i << ") Наличие сахара - нет\n";

        i++;
        file << i << ") Программа завершила работу корректно!\n\n";
        file.close();
        return true;
    }

    if (type == "cofe") {
        file << i << ") Начато приготовление кофе.\n" << i + 1 << ") Тип - Просто кофе.\n";
        i += 2;

        if (size == 1)
            file << i << ") Размер - Маленький\n";
        if (size == 2)
            file << i << ") Размер - Средний\n";
        if (size == 3)
            file << i << ") Размер - Большой\n";

        i++;
        file << i << ") Крепкость - " << cof << "\n";

        i++;
        file << i << ") Программа завершила работу корректно!\n\n";
        file.close();
        return true;
    }
}
