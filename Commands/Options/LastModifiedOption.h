//
// Created by abor on 09/01/25.
//

#ifndef INDEXEUR_LASTMODIFIEDOPTION_H
#define INDEXEUR_LASTMODIFIEDOPTION_H


#include "DateSpec/DateSpecOption.h"

class LastModifiedOption : public DateSpecOption{
public:
    LastModifiedOption(QStringList lastModifiedOptions);
};


#endif //INDEXEUR_LASTMODIFIEDOPTION_H
