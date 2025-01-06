//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_FILESDTO_H
#define INDEXEUR_FILESDTO_H

#include <QString>

struct FilesDTO {
    QString name;
    QString extension;
    qint64 size;
    QString creationTime;
    QString lastUpdateTime;
    QString parentDirectory;
    QString path;
};

#endif //INDEXEUR_FILESDTO_H
