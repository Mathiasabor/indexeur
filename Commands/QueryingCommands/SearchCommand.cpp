//
// Created by abor on 05/01/25.
//

#include "SearchCommand.h"
#include "QDebug"
SearchCommand::SearchCommand() {
    // Constructor implementation
}

QString SearchCommand::toSql() {
    return queryOption ;
}

QStringList SearchCommand::getArguments() {
    return arguments;
}

void SearchCommand::buildOption(QString option, QStringList commonOptions, QStringList tokens) {
    this->option = option;
    arguments.append(option);
    int index = tokens.indexOf(option);
   // qDebug() << "Index of created" << index << "tokens size" << tokens.size();
    int i = index;
    while (!commonOptions.contains(tokens.at(i+1))){
        arguments.append(tokens.at(i+1));
        i++;
        if(i+1 == tokens.size()){
            break;
        }
    }
    QString command = arguments.join(" ");
    queryOption = command;
}
