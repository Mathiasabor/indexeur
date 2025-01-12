//
// Created by abor on 06/01/25.
//

#include "SearchOptions.h"

#include "CreatedOption.h"
#include "LastModifiedOption.h"
#include "MaxSizeOption.h"
#include "MinSizeOption.h"
#include "SizeOption.h"
#include "ExtOption.h"
#include "TypeOption.h"
#include "QDebug"

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
            MaxSizeOption maxSizeOption(queries);
            maxSizeOption.buildSizeSpecOption(errorList);
            searchQuery.append(" "+maxSizeOption.toSql());
            return maxSizeOption.toSql();


        } else if (querytok == "MIN_SIZE") {
            MinSizeOption minSizeOption(queries);
            minSizeOption.buildSizeSpecOption(errorList);
            searchQuery.append(" "+minSizeOption.toSql());
            return minSizeOption.toSql();

        } else if (querytok == "SIZE") {

            SizeOption sizeOption(queries);
            sizeOption.buildSizeSpecOption(errorList);
            searchQuery.append(" "+sizeOption.toSql());
            return sizeOption.toSql();


        } else if (querytok == "EXT") {
            ExtOption extOption(queries);
            extOption.buildExtSpecOption(errorList);
            searchQuery.append(" "+extOption.toSql());
            return extOption.toSql();

        } else if (querytok == "TYPE") {
            TypeOption typeOption(queries);
            typeOption.buildTypeSpecOption(errorList);
            searchQuery.append(" "+typeOption.toSql());
            return typeOption.toSql();

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
        return "size <";
    } else if (option == "MIN_SIZE") {
        return "size >";
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

void SearchOptions::appendSemicolon() {
    searchQuery.append(";");

}
