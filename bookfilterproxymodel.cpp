#include "bookfilterproxymodel.h"

BookFilterProxyModel::BookFilterProxyModel(QObject* parent) : QSortFilterProxyModel(parent), yearFilterVal(0)
{
}

bool BookFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex authorIdx = sourceModel()->index(sourceRow, 0, sourceParent);
    QModelIndex titleIdx = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex yearIdx = sourceModel()->index(sourceRow, 2, sourceParent);

    QString author = sourceModel()->data(authorIdx).toString();
    QString title = sourceModel()->data(titleIdx).toString();
    QString year = sourceModel()->data(yearIdx).toString();

    if(yearFilterVal == 0) {
        return author.contains(authorRegex) && title.contains(titleRegex);
    }

    int yearVal = year.toInt();
    return (author.contains(authorRegex) && title.contains(titleRegex) && yearVal == yearFilterVal);
}

void BookFilterProxyModel::setAuthorFilter(const QString& regExp)
{
    authorRegex.setPattern(regExp);
    invalidateFilter();
}

void BookFilterProxyModel::setTitleFilter(const QString& regExp)
{
    titleRegex.setPattern(regExp);
    invalidateFilter();
}

void BookFilterProxyModel::setYearFilter(const QString& val)
{
    yearFilterVal = val.toInt();
    invalidateFilter();
}
