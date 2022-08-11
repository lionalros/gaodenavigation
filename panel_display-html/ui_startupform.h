/********************************************************************************
** Form generated from reading UI file 'startupform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPFORM_H
#define UI_STARTUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startupForm
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *startupForm)
    {
        if (startupForm->objectName().isEmpty())
            startupForm->setObjectName(QString::fromUtf8("startupForm"));
        startupForm->resize(1024, 600);
        pushButton = new QPushButton(startupForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 140, 251, 111));

        retranslateUi(startupForm);

        QMetaObject::connectSlotsByName(startupForm);
    } // setupUi

    void retranslateUi(QWidget *startupForm)
    {
        startupForm->setWindowTitle(QApplication::translate("startupForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("startupForm", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startupForm: public Ui_startupForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPFORM_H
