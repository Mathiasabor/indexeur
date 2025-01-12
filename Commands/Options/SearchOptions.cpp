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

    QList<QStringList> options = findCommonOptions(tokens);

    for (const QStringList &option : options) {
      int index = 0;
      while( index < option.size()) {
        if (option[index] == "LAST_MODIFIED") {
            //
        } else if (option[index] == "CREATED") {
            //
        } else if (option[index] == "MAX_SIZE") {
            index++;
            Size size(option[index]);
            if (size.sqlCommand()) {
                sqlOptions += "size <= " + size.sqlCommand();
            }
        } else if (option[index] == "MIN_SIZE") {
            index++;
            Size size(option[index]);
            if (size.sqlCommand()) {
                sqlOptions += "size >= " + size.sqlCommand();
            }
        } else if (option[index] == "SIZE") {
            index++;
            if (option[index] == "BETWEEN") {
                index++;
                QString token1 = option[index];
                index++;
                QString tokenAnd = option[index];
                index++;
                QString token2 = option[index];
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
                Size size(option[index]);
                if (size.sqlCommand()) {
                    sqlOptions += "size >= " + size.sqlCommand();
                }
            }
        } else if (option == "EXT") {
            //
        } else if (option == "TYPE") {
            index++;
            Type type(option.mid(index));
            if (type.sqlCommand()) {
                sqlOptions += type.sqlCommand();
            }
            index = option.size();
        }
        sqlOptions += " AND ";
      }
    }
    return QString();
}

