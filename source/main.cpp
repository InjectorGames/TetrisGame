#include <QApplication>
#include <gamewindow.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWindow view;
    view.show();

    return a.exec();
}
