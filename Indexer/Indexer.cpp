//
// Created by abor on 05/01/25.
//

#include "Indexer.h"
#include "../DAO/DB.h"
#include <QDebug>
#include <QDirIterator>
#include <QDateTime>

Indexer::Indexer(QString folderPath) : state(IndexerState::STOPPED) {
    this->folderPath = folderPath;
    startIndexing();
}

void Indexer::startIndexing() {
    if(state == IndexerState::INDEXING) {
        qDebug() << "Indexation déjà en cours.\n";
        return;
    }

    state = IndexerState::INDEXING;
    availableFiles.clear();
    db.clearTable();
    qDebug() << "Indexation en cours...\n";

    QDirIterator it(folderPath, QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        it.next();
        QFileInfo fileInfo = it.fileInfo();
        if (fileInfo.isFile()) {
            availableFiles.append(QFile(fileInfo.absoluteFilePath()));
        }
    }
    setIndexedFiles();
    addIndexedFilesToDB();

    state = IndexerState::READY;

}

IndexerState Indexer::getState() {
    return state;
}

QList<QFileInfo> Indexer::getIndexedFiles() {
    return availableFiles;
}

void Indexer::setIndexedFiles() {
    indexedFiles.clear();
    for (const QFileInfo &fileInfo : availableFiles) {
        FilesDTO fileDTO;
        fileDTO.name = fileInfo.fileName();
        fileDTO.extension = fileInfo.suffix();
        fileDTO.size = fileInfo.size();
        QDateTime creationTime = fileInfo.birthTime();
        fileDTO.creationTime = creationTime.toString("yyyy-MM-dd HH:mm:ss");
        QDateTime lastUpdateTime = fileInfo.lastModified();
        fileDTO.lastUpdateTime = lastUpdateTime.toString("yyyy-MM-dd HH:mm:ss");
        fileDTO.parentDirectory = fileInfo.path();
        fileDTO.path = fileInfo.absoluteFilePath();

        indexedFiles.append(fileDTO);
    }

    qDebug() << "Indexation terminée. " << indexedFiles.size() << " fichiers indexés.\n";
}

void Indexer::addIndexedFilesToDB() {

    db.insertDatas(indexedFiles);
}