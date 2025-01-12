//
// Created by abor on 05/01/25.
//

#include "CommandFactory.h"
#include "QueryingCommands/SearchCommand.h"
#include "Options/SearchOptions.h"
#include <QDebug>

CommandFactory::CommandFactory(QString commands, QStringList tokens, DB db)
        : Commands(commands), tokens(tokens), errorList(new QStringList()), db(db) {
    // Constructor implementation
}
void CommandFactory::createCommand() {

    if (tokens.at(1) == "SEARCH") {
       SearchCommand command ;
       SearchOptions searchOptions;
       QString argument = tokens.at(2);
       command.searchQuery.append("'%"+argument +"%' ");
       QString sqlquery;
       QList<QString> commonOptions = searchOptions.findCommonOptions(tokens);
       if(commonOptions.size() > 0){

           for(int i = 0; i < commonOptions.size(); i++){
               searchOptions.appendAdd();
               qDebug() << "common token : " << commonOptions.at(i);
               SearchCommand searchCommand;
                searchCommand.buildOption(commonOptions.at(i),commonOptions, tokens);
                searchOptions.toSqlQuery(searchCommand.getArguments(), errorList);


           }


       }else{
           qDebug() << "No options found";
       }

       searchOptions.appendSemicolon();



command.searchQuery.append(searchOptions.getSearchQuerySql());
       qDebug() << command.searchQuery;

       executedQuery = command.searchQuery;


    }


        qDebug() << "errorList" << errorList->size();
        for (const QString &error : *errorList) {
            qDebug() << "error : " << error;
        }

}

void CommandFactory::execute() {

    db.executeQuery(executedQuery, errorList);

}


