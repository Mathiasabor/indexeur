//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_SIZESPEC_H
#define INDEXEUR_SIZESPEC_H


#include <QString>

class SizeSpec {

public:
    SizeSpec();
    void toSql(QString command);
    QString buildSize(QString size,QStringList *errorList);
    QString buildSizeBetween(QStringList betweenSpec,QStringList *errorList, QString columnName);
};


#endif //INDEXEUR_SIZESPEC_H
