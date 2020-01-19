#include "game_window.h"

Qt3DCore::QEntity* GameWindow::createBlockEntity()
{
    auto entity = new Qt3DCore::QEntity(rootEntity);

    auto planeMesh = new Qt3DExtras::QPlaneMesh;
    planeMesh->setWidth(1.0f);
    planeMesh->setHeight(1.0f);
    entity->addComponent(planeMesh);

    auto transform = new Qt3DCore::QTransform;
    transform->setRotation(QQuaternion::fromEulerAngles(180.0f, 90.0f, 90.0f));
    entity->addComponent(transform);

    auto texture = new Qt3DRender::QTextureLoader;
    texture->setSource(QUrl(QStringLiteral("qrc:/sprite/block/classic/blue")));
    auto material = new Qt3DExtras::QTextureMaterial(rootEntity);
    material->setTexture(texture);
    material->setAlphaBlendingEnabled(true);
    entity->addComponent(material);

    return entity;
}

GameWindow::GameWindow(QScreen *screen) : Qt3DExtras::Qt3DWindow(screen), rootEntity(new Qt3DCore::QEntity())
{
    setRootEntity(rootEntity);
    format().setSwapInterval(0);

    auto actionFrame = new Qt3DLogic::QFrameAction(rootEntity);
    connect(actionFrame, SIGNAL(triggered(float)), this, SLOT(onUpdate(float)));

    auto camera = Qt3DExtras::Qt3DWindow::camera();
    camera->setProjectionType(Qt3DRender::QCameraLens::ProjectionType::OrthographicProjection);
    camera->setPosition(QVector3D(0.0f, 0.0f, 10.0f));
    camera->setNearPlane(0.1f);
    camera->setFarPlane(100.0f);
    camera->setLeft(-10);
    camera->setRight(10);
    camera->setBottom(-10);
    camera->setTop(10);


    auto block = createBlockEntity();
}

GameWindow::~GameWindow()
{
    delete rootEntity;
    rootEntity = nullptr;
}

void GameWindow::resizeEvent(QResizeEvent*  event)
{
    Qt3DExtras::Qt3DWindow::resizeEvent(event);

    auto size = event->size();
    auto camera = Qt3DExtras::Qt3DWindow::camera();
    auto aspectRatio = size.width() / float(size.height());

    if (size.width() > size.height())
    {
        camera->setLeft(-10.0f * aspectRatio);
        camera->setRight(10.0f * aspectRatio);
        camera->setBottom(-10.0f);
        camera->setTop(10.0f);
    }
    else
    {
        camera->setLeft(-10.0f);
        camera->setRight(10.0f);
        camera->setBottom(-10.0f / aspectRatio);
        camera->setTop(10.0f / aspectRatio);
    }
}

void GameWindow::onUpdate(float dt)
{
    camera()->rollAboutViewCenter(dt * 100.0f);
}
