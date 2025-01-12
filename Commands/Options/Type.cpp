//
// Created by Marie C on 11/01/2025.
//

#include "Type.h"

Type::Type(QString token) {
  this->token = token;
}

QString Type::sqlCommand() {
    QString txtExtensions = "'.html', '.txt', '.md', '.mdx', '.asc', '.doc', '.docx', '.pdf', '.wps', '.wpd', '.rtf', '.msg'";
    QString imgExtensions = "'.webp', '.apng', '.png', '.avif', '.gif', '.jpg', '.jpeg', '.jfif', '.pjpeg', '.pjp', '.png', '.svg'";
    QString exeExtensions = "'.exe', '.bat', '.sh'";

    if (token == "image") {
        return "extension IN (" + imgExtensions + ")";
    }
    else if (token == "text") {
        return "extension IN (" + txtExtensions + ")";
    }
    else if (token == "exe") {
        return "extension IN (" + exeExtensions + ")";
    }
    else {
        //throw error
    }
}