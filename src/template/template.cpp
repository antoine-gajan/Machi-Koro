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
// Exemple complet : QObject::connect(&bouton,SIGNAL(clicked()),&app,SLOT(quit()));

// Widgets : https://fr.wikibooks.org/wiki/Programmation_Qt/Les_widgets

// créer un objet : deux possibilités, objets ou pointeurs :
QBlablabla *mon_blabla = new QBlablabla();
QBlabla mon_blablabla;


//Positionnement des widgets


// Positionnement absolu
monWidget->move(50, 70); //déplace le widget à l’abscisse (x) 50 et l'ordonnée (y) 70. Les attributs sont exprimées en pixels.
monWidget->setSize(24, 89); //redimensionne le widget de 24 pixels de largeur et de 89 pixels de hauteur.
monWidget->setGeometry(50, 70, 24, 89); //déplace le widget à l'abscisse 50 et à l'ordonnée 70 tout en lui donnant une largeur de 24 et une hauteur de 89.


//Positionnement relatif

// Layout horizontal
QWidget *maPage = new QWidget(); /* Création de la page qui contiendra le layout, un QWidget est une fenêtre */

// On peut donner tout un tas de propriétés à la fenêtre :
maPage->setFixedSize(500, 500);
maPage->setWindowTitle("mon titre");

/* Création des boutons */
QPushButton *bouton1 = new QPushButton("Wiki");
QPushButton *bouton2 = new QPushButton("Books");

/* layout :
+ QHBoxLayout : comme une div ou les éléments seront entassés horizontalement
+ QVBoxLayout : idem mais verticalement
QGridLayout : Positionnement en grille

Voir images dans ce dossier qui montrent des exemples
*/
QHBoxLayout *monLayout = new QHBoxLayout(); /* Création du layout */
/* Ajout des widgets dans le layout */
monLayout->addWidget(bouton1);
monLayout->addWidget(bouton2);

maPage->setLayout(monLayout); /* Le layout appartient désormais à l'objet maPage */


// Layout en  grille
QPushButton *wi = new QPushButton("Wi"); /* Création des boutons */
QPushButton *ki = new QPushButton("ki");
QPushButton *books = new QPushButton("books");

/* Introduction des boutons dans le layout */
QGridLayout *m_layout = new QGridLayout();
m_layout->addWidget(wi, 0, 0); /* En haut à gauche */
m_layout->addWidget(ki, 1, 0); /* En haut à droite */
m_layout->addWidget(books, 1, 1, 1, 2); /* En bas */

// possibilité que le widget occupe plusieurs colonnes/lignes, par défaut une seule.
// dans ce cas, les coordonnées correspondent au début du widget
m_layout->addWidget(widget, pos_x, pos_y, row_pan, columnspan);

// Création d'un formulaire avec QFormLayout -> utile pour définir le début de partie machi koro
/* Création des widgets */
QLineEdit *nom = new QLineEdit();
QLineEdit *langageProg = new QLineEdit();

/* Création et introduction dans le layout */
QFormLayout *monLayout = new QFormLayout();
monLayout->addRow("Votre nom : ", nom);
monLayout->addRow("Votre langage de programmation préféré : " langageProg);

/* Création et introduction dans la page **/
QWidget *maPage = new QWidget();
maPage->setLayout(monLayout);

/* Introduction du layout dans la page */
QWidget *m_page = new QWidget();
m_page->setLayout(m_layout);

// combiner des layouts, pour ajouter un bouton quitter à un formulaire par ex
QLineEdit *nom = new QLineEdit();
QLineEdit *prenom = new QLineEdit();

QFormLayout *layoutFormulaire = new QFormLayout();
layoutFormulaire->addRow("Votre nom : ", nom);
layoutFormulaire->addRow("Votr prénom : ", prenom);

QPushButton *boutonQuitter = new QPushButton("Quitter");

QVBoxLayout *layoutPrincipal = new QVBoxLayout();
layoutPrincipal->addLayout(layoutFormulaire); /* Utilisation de la méthode addLayout() */
layoutPrincipal->addWidget(boutonQuitter);

QWidget *maPage = new QWidget();
maPage->setLayout(layoutPrincipal);


// Les différents Widget

/*
QLabel : afficher un texte ou une image
QProgressBar : une barre de progression
QLCDNumber : un label pour nombre
QTableWidget : un tableau
QListWidget : une liste
*/

// Les différents boutons

/*
QPushButton : un bouton classique
QCheckBox : une case à cocher
QRadioButton : un bouton radio


ex :

QGroupBox *qgroupbox = new QGroupBox("Votre language de programmation préféré :");  Création du QGroupBox
QRadioButton *cPlusPlus = new QRadioButton("C++"); /* Création de l'option C++ ...
QRadioButton *python = new QRadioButton("Python"); /*..., de l'option Python ...
QRadioButton *php = new QRadioButton("PHP"); /*..., et de l'option PHP

QVBoxLayout *layout = new QVBoxLayout(); /* Création du layout
layout->addWidget(cPlusPlus);/* Ajout des QRadioButton
layout->addWidget(python);
layout->addWidget(php);

qgroupbox->setLayout(layout); /* Définition du layout pour l'objet QGroupBox


QLineEdit : un champ de texte à une ligne
QTextEdit : un champ de texte multi-ligne
QSpinBox : un champ de nombres
QDoubleSpinBox : un champ de nombres non-entiers
QSlider : un curseur
QDial : un curseur en forme de cercle
QComboBox : une liste déroulante
QDateEdit : un champ pour date
QTimeEdit : un champ pour temps
QDateTimeEdit : un champ qui combine date et temps
QCalendarWidget : un calendrier





QFrame : une bordure
QGroupBox : un conteneur pour une catégorie de widgets
QTabWidget : un conteneur à onglets

*/

