/********************************************************************************
** Form generated from reading UI file 'navigationform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONFORM_H
#define UI_NAVIGATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationForm
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *NavigationForm)
    {
        if (NavigationForm->objectName().isEmpty())
            NavigationForm->setObjectName(QString::fromUtf8("NavigationForm"));
        NavigationForm->resize(1024, 600);
        pushButton = new QPushButton(NavigationForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 190, 251, 121));

        retranslateUi(NavigationForm);

        QMetaObject::connectSlotsByName(NavigationForm);
    } // setupUi

    void retranslateUi(QWidget *NavigationForm)
    {
        NavigationForm->setWindowTitle(QApplication::translate("NavigationForm", "Form", nullptr));
        pushButton->setText(QApplication::translate("NavigationForm", "navigation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NavigationForm: public Ui_NavigationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONFORM_H
