//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_SEARCHCOMMAND_H
#define INDEXEUR_SEARCHCOMMAND_H


#include "QueryingCommand.h"

class SearchCommand  {
private:
    QString queryOption;
    QString option;
    QStringList arguments;
public:
    QString searchQuery = "SELECT * FROM indexed_file WHERE name LIKE ";
    SearchCommand();
    QString toSql();
    void buildOption(QString option,QStringList commonOptions, QStringList tokens);
    QStringList getArguments();

};


#endif //INDEXEUR_SEARCHCOMMAND_H
