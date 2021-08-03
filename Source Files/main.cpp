#include "QBoards.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QBoards w;
    QFile styleSheetF("StyleSheet.qss");
    styleSheetF.open(QFile::ReadOnly);
    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);
    qApp->setStyleSheet(styleSheetF.readAll());
    qApp->setFont(font);
    w.show();
    return a.exec();
}
