//
// Created by abor on 06/01/25.
//

#include "SearchOptions.h"

#include "CreatedOption.h"
#include "LastModifiedOption.h"

SearchOptions::SearchOptions() {

}

QString SearchOptions::toSqlQuery(QStringList queries, QStringList *errorList) {


    for (const QString &querytok : queries) {
        if (querytok == "LAST_MODIFIED") {
            LastModifiedOption lastModifiedOption(queries);
            lastModifiedOption.buildDateSpecOption(errorList);
            searchQuery.append(" "+lastModifiedOption.toSql());
            return lastModifiedOption.toSql();
        } else if (querytok == "CREATED") {
            CreatedOption createdOption(queries);
            createdOption.buildDateSpecOption(errorList);
            searchQuery.append(" "+createdOption.toSql());
            return createdOption.toSql();
        } else if (querytok == "MAX_SIZE") {
            return "ORDER BY size DESC";
        } else if (querytok == "MIN_SIZE") {
            return "ORDER BY size ASC";
        } else if (querytok == "SIZE") {
            return "ORDER BY size";
        } else if (querytok == "EXT") {
            return "ORDER BY extension";
        } else if (querytok == "TYPE") {
            return "ORDER BY extension";
        }
    }
    return QString();
}

QString SearchOptions::getSearchQuerySql() {
    return searchQuery;
}

void SearchOptions::appendAdd() {
    searchQuery.append(" AND");

}

QString SearchOptions::getColumnName(QString option) {

    if (option == "LAST_MODIFIED") {
        return "date(lastUpdateTime)";
    } else if (option == "CREATED") {
        return "date(creationTime)";
    } else if (option == "MAX_SIZE") {
        return "size";
    } else if (option == "MIN_SIZE") {
        return "size";
    } else if (option == "SIZE") {
        return "size";
    } else if (option == "EXT") {
        return "extension";
    } else if (option == "TYPE") {
        return "extension";
    }
    return QString();
}

QList<QString> SearchOptions::findCommonOptions(QList<QString> tokens) {
    QList<QString> commonOptions;
    for (const auto& TokensOption : tokens) {
        for (const auto& predefinedOption : predefinedOptions) {
            if (TokensOption == predefinedOption) {
                commonOptions.append(TokensOption);
            }
        }
    }
    return commonOptions;
}
