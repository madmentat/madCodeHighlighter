#include "about.h"
#include "ui_about.h"
#include <QGraphicsPixmapItem>

About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);

    // Создаём сцену
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Настраиваем QGraphicsView
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    // Убираем рамку и фон QGraphicsView
    ui->graphicsView->setStyleSheet("QGraphicsView { border: none; background: transparent; }");

    // Загружаем изображение
    QPixmap pixmap(":/images/fufik_3.png");
    if (pixmap.isNull()) {
        qDebug() << "Ошибка: Не удалось загрузить изображение fufik_3.png";
        return;
    }

    // Масштабируем изображение с учётом DPI
    const qreal targetWidth = 380.0;
    qreal devicePixelRatio = qApp->devicePixelRatio();
    QPixmap scaledPixmap = pixmap.scaledToWidth(targetWidth * devicePixelRatio, Qt::SmoothTransformation);
    scaledPixmap.setDevicePixelRatio(devicePixelRatio);
    QGraphicsPixmapItem *imageItem = scene->addPixmap(scaledPixmap);

    // Центрирование по горизонтали
    qreal viewWidth = ui->graphicsView->viewport()->width();
    qreal offsetX = (viewWidth - targetWidth) / 2.0;
    imageItem->setPos(offsetX > 0 ? offsetX : 0, 0);

    // Проверка размера QGraphicsView
    qreal viewHeight = ui->graphicsView->viewport()->height();
    if (viewWidth < targetWidth || viewHeight < scaledPixmap.height() / devicePixelRatio) {
        qDebug() << "Предупреждение: Размер QGraphicsView (" << viewWidth << "x" << viewHeight
                 << ") меньше размера изображения (" << targetWidth << "x" << scaledPixmap.height() / devicePixelRatio << ")";
    }

    // Устанавливаем сцену с учётом размеров изображения
    scene->setSceneRect(0, 0, targetWidth, scaledPixmap.height() / devicePixelRatio);
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    this->close();
}
