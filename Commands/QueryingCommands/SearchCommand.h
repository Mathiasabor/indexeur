//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_SEARCHCOMMAND_H
#define INDEXEUR_SEARCHCOMMAND_H


#include "QueryingCommand.h"

class SearchCommand : QueryingCommand {
private:

public:
    QString searchQuery = "SEARCH ";
    SearchCommand();
    QString toSql();

};


#endif //INDEXEUR_SEARCHCOMMAND_H
