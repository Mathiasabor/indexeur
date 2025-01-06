//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_QUERYMANAGER_H
#define INDEXEUR_QUERYMANAGER_H


const char* createTableFileDTOQuery = "CREATE TABLE IF NOT EXISTS indexed_file ("
                                      "id INTEGER PRIMARY KEY AUTOINCREMENT,  "
                                      "name TEXT NOT NULL,  "
                                      "extension TEXT ,  "
                                      "size INTEGER NOT NULL,    "
                                      "creationTime TEXT NOT NULL, "
                                      "lastUpdateTime TEXT NOT NULL, "
                                      "parentDirectory TEXT NOT NULL,  "
                                      "path TEXT NOT NULL);";

const char* insertFileDTOQuery = "INSERT INTO indexed_file (name, extension, size, creationTime, lastUpdateTime, parentDirectory, path) "
                                 "VALUES (:name, :extension, :size, :creationTime, :lastUpdateTime, :parentDirectory, :path)";

const char* clearTableFileDTOQuery = "DELETE FROM indexed_file";

#endif //INDEXEUR_QUERYMANAGER_H
