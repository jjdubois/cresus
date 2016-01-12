#ifndef OPERATIONLIST_H
#define OPERATIONLIST_H

#include <Operation.h>

class OperationList{
public:
    virtual int count() const = 0;
    virtual Operation operation( int i ) const = 0;
};

#endif // OPERATIONLIST_H
