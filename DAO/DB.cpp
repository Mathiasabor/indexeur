//
// Created by abor on 05/01/25.
//

#include <QSqlDatabase>
#include "DB.h"
#include "QueryManager.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

DB::DB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/abor/Bureau/ynov/devLogiciel/indexer.db");
    createTable();

}

void DB::createTable() {

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données ";
        return;
    }

    QSqlQuery query;
    query.prepare(createTableFileDTOQuery);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la création de la table  " ;
    } else {
        qDebug() << "Table créée avec succès!";
    }
}

void DB::insertDatas(QList<FilesDTO> indexedFiles) {
    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données ";
        return;
    }

    QSqlQuery query;
    query.prepare(insertFileDTOQuery);

    for (const FilesDTO &file : indexedFiles) {
        query.bindValue(":name", file.name);
        query.bindValue(":extension", file.extension);
        query.bindValue(":size", file.size);
        query.bindValue(":creationTime", file.creationTime);
        query.bindValue(":lastUpdateTime", file.lastUpdateTime);
        query.bindValue(":parentDirectory", file.parentDirectory);
        query.bindValue(":path", file.path);

        if (!query.exec()) {
            QSqlError error = query.lastError();
            qDebug() << "Erreur lors de l'insertion de données  " << error.text();
        }
    }

    qDebug() << "Données insérées avec succès!";
}

void DB::clearTable() {
    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données ";
        return;
    }

    QSqlQuery query;
    query.prepare(clearTableFileDTOQuery);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression des données  ";
    } else {
        qDebug() << "Données supprimées avec succès!";
    }

}

void DB::executeQuery(QString query, QStringList *errorList) {
    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données ";
        return;
    }

    QSqlQuery sqlQuery;
    sqlQuery.prepare(query);




    if (!sqlQuery.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête  " << sqlQuery.lastError().text();
        errorList->append(sqlQuery.lastError().text());
    } else {
        qDebug() << "Requête exécutée avec succès!";

        while (sqlQuery.next()) {
            qDebug() << "name : " << sqlQuery.value(0).toString();
            qDebug() << "extension : " << sqlQuery.value(1).toString();
            qDebug() << "size : " << sqlQuery.value(2).toString();
            qDebug() << "creationTime : " << sqlQuery.value(3).toString();
            qDebug() << "lastUpdateTime : " << sqlQuery.value(4).toString();
            qDebug() << "parentDirectory : " << sqlQuery.value(5).toString();
            qDebug() << "path : " << sqlQuery.value(6).toString();
        }

    }

}
