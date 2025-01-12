//
// Created by abor on 12/01/25.
//

#include "ExtOption.h"

ExtOption::ExtOption(QStringList extOptions) {
    this->extOptions = extOptions;
    // Constructor implementation
}

QString ExtOption::toSql() {
    return querySql;
}

void ExtOption::buildExtSpecOption(QStringList *errorList) {
    QStringList tempExtensions;
    querySql.append("extension IN (");

    for(int i = 1; i < extOptions.size(); i++){
        tempExtensions.append("'"+extOptions[i]+"'");
    }
    querySql.append(tempExtensions.join(","));
    querySql.append(")");
}
