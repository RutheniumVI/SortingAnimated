#include <QtCore>
#include <QtWidgets>
#include "window.h"
#include <iostream>

//class QGraphicsRectWidget : public QGraphicsWidget
//{
//public:
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
//               QWidget *) override
//    {
//        painter->fillRect(rect(), Qt::blue);
//    }
//};
////![13]

//class GraphicsView : public QGraphicsView
//{
//    Q_OBJECT
//public:
//    GraphicsView(QGraphicsScene *scene, QWidget *parent = NULL) : QGraphicsView(scene, parent)
//    {
//    }

//protected:
//    void resizeEvent(QResizeEvent *event) override
//    {
//        fitInView(scene()->sceneRect());
//        QGraphicsView::resizeEvent(event);
//    }
//private slots:
//    void slotButtonClicked(bool checked){

//    }
//};

int main(int argc, char ** argv){
    QApplication app(argc, argv);

//    QGraphicsRectWidget *button1 = new QGraphicsRectWidget;
//    QGraphicsScene scene(0, 0, 300, 300);
//    scene.setBackgroundBrush(Qt::black);
//    scene.addItem(button1);



//    GraphicsView window(&scene);
//    window.setFrameStyle(0);
//    window.setAlignment(Qt::AlignLeft | Qt::AlignTop);
//    window.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    window.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    window.resize(300, 400);

//    QPushButton *m_button = new QPushButton("press", &window);
//    m_button->setGeometry(10, 300, 80, 30);
//    window.show();
    Window window;
    window.show();
    return app.exec();
}

