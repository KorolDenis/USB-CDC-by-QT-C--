/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *OpenFile;
    QPushButton *Save;
    QPushButton *Programm;
    QPushButton *Read;
    QPushButton *Erase;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QTextEdit *Logs;
    QPushButton *ClearLogs;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QComboBox *ComPortList;
    QPushButton *COM_Connect;
    QPushButton *UpdateCOM;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(889, 560);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(889, 560));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 671, 311));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(710, 20, 141, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        OpenFile = new QPushButton(layoutWidget);
        OpenFile->setObjectName(QString::fromUtf8("OpenFile"));

        verticalLayout->addWidget(OpenFile);

        Save = new QPushButton(layoutWidget);
        Save->setObjectName(QString::fromUtf8("Save"));

        verticalLayout->addWidget(Save);

        Programm = new QPushButton(layoutWidget);
        Programm->setObjectName(QString::fromUtf8("Programm"));

        verticalLayout->addWidget(Programm);

        Read = new QPushButton(layoutWidget);
        Read->setObjectName(QString::fromUtf8("Read"));

        verticalLayout->addWidget(Read);

        Erase = new QPushButton(layoutWidget);
        Erase->setObjectName(QString::fromUtf8("Erase"));

        verticalLayout->addWidget(Erase);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 342, 33, 16));
        Logs = new QTextEdit(centralwidget);
        Logs->setObjectName(QString::fromUtf8("Logs"));
        Logs->setGeometry(QRect(12, 365, 675, 147));
        Logs->setReadOnly(true);
        ClearLogs = new QPushButton(centralwidget);
        ClearLogs->setObjectName(QString::fromUtf8("ClearLogs"));
        ClearLogs->setGeometry(QRect(10, 520, 93, 28));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(710, 340, 141, 201));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ComPortList = new QComboBox(layoutWidget1);
        ComPortList->addItem(QString());
        ComPortList->setObjectName(QString::fromUtf8("ComPortList"));

        verticalLayout_2->addWidget(ComPortList);

        COM_Connect = new QPushButton(layoutWidget1);
        COM_Connect->setObjectName(QString::fromUtf8("COM_Connect"));

        verticalLayout_2->addWidget(COM_Connect);

        UpdateCOM = new QPushButton(layoutWidget1);
        UpdateCOM->setObjectName(QString::fromUtf8("UpdateCOM"));

        verticalLayout_2->addWidget(UpdateCOM);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "USB CDC \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "0x00000000", nullptr));
        OpenFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        Save->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        Programm->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        Read->setText(QCoreApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        Erase->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\265\321\200\320\265\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270:", nullptr));
        ClearLogs->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        ComPortList->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\321\203\321\201\321\202\320\276", nullptr));

        COM_Connect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        UpdateCOM->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
