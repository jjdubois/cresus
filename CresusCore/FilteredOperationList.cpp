#include "FilteredOperationList.h"

Filter *FilteredOperationList::filter() const
{
    return m_filter;
}

void FilteredOperationList::setFilter(Filter *filter)
{
    m_filter = filter;

    Q_FOREACH( FilteredOperationList* operation, m_operationsLists )
    {
        operation->setFilter( filter );
    }
    update();
}

QString FilteredOperationList::label() const
{
    return m_source.label();
}

QString FilteredOperationList::icon() const
{
    return m_source.icon();
}

FilteredOperationList::FilteredOperationList(FilteredOperationList* parent, OperationsList& source):AbstractOperationsList( parent ), m_source( source )
{

}

void FilteredOperationList::update()
{

}

FilteredOperationList::FilteredOperationList(OperationsList &source):AbstractOperationsList( NULL ), m_source(source)
{
}
