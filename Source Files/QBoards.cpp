#include "QBoards.h"

QBoards::QBoards(QWidget *parent)
    : QMainWindow(parent)
{   
    ui.setupUi(this);

    removeToolBar(ui.mainToolBar);

    QPainter painter(this);
    QBrush darkbrush(QColor("#0C0C0C"), Qt::SolidPattern);

    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);

    QMenuBar* menuBar = new QMenuBar(this);
    menuBar->setFont(font);
    setMenuBar(menuBar);
    
    QMenu* boardsMenu = menuBar->addMenu("&Boards");
    menuBar->addSeparator();
    QMenu* widgetsMenu = menuBar->addMenu("&Widgets");
    
    // New
    QAction* action = new QAction("&New", this);
    connect(action, &QAction::triggered, this, &QBoards::OnBoardNew);
    boardsMenu->addAction(action);

    boardsMenu->addSeparator();
    // Open
    action = new QAction("&Open", this);
    connect(action, &QAction::triggered, this, &QBoards::OnBoardOpen);
    boardsMenu->addAction(action);

    boardsMenu->addSeparator();
    // Save
    action = new QAction("&Save", this);
    connect(action, &QAction::triggered, this, &QBoards::OnBoardSave);
    boardsMenu->addAction(action);

    action = new QAction("&Text", this);
    connect(action, &QAction::triggered, this, &QBoards::OnWidgetsNew);
    widgetsMenu->addAction(action);

    QStatusBar* statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    
    QRect separator(0, menuBar->height(), menuBar->width(), 3);
    painter.fillRect(separator, darkbrush);

    update();
}

void QBoards::OnBoardNew()
{
    statusBar()->showMessage("File -> New");
}

void QBoards::OnBoardOpen()
{
    statusBar()->showMessage("File -> Open");
}

void QBoards::OnBoardSave()
{
    statusBar()->showMessage("File -> Save");
}

void QBoards::OnWidgetsNew() 
{
    QDockWidget* widget = new QDockWidget(this, Qt::CustomizeWindowHint);
    widget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    QTextEdit* textEdit = new QTextEdit(widget);
    widget->layout()->addWidget(textEdit);
    widget->setContentsMargins(1, 1, 1, 1);
    widget->move(100, 100);
    layout()->addWidget(widget);
    statusBar()->showMessage("Adding new text Widget");
}
