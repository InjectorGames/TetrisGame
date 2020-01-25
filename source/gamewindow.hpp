#pragma once
#include <QTimer>
#include <Qt3DExtras>
#include <QCameraLens>
#include <QResizeEvent>
#include <QFrameAction>
#include <array2.hpp>

class GameWindow : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT

protected:
    Qt3DCore::QEntity* rootEntity;

public:
    GameWindow(QScreen *screen = nullptr) : Qt3DExtras::Qt3DWindow(screen), rootEntity(new Qt3DCore::QEntity())
    {
        setRootEntity(rootEntity);
        //format().setSwapInterval(0);

        auto actionFrame = new Qt3DLogic::QFrameAction(rootEntity);
        connect(actionFrame, SIGNAL(triggered(float)), this, SLOT(onFrameAction(float)));

        auto camera = Qt3DExtras::Qt3DWindow::camera();
        camera->setProjectionType(Qt3DRender::QCameraLens::ProjectionType::OrthographicProjection);
        camera->setPosition(QVector3D(0.0f, 10.0f, 0.0f));
        camera->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));
        camera->setNearPlane(0.1f);
        camera->setFarPlane(100.0f);
        camera->setLeft(-10);
        camera->setRight(10);
        camera->setBottom(-10);
        camera->setTop(10);

        auto background = new Qt3DCore::QEntity(rootEntity);
        auto planeMesh = new Qt3DExtras::QPlaneMesh;
        planeMesh->setWidth(20.0f);
        planeMesh->setHeight(20.0f);
        background->addComponent(planeMesh);
        auto transform = new Qt3DCore::QTransform;
        transform->setRotation(QQuaternion::fromEulerAngles(0.0f, -90.0f, 0.0f));
        background->addComponent(transform);
        auto texture = new Qt3DRender::QTextureLoader;
        texture->setSource(QUrl(QStringLiteral("qrc:/texture/background/classic/default")));
        auto material = new Qt3DExtras::QTextureMaterial(rootEntity);
        material->setTexture(texture);
        background->addComponent(material);

        auto block = createBlockEntity();
    }
    ~GameWindow()
    {
        delete rootEntity;
        rootEntity = nullptr;
    }

    enum BlockType
    {
        Blue,
    };

    Qt3DCore::QEntity* createBlockEntity()
    {
        auto entity = new Qt3DCore::QEntity(rootEntity);

        auto planeMesh = new Qt3DExtras::QPlaneMesh;
        planeMesh->setWidth(0.5f);
        planeMesh->setHeight(0.5f);
        entity->addComponent(planeMesh);

        auto transform = new Qt3DCore::QTransform;
        transform->setTranslation(QVector3D(0.0f, 1.0f, 0.0f));
        transform->setRotation(QQuaternion::fromEulerAngles(0.0f, -90.0f, 0.0f));
        entity->addComponent(transform);

        auto texture = new Qt3DRender::QTextureLoader;
        texture->setSource(QUrl(QStringLiteral("qrc:/texture/block/classic/blue")));
        auto material = new Qt3DExtras::QTextureMaterial(rootEntity);
        material->setTexture(texture);
        material->setAlphaBlendingEnabled(true);
        entity->addComponent(material);

        return entity;
    }

    Qt3DCore::QEntity* createFigureEntity(Array2<BlockType, 3, 3> figure)
    {
        auto entity = new Qt3DCore::QEntity(rootEntity);

        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                auto blockType = figure.getUnsafe(x, y);

                // TODO
                //switch () {

                //}
            }
        }
    }

public Q_SLOTS:
    void resizeEvent(QResizeEvent*  event) override
    {
        Qt3DExtras::Qt3DWindow::resizeEvent(event);

        auto size = event->size();
        auto camera = Qt3DExtras::Qt3DWindow::camera();
        auto aspectRatio = size.width() / float(size.height());

        // > and < controls window scale type
        if (size.width() < size.height())
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

    void onFrameAction(float deltaTime)
    {
        //camera()->rollAboutViewCenter(deltaTime * 100.0f);
    }
};
