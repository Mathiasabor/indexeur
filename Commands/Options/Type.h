//
// Created by Marie C on 11/01/2025.
//

#ifndef TYPE_H
#define TYPE_H

#include <QStringList>

class Type {
public:
    Type(QStringList tokens);
    QString sqlCommand();
private:
    QString tokens;
};



#endif //TYPE_H
