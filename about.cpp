#include "about.h"
#include "ui_about.h"
#include <QGraphicsPixmapItem>



About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);

    // Создаём сцену и отключаем скроллинг
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);

    // Загружаем и масштабируем картинку
    QPixmap pixmap(":/images/fufik_3.png");
    const qreal targetWidth = 380.0;
    qreal scale = targetWidth / pixmap.width();

    QGraphicsPixmapItem *imageItem = scene->addPixmap(pixmap);
    imageItem->setScale(scale);

    // Центрирование по горизонтали
    qreal viewWidth = ui->graphicsView->viewport()->width();
    qreal offsetX = (viewWidth - targetWidth) / 2;
    imageItem->setPos(offsetX > 0 ? offsetX : 0, 0);

    // Установка фиксированного размера сцены, чтобы не было "лишнего пространства"
    scene->setSceneRect(imageItem->boundingRect());
}


About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    this->close();

}
