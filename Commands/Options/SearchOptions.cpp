//
// Created by abor on 06/01/25.
//

#include "SearchOptions.h"
#include "Options.h"
#include "Size.h"
#include "Type.h"


SearchOptions::SearchOptions(QStringList tokens) {
    this->tokens = tokens;
}

QString SearchOptions::toSqlOptions() {
    QStringList sqlOptions = "WHERE ";

    //QStringList commonOptions = findCommonOptions(tokens);

    for (const QString &token : tokens) {
        if (token == "LAST_MODIFIED") {
            return ;
        } else if (token == "CREATED") {
            return ;
        } else if (token == "MAX_SIZE") {
            Size size(tokens.getNextToken());
            if (size.sqlCommand()) {
                sqlOptions += "size <= " + size.sqlCommand();
            }
        } else if (token == "MIN_SIZE") {
            Size size(tokens.getNextToken());
            if (size.sqlCommand()) {
                sqlOptions += "size >= " + size.sqlCommand();
            }
        } else if (token == "SIZE") {
            QString nextToken = tokens.getnextTtoken();
            if (nextToken == "BETWEEN") {
                QString token1 = tokens.getnextToken();
                QString tokenAnd = tokens.getnextToken();
                QString token2 = tokens.getnextToken();
                if (tokenAnd != "AND") {
                    //trow error
                }
                else {
                    Size size1(token1);
                    Size size2(token2);
                    if (size1.sqlCommand() && size2.sqlCommand()) {
                        sqlOptions += "size >= " + size1.sqlCommand() + " AND size <=" + size2.sqlCommand();
                    }
                }
            }
            else {
                Size size(nextToken);
                if (size.sqlCommand()) {
                    sqlOptions += "size >= " + size.sqlCommand();
                }
            }
        } else if (token == "EXT") {
            return ;
        } else if (token == "TYPE") {
          QString tables;
          QString nextToken = tokens.getNextToken();

             if (nextToken.section(-1) == ",") {
                 Type type(token.section(-1));
                 if (type.sqlCommand()) {
                     sqlOptions += type.sqlCommand();
                 }
                 //recall for next token ??
             }
             else {
                 Type type(token);
                 if (type.sqlCommand()) {
                     sqlOptions += type.sqlCommand();
                 }

             }
             //while (  tokens.getNextToken() == "OR" or nextToken.section(-1) == "," ) {
                 // tables += "OR"
                // get next token
                // sqlCommand(token);
        }
        sqlOptions += " AND ";
    }

    return QString();
}


