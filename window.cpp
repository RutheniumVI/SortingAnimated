#include "window.h"
#include "sortingalgorithms.h"


Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(width + 200, height);
//    QGraphicsRectWidget *button1 = new QGraphicsRectWidget;
    GraphicsScene * scene = new GraphicsScene(50, 0, 0, width, height);
//    scene->setBackgroundBrush(Qt::black);
//    scene->addItem(button1);



    GraphicsView * window = new GraphicsView(scene, this);
    //window->setGeometry(0, 0, 300, 300);
    window->setFrameStyle(0);
    window->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    window->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    window->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    m_button = new QPushButton("Enter", this);
    m_button->setGeometry(width+10, 300, 80, 30);
    connect(m_button, SIGNAL (clicked(bool)), scene, SLOT (slotButtonClicked(bool)));


}
