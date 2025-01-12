//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_DATESPEC_H
#define INDEXEUR_DATESPEC_H


#include <QString>

class DateSpec {
private:
    QChar delimiteur = '/';
    QString date;
public:
    DateSpec();
    void toSql(QString command);
    QString buildDate(QString date,QStringList *errorList);
    QString buildDateBetween(QStringList betweenSpec,QStringList *errorList, QString columnName);

};


#endif //INDEXEUR_DATESPEC_H
