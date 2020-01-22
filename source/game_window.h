#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QTimer>
#include <Qt3DExtras>
#include <QCameraLens>
#include <QResizeEvent>
#include <QFrameAction>

class GameWindow : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT

public:
    GameWindow(QScreen *screen = nullptr);
    ~GameWindow();

protected:
    Qt3DCore::QEntity* rootEntity;
    Qt3DCore::QEntity* createBlockEntity();

public Q_SLOTS:
    void resizeEvent(QResizeEvent* event) override;
    void onUpdate(float dt);
};

#endif // GAME_WINDOW_H
