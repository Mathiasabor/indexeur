//
// Created by abor on 12/01/25.
//

#include "SizeSpecOption.h"
#include "SizeSpec.h"
#include "../SearchOptions.h"

SizeSpecOption::SizeSpecOption(QStringList sizeSpecOptions) {

    this->sizeSpecOptions = sizeSpecOptions;
    querySql.append(SearchOptions::getColumnName(sizeSpecOptions.first()));
}

void SizeSpecOption::buildSizeSpecOption(QStringList *errorList) {

    if(sizeSpecOptions.size() == 0) {
        errorList->append("SizeSpecOption: No size spec option provided");
        return;
    }

    if(sizeSpecOptions.size() ==2){
        querySql.append("=");
        QString size = SizeSpec().buildSize(sizeSpecOptions.last(),errorList);
        querySql.append(size);
    }

    if(sizeSpecOptions.contains("BETWEEN")){
        QStringList betweenSpec;
        int index = sizeSpecOptions.indexOf("BETWEEN");
        betweenSpec.append(sizeSpecOptions.at(index));
        betweenSpec.append(sizeSpecOptions.at(index+1));
        betweenSpec.append(sizeSpecOptions.at(index+2));
        betweenSpec.append(sizeSpecOptions.at(index+3));
        QString sizeBetween = SizeSpec().buildSizeBetween(betweenSpec,errorList,SearchOptions::getColumnName(sizeSpecOptions.first()));
        querySql.append(" "+sizeBetween);
    }
}

QString SizeSpecOption::toSql() {
    return querySql;
}
