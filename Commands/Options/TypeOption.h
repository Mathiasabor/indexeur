//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_TYPEOPTION_H
#define INDEXEUR_TYPEOPTION_H


#include <QStringList>

class TypeOption {

public:
    TypeOption(QStringList typeOptions);
    void buildTypeSpecOption(QStringList *errorList);
    QString toSql();

private:
    QStringList typeOptions;
    QString querySql;
    QString txtExtensions = "'html', 'txt', 'md', 'mdx', 'asc', 'doc', 'docx', 'pdf', 'wps', 'wpd', 'rtf', 'msg'";
    QString imgExtensions = "'webp', 'apng', 'png', 'avif', 'gif', 'jpg', 'jpeg', 'jfif', 'pjpeg', 'pjp', 'png', 'svg'";
    QString exeExtensions = "'exe', 'bat', 'sh'";
    QString getExtenions(QString type, QStringList *errorList);
};


#endif //INDEXEUR_TYPEOPTION_H
