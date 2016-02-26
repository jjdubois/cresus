#ifndef FILTER_H
#define FILTER_H

#include <QObject>

class Operation;

class Filter : public QObject
{
public:
    Filter( QObject* parent = NULL);
    virtual bool accept( const Operation& operation ) = 0;

signals:
    void filterChanged();
};

#endif // FILTER_H
