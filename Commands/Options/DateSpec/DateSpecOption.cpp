//
// Created by abor on 12/01/25.
//

#include "DateSpecOption.h"
#include "DateSpec.h"
#include "../SearchOptions.h"

DateSpecOption::DateSpecOption(QStringList dateSpecOptions) {

    this->dateSpecOptions = dateSpecOptions;
    querySql.append(SearchOptions::getColumnName(dateSpecOptions.first()));
    // Constructor implementation
}

void DateSpecOption::buildDateSpecOption(QStringList *errorList){
    if(dateSpecOptions.size()==2){
        querySql.append("=");
        QString date = DateSpec().buildDate(dateSpecOptions.last(),errorList);
        querySql.append(date);
    }
    if(dateSpecOptions.contains("BETWEEN")){
        QStringList betweenSpec;
        int index = dateSpecOptions.indexOf("BETWEEN");
        betweenSpec.append(dateSpecOptions.at(index));
        betweenSpec.append(dateSpecOptions.at(index+1));
        betweenSpec.append(dateSpecOptions.at(index+2));
        betweenSpec.append(dateSpecOptions.at(index+3));
        QString dateBetween = DateSpec().buildDateBetween(betweenSpec,errorList,SearchOptions::getColumnName(dateSpecOptions.first()));
        querySql.append(" "+dateBetween);
    }
}

QString DateSpecOption::toSql() {
    return querySql;
}