//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_QUERYINGCOMMAND_H
#define INDEXEUR_QUERYINGCOMMAND_H


#include <QString>
#include "../AbstractCommand.h"

class QueryingCommand : AbstractCommand {
public:
    QString toSql();
    QueryingCommand();
};


#endif //INDEXEUR_QUERYINGCOMMAND_H
