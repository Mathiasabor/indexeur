//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_DATESPECOPTION_H
#define INDEXEUR_DATESPECOPTION_H


#include <QStringList>

class DateSpecOption {

private:
    QStringList dateSpecOptions;
    QString querySql;
public:
    DateSpecOption(QStringList dateSpecOptions);
    void buildDateSpecOption(QStringList *errorList);
    QString toSql();
};


#endif //INDEXEUR_DATESPECOPTION_H
