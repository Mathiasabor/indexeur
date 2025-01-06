//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_TOKENIZER_H
#define INDEXEUR_TOKENIZER_H


#include <QStringList>

class Tokenizer {
private:
    void splitAndAddToken(const QString& token);
public:
    QStringList tokens;
    Tokenizer(char** input, int argsize);

};


#endif //INDEXEUR_TOKENIZER_H
