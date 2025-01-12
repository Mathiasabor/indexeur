//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_EXTOPTION_H
#define INDEXEUR_EXTOPTION_H


#include <QStringList>

class ExtOption {
public:
    ExtOption(QStringList extOptions);
    QString toSql();
    void buildExtSpecOption(QStringList *errorList);
    QStringList getExtOptions();

private:
    QStringList extOptions;
    QString querySql;

};


#endif //INDEXEUR_EXTOPTION_H
