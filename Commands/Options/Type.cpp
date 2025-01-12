//
// Created by Marie C on 11/01/2025.
//

#include "Type.h"

Type::Type(QStringList tokens) {
  this->tokens = tokens;
}

QString Type::sqlCommand() {
    QString sqlOptions;
    int index = 0;
    while (index < tokens.size()) {
        if (tokens[index].section(-1) == ",") {
            QString token = tokens[index].section(-1);
            if (toSqlOption(token)) {
                sqlOptions += toSqlOption(token) + " OR ";
            }
        }
        else if (tokens[index] == "OR") {
            sqlOptions += " OR ";
        }
        else if (toSqlOption(tokens[index])) {
            sqlOptions += (toSqlOption(tokens[index]);
        }
        index++;
    }
}

QString Type::toSqlOption(QString token) {
    QString txtExtensions = "'.html', '.txt', '.md', '.mdx', '.asc', '.doc', '.docx', '.pdf', '.wps', '.wpd', '.rtf', '.msg'";
    QString imgExtensions = "'.webp', '.apng', '.png', '.avif', '.gif', '.jpg', '.jpeg', '.jfif', '.pjpeg', '.pjp', '.png', '.svg'";
    QString exeExtensions = "'.exe', '.bat', '.sh'";

    if (token == "image") {
        return "extension IN (" + imgExtensions + ")";
    }
    else if (token == "text") {
        return "extension IN (" + txtExtensions + ")";
    }
    else if (token == "exe") {
        return "extension IN (" + exeExtensions + ")";
    }
    else {
        //throw error
    }
}