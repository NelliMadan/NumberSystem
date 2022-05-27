#ifndef NUMBERSYSTEMSH_H
#define NUMBERSYSTEMSH_H

#include <QWidget>
#include "DigitalCore.h"

class QLabel;
class QLineEdit;


class NumberSystem: public QWidget
{
    Q_OBJECT
public:
    NumberSystem(QWidget* pwgt = 0);
private:
    QLabel* m_declabel;
    QLabel* m_hexlabel;
    QLabel* m_binlabel;

    QLineEdit* m_decLineEdit;
    QLineEdit* m_hexLineEdit;
    QLineEdit* m_binLineEdit;

    DigitalCore* m_core;
private slots:
    void displayHexBinSlots(const QString& text);
    void displayDecBinSlots(const QString& text);
    void dsiplayDecHexSlots(const QString& text);


    void setBinaryLineSlot(const QString& result);
    void setHexLineSlot(const QString& result);
    void setDecLineSlot(const QString& result);
};




#endif
