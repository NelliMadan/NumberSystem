#include "DigitalCore.h"



DigitalCore::DigitalCore(QObject *obj)
    :QObject(obj){}

void DigitalCore::setFromDecToBinary(const QString& number)
{
    int value = number.toInt();
    QString result;
    result = QString::number(value, 2);
    emit FromDecToBinaryFinish(result);
}

void DigitalCore::setFromDecToHex(const QString &number)
{
    int value = number.toInt();
    QString result;

    result = QString::number(value, 16);

    emit FromDecToHexFinish(result);
}

void DigitalCore::setFromHexToDec(const QString &number)
{
    QString result;
    bool ok;
    uint hex = number.toUInt(&ok, 16);
    result = QString::number(hex);


    emit FromHexToDecFinish(result);
}

void DigitalCore::setFromHexToBin(const QString &number)
{
    bool ok;
    QString result;
    int value = number.toInt(&ok, 16);
    result = QString::number(value, 2);


    emit FromHexToBinFinish(result);
}

void DigitalCore::setFromBinToDec(const QString &number)
{
    bool ok;
    QString result;
    int value = number.toInt(&ok, 2);
    result = QString::number(value);


    emit FromBinToDecFinish(result);
}

void DigitalCore::setFromBinToHex(const QString &number)
{
    bool ok;
    QString result;
    uint num = number.toInt(&ok, 16);
    result = QString::number(num, 2);


    emit FromBinToHexFinish(result);
}
