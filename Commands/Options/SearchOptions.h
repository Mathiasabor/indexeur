//
// Created by abor on 06/01/25.
//

#ifndef INDEXEUR_SEARCHOPTIONS_H
#define INDEXEUR_SEARCHOPTIONS_H


#include <QStringList>

class SearchOptions {
public:
    static inline QList<QString> predefinedOptions = {"LAST_MODIFIED", "CREATED", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
    SearchOptions();
    QString toSqlQuery(QStringList queries, QStringList *errorList);
    QString getSearchQuerySql();
    void appendAdd();
    void appendSemicolon();
   static QString getColumnName(QString option);
   static QList<QString> findCommonOptions(QList<QString> tokens);
private:
    QString searchQuery;


};


#endif //INDEXEUR_SEARCHOPTIONS_H
