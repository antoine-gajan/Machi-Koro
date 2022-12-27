#include "Gare.h"
#include "Partie.h"
#include <QRadioButton>

Gare::Gare()
    : Monument(AVANT,
               "Gare",
               4,
               "Vous pouvez lancer 2 des",
               "../assets/monuments/Gare-travaux.png") {
    /// Constructeur de Gare
}

void Gare::declencher_effet(unsigned int possesseur, int bonus) const {
    Joueur *joueur = Partie::get_instance()->get_tab_joueurs()[possesseur];
    Partie *partie = Partie::get_instance();
    if (joueur->get_est_ia()) {
        int choix = rand() % 4;
        if (choix != 0) {
            cout << "Activation de l'effet de la gare du joueur \"" << joueur->get_nom() << "\"" << endl;
            partie->set_de_2(Partie::lancer_de());
        }
    }
    else {

            //Création d'une boite de dialogue afin de savoit si le joueur veut lancer deux dés ou non
            QDialog *window = new QDialog();
            window->setWindowTitle("Machi Koro - Jouer deux dés");
            window->setContentsMargins(50, 30, 50, 50);
            // Création d'un formulaire
            auto *formLayout = new QFormLayout;
            QLabel* label = new QLabel("Voulez-vous lancer deux dés?");
            formLayout->addRow(label);
            auto *ouiRadioButton = new QRadioButton("Oui");
            formLayout->addRow(ouiRadioButton);
            auto *nonRadioButton = new QRadioButton("Oui");
            formLayout->addRow(nonRadioButton);
            auto *validateButton = new QPushButton("Valider");
            formLayout->addRow(validateButton);

            // Connection entre boutons et slots
            QObject::connect(validateButton, &QPushButton::clicked, [partie, window, ouiRadioButton,nonRadioButton]() {
                window->accept();
                // Cas où le joueur veut lancer deux dés
                if (ouiRadioButton->isChecked()){
                    partie->get_vue_partie()->lancer_de_2_display();

                }
                    // Sinon on ne fait rien

            });
            // Execution de la boite de dialogue et attente d'une réponse
            window->setLayout(formLayout);
            window->exec();

        }
}

void Gare::activer() {
    set_image("../assets/monuments/Gare-active.png");
}

void Gare::desactiver() {
    set_image("../assets/monuments/Gare-travaux.png");
}