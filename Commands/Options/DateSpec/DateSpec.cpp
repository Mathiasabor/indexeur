//
// Created by abor on 12/01/25.
//

#include <QStringList>
#include <QTextStream>
#include "DateSpec.h"


DateSpec::DateSpec() {
    // Constructor implementation
}


QString DateSpec::buildDate(QString date, QStringList *errorList) {
    this->date = date;
    int jour, mois, annee;
    QTextStream qin(&date);
    qin >> jour >> delimiteur >> mois >> delimiteur >> annee;

    if (qin.status() != QTextStream::Ok || delimiteur != '/') {
        errorList->append("Format de date invalide.");
        return "";
    }

    QString dateConvertie = QString("'%1-%2-%3'")
            .arg(annee, 4, 10, QChar('0')) // Remplissage à gauche avec des 0 pour l'année
            .arg(mois, 2, 10, QChar('0'))  // Remplissage à gauche avec des 0 pour le mois
            .arg(jour, 2, 10, QChar('0')); // Remplissage à gauche avec des 0 pour le jour

    return dateConvertie;
}

QString DateSpec::buildDateBetween(QStringList betweenSpec, QStringList *errorList, QString columnName) {
    QString date1 = buildDate(betweenSpec.at(1),errorList);
    QString date2 = buildDate(betweenSpec.at(3),errorList);
    if(date1.isEmpty() || date2.isEmpty()){
        errorList->append("Format de date invalide.");
        return "";
    }
    return QString(">= %1 AND %2 <= %3").arg(date1).arg(columnName).arg(date2);
}


