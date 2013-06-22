#include "mouseEvent.h"
#include <QApplication>


int main( int argc, char* argv[] )
{
    QFont font("ZYSong18030",12);
    QApplication::setFont(font);
    	
    QApplication app( argc, argv );   
    
    mouseEvent *mouseevent = new mouseEvent();
    mouseevent->show();

    return app.exec();
}
