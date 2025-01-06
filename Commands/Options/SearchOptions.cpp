//
// Created by abor on 06/01/25.
//

#include "SearchOptions.h"
#include "Options.h"

SearchOptions::SearchOptions(QStringList tokens) {
    this->tokens = tokens;
}

QString SearchOptions::toSqlQuery() {
    QStringList sqlCommands;

    QStringList commonOptions = findCommonOptions(tokens);



    for (const QString &token : tokens) {
        if (token == "LAST_MODIFIED") {
            return "ORDER BY lastUpdateTime DESC";
        } else if (token == "CREATED") {
            return "ORDER BY creationTime DESC";
        } else if (token == "MAX_SIZE") {
            return "ORDER BY size DESC";
        } else if (token == "MIN_SIZE") {
            return "ORDER BY size ASC";
        } else if (token == "SIZE") {
            return "ORDER BY size";
        } else if (token == "EXT") {
            return "ORDER BY extension";
        } else if (token == "TYPE") {
            return "ORDER BY extension";
        }
    }
    return QString();
}
