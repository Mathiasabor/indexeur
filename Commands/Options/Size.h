//
// Created by Marie C on 11/01/2025.
//

#ifndef SIZE_H
#define SIZE_H

#include <QStringList>

class Size {
public:
    Size(QString token);
    QString sqlCommand();
private:
    QString token;
};

#endif //SIZE_H
