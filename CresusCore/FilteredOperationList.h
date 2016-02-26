#ifndef FILTEREDOPERATIONLIST_H
#define FILTEREDOPERATIONLIST_H

#include <OperationsList.h>
#include <Filter.h>
#include <AbstractOperationsList.h>
class FilteredOperationList : public AbstractOperationsList<FilteredOperationList>
{
    Filter *m_filter;
    OperationsList& m_source;
public:
    FilteredOperationList( OperationsList& source );

    Filter *filter() const;
    void setFilter(Filter *filter);

    QString label() const;
    QString icon() const;


private:
    FilteredOperationList( FilteredOperationList* parent, OperationsList& source );
    void update();
};

#endif // FILTEREDOPERATIONLIST_H
