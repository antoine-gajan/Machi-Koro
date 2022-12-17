#include <iostream>
using namespace std;

#include <QApplication>
#include <QPushButton>


int main(int argc, char * argv[]) {

    QApplication app(argc, argv);

    QPushButton bouton("Jouer");
    bouton.show();

    return app.exec();
}