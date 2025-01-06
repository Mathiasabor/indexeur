//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_ABSTRACTCOMMAND_H
#define INDEXEUR_ABSTRACTCOMMAND_H


#include <QString>
#include <QStringList>

class AbstractCommand {
public:
    AbstractCommand() ;
private:
    QString command;
    QStringList tokens;
};


#endif //INDEXEUR_ABSTRACTCOMMAND_H
