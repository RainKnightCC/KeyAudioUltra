#include "MainForm.h"
#include <QApplication>
#include <QStyleFactory>

#include "MonitoreSafAPI.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
//    app.setStyle(QStyleFactory::create("Motif"));
    MainForm win;
    win.show();

    MonitoreSafAPI *eSafAPI = new MonitoreSafAPI();
    eSafAPI->getObjectList([&](bool success, QList<QPair<QString, QString>> monitor){
        if(success) {
            // do something
            printf("yes,it's success.\r\n");
        }
    });

//    eSafAPI->postObjectList([&](bool success, QList<QPair<QString, QString>> monitor) {
//        if(success) {
//            // do something
//            printf("yes,it's success.\r\n");
//        }
//    });

    return app.exec();
}
