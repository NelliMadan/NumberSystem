#ifndef CORENUMBERSYSTEM_H
#define CORENUMBERSYSTEM_H

#include<QObject>


class DigitalCore: public QObject
{
    Q_OBJECT

public:
    DigitalCore(QObject* obj = nullptr);
    void setFromDecToBinary(const QString& number = "");
    void setFromDecToHex(const QString& number = "");
    void setFromHexToDec(const QString& number = "");
    void setFromHexToBin(const QString& number = "");
    void setFromBinToDec(const QString& number = "");
    void setFromBinToHex(const QString& number = "");
signals:
    void FromDecToBinaryFinish(const QString& = "");
    void FromDecToHexFinish(const QString& = "");
    void FromHexToDecFinish(const QString& = "");
    void FromHexToBinFinish(const QString& = "");
    void FromBinToDecFinish(const QString& = "");
    void FromBinToHexFinish(const QString& = "");
};

#endif
