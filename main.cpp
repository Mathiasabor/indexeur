#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>
#include "Indexer/Indexer.h"
#include "Tokenizer/Tokenizer.h"

#include "Commands/CommandFactory.h"
#include "Commands/Options/SearchOptions.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
/*
   Indexer indexer("/home/abor/Téléchargements/");  // Remplacez par votre chemin
   qDebug() << "État actuel : " << stateToString(indexer.getState());

    qDebug() << "Fichiers indexés : " << indexer.getIndexedFiles().size();
*/
/*
    for (const QFileInfo &fileInfo : indexer.getIndexedFiles()) {
        qDebug() << "Nom du fichier : " << fileInfo.fileName();
        qDebug() << "Chemin absolu : " << fileInfo.absoluteFilePath();
        qDebug() << "Extension : " << fileInfo.suffix();
        qDebug() << "Taille : " << fileInfo.size() << " octets";
        QDateTime lastModified = fileInfo.lastModified();
        qDebug() << "Dernière modification : " << lastModified.toString("yyyy-MM-dd HH:mm:ss");  ;

    }
*/

DB db = DB();
Tokenizer tokenizer(argv, argc);
QStringList tokens = SearchOptions::findCommonOptions(tokenizer.tokens);
CommandFactory commandFactory(tokenizer.tokens.first(), tokenizer.tokens, db);
commandFactory.createCommand();
commandFactory.execute();


    qDebug() << "Hello World";
    return QCoreApplication::exec();
}
