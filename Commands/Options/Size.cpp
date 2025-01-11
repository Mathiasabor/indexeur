//
// Created by Marie C on 11/01/2025.
//

#include "Size.h"

Size::Size(QString token) {
    this->token = token;
}

QString Size::tokenToSize() {
    QString unit = token.section(-1);
    int digits = token.chop(1).toInt();
    if (unit == "K") {
        return QString::number(digits * 1024);
    }
    else if (unit == "M") {
        return QString::number(digits * 1048576);
    }
    else if (unit == "G") {
        return QString::number(digits * 1073741824);
    }
    else {
        //throw error
    }
}

