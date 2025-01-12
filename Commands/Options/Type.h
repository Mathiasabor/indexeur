//
// Created by Marie C on 11/01/2025.
//

#ifndef TYPE_H
#define TYPE_H

#include <QStringList>

class Type {
public:
    Type(QString token);
    QString sqlCommand();
private:
    QString token;
};



#endif //TYPE_H