/********************************************************************************
** Form generated from reading UI file 'matrixtesterapp.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIXTESTERAPP_H
#define UI_MATRIXTESTERAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatrixTesterAppClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_1;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_15;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_10;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MatrixTesterAppClass)
    {
        if (MatrixTesterAppClass->objectName().isEmpty())
            MatrixTesterAppClass->setObjectName(QStringLiteral("MatrixTesterAppClass"));
        MatrixTesterAppClass->resize(252, 201);
        centralWidget = new QWidget(MatrixTesterAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 232, 100));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_1 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_1->setObjectName(QStringLiteral("doubleSpinBox_1"));

        gridLayout->addWidget(doubleSpinBox_1, 0, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));

        gridLayout->addWidget(doubleSpinBox_2, 0, 1, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));

        gridLayout->addWidget(doubleSpinBox_3, 0, 2, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));

        gridLayout->addWidget(doubleSpinBox_4, 0, 3, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));

        gridLayout->addWidget(doubleSpinBox_7, 1, 0, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));

        gridLayout->addWidget(doubleSpinBox_8, 1, 1, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));

        gridLayout->addWidget(doubleSpinBox_5, 1, 2, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));

        gridLayout->addWidget(doubleSpinBox_6, 1, 3, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));

        gridLayout->addWidget(doubleSpinBox_11, 2, 0, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));

        gridLayout->addWidget(doubleSpinBox_12, 2, 1, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));

        gridLayout->addWidget(doubleSpinBox_9, 2, 2, 1, 1);

        doubleSpinBox_15 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_15->setObjectName(QStringLiteral("doubleSpinBox_15"));

        gridLayout->addWidget(doubleSpinBox_15, 3, 0, 1, 1);

        doubleSpinBox_16 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_16->setObjectName(QStringLiteral("doubleSpinBox_16"));

        gridLayout->addWidget(doubleSpinBox_16, 3, 1, 1, 1);

        doubleSpinBox_13 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));

        gridLayout->addWidget(doubleSpinBox_13, 3, 2, 1, 1);

        doubleSpinBox_14 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));

        gridLayout->addWidget(doubleSpinBox_14, 3, 3, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));

        gridLayout->addWidget(doubleSpinBox_10, 2, 3, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 120, 231, 23));
        MatrixTesterAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MatrixTesterAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 252, 21));
        MatrixTesterAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MatrixTesterAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MatrixTesterAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MatrixTesterAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MatrixTesterAppClass->setStatusBar(statusBar);

        retranslateUi(MatrixTesterAppClass);

        QMetaObject::connectSlotsByName(MatrixTesterAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *MatrixTesterAppClass)
    {
        MatrixTesterAppClass->setWindowTitle(QApplication::translate("MatrixTesterAppClass", "MatrixTesterApp", 0));
        pushButton->setText(QApplication::translate("MatrixTesterAppClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MatrixTesterAppClass: public Ui_MatrixTesterAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIXTESTERAPP_H
