#ifndef MACHI_KORO_MAISONEDITION_H
#define MACHI_KORO_MAISONEDITION_H

class MaisonEdition : public Batiment {
public:
    MaisonEdition();
    virtual void declencher_effet() const;
};

#endif //MACHI_KORO_MAISONEDITION_H
