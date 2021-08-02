#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QBoards.h"

class QBoards : public QMainWindow
{
    Q_OBJECT

public:
    QBoards(QWidget *parent = Q_NULLPTR);

private:
    Ui::QBoardsClass ui;

private slots:
    void OnFileNew();
    void OnFileOpen();
    void OnFileSave();
};
