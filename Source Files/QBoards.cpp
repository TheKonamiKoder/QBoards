#include "QBoards.h"

QBoards::QBoards(QWidget *parent)
    : QMainWindow(parent)
{   

    ui.setupUi(this);

    QMenuBar* menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
    
    QMenu* fileMenu = menuBar->addMenu("&File");
    menuBar->addSeparator();
    QMenu* widgetsMenu = menuBar->addMenu("&Widgets");
    
    // New
    QAction* action = new QAction("&New", this);
    connect(action, &QAction::triggered, this, &QBoards::OnFileNew);
    fileMenu->addAction(action);
    // Open
    action = new QAction("&Open", this);
    connect(action, &QAction::triggered, this, &QBoards::OnFileOpen);
    fileMenu->addAction(action);
    // Save
    action = new QAction("&Save", this);
    connect(action, &QAction::triggered, this, &QBoards::OnFileSave);
    fileMenu->addAction(action);

    QStatusBar* statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
}

void QBoards::OnFileNew()
{
    statusBar()->showMessage("File -> New");
}

void QBoards::OnFileOpen()
{
    statusBar()->showMessage("File -> Open");
}

void QBoards::OnFileSave()
{
    statusBar()->showMessage("File -> Save");
}
