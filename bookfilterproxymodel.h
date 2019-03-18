#ifndef BOOKFILTERPROXYMODEL_H
#define BOOKFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class BookFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit BookFilterProxyModel(QObject* parent = nullptr);

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const  override;

public slots:
    void setAuthorFilter(const QString& regExp);
    void setTitleFilter(const QString& regExp);
    void setYearFilter(const QString& regExp);

private:
   QRegExp authorRegex;
   QRegExp titleRegex;
   int yearFilterVal;
};

#endif // BOOKFILTERPROXYMODEL_H
