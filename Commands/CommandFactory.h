//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_COMMANDFACTORY_H
#define INDEXEUR_COMMANDFACTORY_H


#include <QString>
#include <QStringList>

class CommandFactory {
private:
    QString Command;
    QStringList tokens;

public:
    CommandFactory(QString command , QStringList tokens);
    void createCommand();
    void execute(QString searchQuery); ;
    QStringList *errorList;

};


#endif //INDEXEUR_COMMANDFACTORY_H
