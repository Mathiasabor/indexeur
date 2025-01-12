//
// Created by abor on 05/01/25.
//

#ifndef INDEXEUR_OPTIONS_H
#define INDEXEUR_OPTIONS_H


#include <QString>
#include <QList>

enum class Options {
LAST_MODIFIED,
CREATED,
MAX_SIZE,
MIN_SIZE,
SIZE,
EXT,
TYPE
};


const QList<QString> predefinedOptions = {"LAST_MODIFIED", "CREATED", "MAX_SIZE", "MIN_SIZE", "SIZE", "EXT", "TYPE"};
inline QString optionToString(Options option) {
    switch (option) {
        case Options::LAST_MODIFIED: return "LAST_MODIFIED";
        case Options::CREATED: return "CREATED";
        case Options::MAX_SIZE: return "MAX_SIZE";
        case Options::MIN_SIZE: return "MIN_SIZE";
        case Options::SIZE: return "SIZE";
        case Options::EXT: return "EXT";
        case Options::TYPE: return "TYPE";
        default: return "UNKNOWN";
    }
}

inline QList<QString> findCommonOptions(QList<QString> tokens) {
    QList<QStringList> commonOptions;
    QStringList option;
    commonOptions.append(option);
    for (const auto& TokensOption : tokens) {
        for (const auto& predefinedOption : predefinedOptions) {
            if (TokensOption == predefinedOption) {
                QStringList newOption;
                commonOptions.append(newOption);
                newOption.append(TokensOption);
            }
            else {
                option.append(TokensOption);
            }
        }
    }
    return commonOptions;
}


#endif //INDEXEUR_OPTIONS_H
