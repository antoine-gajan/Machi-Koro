#ifndef MACHI_KORO_VUECARTE_H
#define MACHI_KORO_VUECARTE_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include "Carte.h"
#include <iostream>

class VueCarte : public QPushButton
{
Q_OBJECT
public:
    VueCarte(const Carte& c,bool etat, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void setCarte(const Carte& c) { setCheckable(true); setChecked(false); carte=&c; update(); }
    const Carte* getCarte() const { return carte; }
    bool cartePresente() const { return carte!=nullptr; }
    string get_path_carte() const{return path_carte;};
    QPixmap get_pixmap() const{return pixmap;}
    QIcon get_icon() const{return ButtonIcon;}
    void set_pixmap(string path){pixmap = QPixmap(QString::fromStdString(path));};
    void set_icon(QPixmap pixmap){ButtonIcon = QIcon(pixmap);};
    void peinture(QPaintEvent* event);
    //
    void paintEvent(QPaintEvent *event) override;
private:
    const Carte* carte = nullptr;
    QPixmap pixmap;
    QIcon ButtonIcon;
    string path_carte;

};


#endif //MACHI_KORO_VUECARTE_H
