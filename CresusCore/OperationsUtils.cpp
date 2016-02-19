#include "OperationsUtils.h"
#include <qmath.h>

int Cresus::amountFromDouble(double value)
{
    return qCeil( value*100 );
}

int Cresus::doubleFromAmount(int value)
{
    return value / 100.;
}
