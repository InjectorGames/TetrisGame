#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <Qt3DExtras>
#include <QCameraLens>
#include <QResizeEvent>

class GameWindow : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT

public:
    GameWindow(QScreen *screen = nullptr);
    ~GameWindow();

protected:
    Qt3DCore::QEntity* rootEntity;

    void setRootEntity(Qt3DCore::QEntity *root);
    Qt3DCore::QEntity* createBlockEntity();

    void resizeEvent(QResizeEvent* event) override;
};

#endif // GAME_WINDOW_H
