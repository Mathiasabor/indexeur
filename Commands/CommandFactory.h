//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_COMMANDFACTORY_H
#define INDEXEUR_COMMANDFACTORY_H


#include <QString>
#include <QStringList>
#include "../DAO/DB.h"

class CommandFactory {
private:
    QString Commands;
    QStringList tokens;
    QString executedQuery;
    DB db;

public:
    CommandFactory(QString command , QStringList tokens, DB db);
    void createCommand();
    void execute();
    QStringList *errorList;

};


#endif //INDEXEUR_COMMANDFACTORY_H
