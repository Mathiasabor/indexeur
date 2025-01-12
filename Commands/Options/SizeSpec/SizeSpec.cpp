//
// Created by abor on 12/01/25.
//

#include <QStringList>
#include "SizeSpec.h"


SizeSpec::SizeSpec() {
    // Constructor implementation
}

QString SizeSpec::buildSize(QString size, QStringList *errorList) {

    QString unit = size.right(1);
    int sizeValue = size.left(size.length()-1).toInt();

    if (unit == "K") {
        return QString::number(sizeValue* 1024);
    }
   else if (unit == "M") {
        return QString::number(sizeValue* 1048576);
    }
   else if (unit == "G") {
        return QString::number(sizeValue* 1073741824);
    }
else{
        errorList->append("Unité de taille non reconnue");
        return QString();
    }



}

QString SizeSpec::buildSizeBetween(QStringList betweenSpec, QStringList *errorList, QString columnName) {

    QString size1 = buildSize(betweenSpec.at(1),errorList);
    QString size2 = buildSize(betweenSpec.at(3),errorList);
    if(size1.isEmpty() || size2.isEmpty()){
        errorList->append("Unité de taille non reconnue");
        return "";
    }
    return QString(">= %1 AND %2 <= %3").arg(size1).arg(columnName).arg(size2);

}
