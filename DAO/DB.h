//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_DB_H
#define INDEXEUR_DB_H


#include "FilesDTO.h"
#include <QSqlDatabase>

class DB {

public:
    DB();
    void clearTable();
    void insertDatas(QList<FilesDTO> files);
private:
    QSqlDatabase db;
    void createTable();


};


#endif //INDEXEUR_DB_H
