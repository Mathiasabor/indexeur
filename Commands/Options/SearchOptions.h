//
// Created by abor on 06/01/25.
//

#ifndef INDEXEUR_SEARCHOPTIONS_H
#define INDEXEUR_SEARCHOPTIONS_H


#include <QStringList>

class SearchOptions {
public:
    SearchOptions(QStringList tokens);
    QString toSqlQuery();
private:
    QStringList tokens;
};


#endif //INDEXEUR_SEARCHOPTIONS_H
