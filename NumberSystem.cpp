#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include "NumberSystem.h"


NumberSystem::NumberSystem(QWidget* pwgt)
    :QWidget(pwgt)
{
    setFixedSize(700, 300);
    setWindowTitle("NumberSystems");
    setStyleSheet("background: #f1ece9");

    QGridLayout* gridLayout = new QGridLayout(this);

    m_declabel = new QLabel("Decimal", this);
    m_hexlabel = new QLabel("Hexadecimal", this);
    m_binlabel = new QLabel("Binary", this);

    m_declabel->setStyleSheet("font: 18px");
    m_hexlabel->setStyleSheet("font: 18px");
    m_binlabel->setStyleSheet("font: 18px");

    m_decLineEdit = new QLineEdit(this);
    m_hexLineEdit = new QLineEdit(this);
    m_binLineEdit = new QLineEdit(this);


    m_decLineEdit->setFixedHeight(30);
    m_hexLineEdit->setFixedHeight(30);
    m_binLineEdit->setFixedHeight(30);


    QFont font = m_decLineEdit->font();
    font.setPointSize(18);

    m_decLineEdit->setFont(font);
    m_hexLineEdit->setFont(font);
    m_binLineEdit->setFont(font);

    m_core = new DigitalCore(this);

    connect(m_decLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(displayHexBinSlots(const QString&)));
    connect(m_core, SIGNAL(FromDecToBinaryFinish(const QString&)), this, SLOT(setBinaryLineSlot(const QString&)));
    connect(m_core, SIGNAL(FromDecToHexFinish(const QString&)), this, SLOT(setHexLineSlot(const QString&)));

    connect(m_hexLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(displayDecBinSlots(const QString&)));
    connect(m_core, SIGNAL(FromHexToDecFinish(const QString&)), this, SLOT(setDecLineSlot(const QString&)));
    connect(m_core, SIGNAL(FromHexToBinFinish(const QString&)), this, SLOT(setBinaryLineSlot(const QString&)));

    connect(m_binLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(dsiplayDecHexSlots(const QString&)));
    connect(m_core, SIGNAL(FromBinToDecFinish(const QString&)), this, SLOT(setDecLineSlot(const QString&)));
    connect(m_core, SIGNAL(FromBinToHexFinish(const QString&)), this , SLOT(setHexLineSlot(const QString&)));

    gridLayout->addWidget(m_declabel);
    gridLayout->addWidget(m_hexlabel);
    gridLayout->addWidget(m_binlabel);

    gridLayout->addWidget(m_decLineEdit, 0, 2, 1, 5);
    gridLayout->addWidget(m_hexLineEdit, 1, 2, 1, 5);
    gridLayout->addWidget(m_binLineEdit, 2, 2, 1, 5);

    this->setLayout(gridLayout);
}

void NumberSystem::displayHexBinSlots(const QString& text)
{
    m_core->setFromDecToBinary(text);
    m_core->setFromDecToHex(text);
}

void NumberSystem::displayDecBinSlots(const QString &text)
{
    m_core->setFromHexToDec(text);
    m_core->setFromHexToBin(text);
}

void NumberSystem::dsiplayDecHexSlots(const QString &text)
{
    m_core->setFromBinToDec(text);
}

void NumberSystem::setBinaryLineSlot(const QString& result)
{
    m_binLineEdit->setText(result);
}

void NumberSystem::setHexLineSlot(const QString& result)
{
    m_hexLineEdit->setText(result);
}

void NumberSystem::setDecLineSlot(const QString &result)
{
    m_decLineEdit->setText(result);
}
