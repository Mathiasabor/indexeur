//
// Created by abor on 12/01/25.
//

#ifndef INDEXEUR_MINSIZEOPTION_H
#define INDEXEUR_MINSIZEOPTION_H


#include <QStringList>
#include "SizeSpec/SizeSpecOption.h"

class MinSizeOption : public SizeSpecOption {

public:
    MinSizeOption(QStringList minSizeOptions);
};


#endif //INDEXEUR_MINSIZEOPTION_H
