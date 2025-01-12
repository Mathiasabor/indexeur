//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_SIZESPECOPTION_H
#define INDEXEUR_SIZESPECOPTION_H


#include <QStringList>

class SizeSpecOption {
private:
    QStringList sizeSpecOptions;
    QString querySql;
public:
    SizeSpecOption(QStringList sizeSpecOptions);
    void buildSizeSpecOption(QStringList *errorList);
    QString toSql();
};


#endif //INDEXEUR_SIZESPECOPTION_H
