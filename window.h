#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QPushButton>
#include <QtCore>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "sortingalgorithms.h"



class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
private:
    QPushButton *m_button;
    const int width = 500, height = 600;
signals:

};

class QGraphicsRectWidget : public QGraphicsWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ getColor WRITE setColor)
private:
    QColor color = Qt::blue;
    int val;
public:
    QGraphicsRectWidget(int value) : QGraphicsWidget(){
        val = value;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *) override
    {
        painter->setPen(QPen(Qt::white, 1));
        painter->fillRect(rect(), color);
        painter->drawRect(rect());

    }
    QColor getColor(){
        return color;
    }
    void setColor(QColor c){
        color = c;
    }
    int value(){
        return val;
    }
    bool operator < (QGraphicsRectWidget &b){
        return val < b.value();
    }

};

class GraphicsScene : public QGraphicsScene, SortingAlgorithms<QGraphicsRectWidget> {
    Q_OBJECT
public:
    GraphicsScene(int num, qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr) : QGraphicsScene(x, y, width, height, parent){
        std::vector<int> temp_val(num);
        for(int i=0;i<num;i++){temp_val[i]=i;}
        std::random_shuffle(temp_val.begin(), temp_val.end(), randomizer);

        for(int i=0; i<num; i++){
            rec_width = width/recToWindowWidthRatio;
            QGraphicsRectWidget * rec = new QGraphicsRectWidget(temp_val[i]);
            rec->setGeometry(i*rec_width, height-((temp_val[i]+1)*rec_height_multiplier), rec_width,(temp_val[i]+1)*rec_height_multiplier);
            setBackgroundBrush(Qt::black);
            addItem(rec);
            rectangles.push_back(rec);
        }

        animationQueue = new QSequentialAnimationGroup;

    }
    ~GraphicsScene(){
        delete(animationGrp);
    }
private:
    static int randomizer (int i) { return std::rand()%i;}

    std::vector<QGraphicsRectWidget*> rectangles;
    const int recToWindowWidthRatio = 50;//the ratio between the width of the rectangle vs the width of the window
    int rec_width, rec_height_multiplier = 10;

    QSequentialAnimationGroup * animationQueue;
    QParallelAnimationGroup * animationGrp;
    QPropertyAnimation * anim1, * anim2;
    QPropertyAnimation * colorAnim1, * colorAnim2;
    int animationSpeed = 1;

private:
    void swap(QGraphicsRectWidget* &a, QGraphicsRectWidget* &b) {
        QGraphicsRectWidget* temp = a;
        a = b;
        b = temp;
        animateSwap(a, b);
    }
private slots:
    void slotButtonClicked(bool checked){
        SortingAlgorithms<QGraphicsRectWidget*>::SelectionSort2(rectangles);
        animationQueue->start();
    }
public:
    void animateSwap(QGraphicsRectWidget* a, QGraphicsRectWidget* b){
        animationGrp = new QParallelAnimationGroup(animationQueue);

        anim1 = new QPropertyAnimation();
        anim2 = new QPropertyAnimation();

        anim1->setPropertyName("geometry");
        anim2->setPropertyName("geometry");

        colorAnim1 = new QPropertyAnimation;
        colorAnim2 = new QPropertyAnimation;
        colorAnim1->setPropertyName("color");
        colorAnim2->setPropertyName("color");

        animationGrp->addAnimation(anim1);
        animationGrp->addAnimation(anim2);

        animationGrp->addAnimation(colorAnim1);
        animationGrp->addAnimation(colorAnim2);

        a->setZValue((*a < *b) ? 0:1);
        b->setZValue((*a < *b) ? 1:0);

        anim1->setDuration(1000);
        anim1->setTargetObject(a);
        anim1->setStartValue(QRect(a->geometry().x(),
                             a->geometry().y(), a->geometry().width(), a->geometry().height()));
        anim1->setEndValue(QRect(b->geometry().x(),
                           a->geometry().y(), a->geometry().width(), a->geometry().height()));

        anim2->setDuration(1000);
        anim2->setTargetObject(b);
        anim2->setStartValue(QRect(b->geometry().x(),
                             b->geometry().y(), b->geometry().width(), b->geometry().height()));
        anim2->setEndValue(QRect(a->geometry().x(),
                           b->geometry().y(), b->geometry().width(), b->geometry().height()));


        colorAnim1->setDuration(1000);
        colorAnim1->setTargetObject((*a < *b) ? a:b);
        colorAnim1->setStartValue(QColor(Qt::red));
        colorAnim1->setEndValue(QColor(Qt::blue));



        colorAnim2->setDuration(1000);
        colorAnim2->setTargetObject((*a < *b) ? b:a);
        colorAnim2->setStartValue(QColor(Qt::green));
        colorAnim2->setEndValue(QColor(Qt::blue));

        animationQueue->addAnimation(animationGrp);

    }
};

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QGraphicsScene *scene, QWidget *parent = NULL) : QGraphicsView(scene, parent)
    {
    }


protected:
    void resizeEvent(QResizeEvent *event) override
    {
        fitInView(scene()->sceneRect());
        QGraphicsView::resizeEvent(event);
    }
private slots:

};

#endif // WINDOW_H
