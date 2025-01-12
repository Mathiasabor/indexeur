//
// Created by abor on 05/01/25.
//

#include "CommandFactory.h"
#include "QueryingCommands/SearchCommand.h"
#include "Options/SearchOptions.h"
#include <QDebug>

CommandFactory::CommandFactory(QString command, QStringList tokens)
        : Command(command), tokens(tokens) {
    // Constructor implementation
}
void CommandFactory::createCommand() {

    if (tokens.at(1) == "SEARCH") {
       SearchCommand command ;
       SearchOptions searchOptions;
       QString argument = tokens.at(2);
       command.searchQuery.append("'%"+argument +"%' AND");
       QString sqlquery;
       QList<QString> commonOptions = searchOptions.findCommonOptions(tokens);
       if(commonOptions.size() > 0){

           for(int i = 0; i < commonOptions.size(); i++){
               qDebug() << "common token : " << commonOptions.at(i);
               SearchCommand searchCommand;
                searchCommand.buildOption(commonOptions.at(i),commonOptions, tokens);
                searchOptions.toSqlQuery(searchCommand.getArguments(), errorList);

                if(i<commonOptions.size()-1){
                    searchOptions.appendAdd();
                }
           }


       }else{
           qDebug() << "No options found";
       }

command.searchQuery.append(searchOptions.getSearchQuerySql());
       qDebug() << command.searchQuery;


    }

    qDebug() << "errorList" << errorList->size();
    for (const QString &error : *errorList) {
        qDebug() << "error : " << error;
    }
}

void CommandFactory::execute(QString searchQuery) {

}
