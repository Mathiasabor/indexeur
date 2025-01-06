//
// Created by abor on 05/01/25.
//

#include "Tokenizer.h"
Tokenizer::Tokenizer(char **input, int argsize) {
    for (int i = 0; i < argsize; i++) {

        if (QString(input[i]).contains(':')) {
            splitAndAddToken(QString(input[i]));
        } else {
            tokens.append(QString(input[i]));
        }


    }
}

void Tokenizer::splitAndAddToken(const QString& token) {
    QStringList splitTokens = token.split(':'); // Remplacez ':' par le caractère de votre choix
    for (const QString& splitToken : splitTokens) {
        tokens.append(splitToken);
    }
}