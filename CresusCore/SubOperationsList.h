#ifndef SUBOPERATIONSLIST_H
#define SUBOPERATIONSLIST_H

#include <AbstractOperationsList.h>
class OperationManager;

class SubOperationsList : public AbstractOperationsList<SubOperationsList>
{
public:
    SubOperationsList( OperationManager& manager, OperationsList& parent );


    virtual void addOperation(const Operation& operation);
    virtual void removeOperation(int index);
    virtual OperationsList*createChild();
    virtual void removeChild(int index);

private:

    void removeOperationInternal( const Operation& operation );
    void addOperationInternal( const Operation& operation );
    OperationManager& m_manager;

};

#endif // SUBOPERATIONSLIST_H

