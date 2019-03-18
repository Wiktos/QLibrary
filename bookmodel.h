#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>
#include <sstream>
#include "book.h"

class BookModel : public QAbstractTableModel
{
    QList<Book> books;

    friend std::ostream& operator<<(std::ostream& os, const BookModel& bookModel);
    friend std::istream& operator>>(std::istream& is, BookModel& bookModel);

public:
    BookModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &) const override { return books.count(); }
    int columnCount(const QModelIndex &) const override { return 3; }
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void append(const Book &book);
    void remove(const int& idx);
    Book* getBook(int idx) {
        if(idx < 0 || idx >= books.size()){
            throw std::invalid_argument("Book Model : idx out of bound");
        }
        return &books[idx];
    }
};

#endif // BOOKMODEL_H
