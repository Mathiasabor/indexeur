//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_INDEXER_H
#define INDEXEUR_INDEXER_H


#include <QString>
#include <QFile>
#include <QFileInfo>
#include "IndexerState.h"
#include "../DAO/FilesDTO.h"
#include "../DAO/DB.h"

class Indexer {
public:
    IndexerState state;  // État actuel de l'indexeur
    Indexer(QString folderPath);
    IndexerState getState();
    QList<QFileInfo> getIndexedFiles();

private:
    DB db;
    QList<FilesDTO> indexedFiles;  // Ensemble des fichiers indexés
    QList<QFileInfo> availableFiles;  // Ensemble des fichiers indexés
    QString folderPath;
    void startIndexing();
    void setIndexedFiles();
    void addIndexedFilesToDB();
};


#endif //INDEXEUR_INDEXER_H
