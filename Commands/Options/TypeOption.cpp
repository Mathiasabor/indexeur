//
// Created by abor on 12/01/25.
//

#include "TypeOption.h"


TypeOption::TypeOption(QStringList typeOptions) {
    this->typeOptions = typeOptions;
}

void TypeOption::buildTypeSpecOption(QStringList *errorList) {
    if(typeOptions.size() == 2) {
        querySql.append("extension IN (");
        querySql.append(getExtenions(typeOptions.last(),errorList));
        querySql.append(")");


    }else if(typeOptions.contains("OR")){

        QStringList tempExtensions;
        querySql.append("extension IN (");
        for(int i = 1; i < typeOptions.size(); i++){
            if(!(typeOptions.at(i) == "OR")){
                tempExtensions.append(getExtenions(typeOptions[i],errorList));
            }
        }
        querySql.append(tempExtensions.join(","));
        querySql.append(")");


    }else{
        errorList->append("TypeOption: No type spec option provided");
        return;
    }
}

QString TypeOption::toSql() {
    return querySql;
}

QString TypeOption::getExtenions(QString type, QStringList *errorList) {

    if (type == "image") {
        return imgExtensions;
    }
    else if (type == "text") {
        return txtExtensions;
    }
    else if (type == "exe") {
        return exeExtensions;
    }
    else {
        errorList->append("TypeOption: No type spec option provided");

        return QString();
    }


}
