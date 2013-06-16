#include<QApplication>
#include<QGraphicsScene>
#include<QGraphicsView>
#include"butterfly.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	// <1>.creat "Scene" ---GraphicsScene
	QGraphicsScene* scene = new QGraphicsScene();
	scene->setSceneRect( QRectF(-200,-200,400,400) );
    
	// <2>.create "butterfly" here
	butterfly* Butterfly = new butterfly();
	Butterfly->setPos(-100,0);
	scene->addItem(Butterfly);//add item to the "Scene"

	// <3>.create "View" ---GraphicView
	// "QGraphicsView" provides a widget displaying
	// the contents of a QGraphicsScene
	QGraphicsView* view = new QGraphicsView();
	view->setScene(scene);
	view->setMinimumSize(400,400);
	view->show();

	return app.exec();
}
