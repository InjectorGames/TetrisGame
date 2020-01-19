#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <QTimer>
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
    QTimer* updateTimer;
    Qt3DCore::QEntity* rootEntity;

    void onUpdate();
    Qt3DCore::QEntity* createBlockEntity();

    void setRootEntity(Qt3DCore::QEntity *root);
    void resizeEvent(QResizeEvent* event) override;
    bool event(QEvent *event) override;
};

#endif // GAME_WINDOW_H
