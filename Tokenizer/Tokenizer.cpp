//
// Created by abor on 05/01/25.
//

#include "Tokenizer.h"
#include <QDebug>
Tokenizer::Tokenizer(char **input, int argsize) {
    for (int i = 0; i < argsize; i++) {

        if (QString(input[i]).contains(':')) {
            splitAndAddToken(QString(input[i]));
        }else if(QString(input[i]).contains(',')){
            splitAndAddToken(QString(input[i]));
        }
        else {
            tokens.append(QString(input[i]));
        }


    }
}

void Tokenizer::splitAndAddToken(const QString& token) {
    QStringList splitTokens = token.split(QRegExp("[:,]")); // Remplacez ':' par le caractère de votre choix
    for (const QString& splitToken : splitTokens) {

        if(!splitToken.isEmpty()){

            qDebug() << "splitToken : " << splitToken;
            tokens.append(splitToken);
        }

    }
}