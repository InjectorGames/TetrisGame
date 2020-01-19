#include <QApplication>
#include "game_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWindow view;
    //window.setRootEntity(createScene());
    view.show();

    // Camera
    //Qt3DRender::QCamera *camera = view.camera();
    //camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    //camera->setPosition(QVector3D(0, 0, 40.0f));
    //camera->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
    //Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
    //camController->setLinearSpeed( 50.0f );
    //camController->setLookSpeed( 180.0f );
    //camController->setCamera(camera);

    return a.exec();
}
