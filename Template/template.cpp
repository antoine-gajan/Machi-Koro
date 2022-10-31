/// Définition des fonctions et/ou création d'un main pour le tester.

/// Classes utilisées
#include <QApplication>
#include <QPushButton>

/// Main
int main(int argc, char* argv[])
{
    QApplication app(argc, argv); // instance unique
    QPushButton hello("Hello world!"); // bouton avec texte
    hello.resize(100,30); // modification paramètre
    hello.show(); // affichage
    return app.exec(); // exécution de la boucle
}

// Signal : évènement envoyé par un objet cf .h
// Slot :  fonction réalisant l'action associée à un signal

QObject::connect();
// Arguments :
//     pointeur vers l'objet qui émet le signal
//     nom du signal que a envoyer
//     pointeur vers l'objet ayant le slot récepteur
//     nom du slot qui doit s'exécuter après le signal

// Fermer une fenêtre : slot(quit()) avec l'objet recepteur : l'application

// Widgets : https://fr.wikibooks.org/wiki/Programmation_Qt/Les_widgets