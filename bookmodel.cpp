#include "bookmodel.h"

std::ostream& operator<<(std::ostream& os, const BookModel& bookModel) {
    for(auto book : bookModel.books) {
        os << book;
    }
    return os;
}

std::istream& operator>>(std::istream& is, BookModel& bookModel) {
    while(!is.eof()) {
        Book curr("", "", "0");
        is >> curr;
        bookModel.append(curr);
    }

    //removing last empty record
    bookModel.remove(bookModel.books.size() - 1);

    return is;
}

BookModel::BookModel(QObject *parent) : QAbstractTableModel(parent)
{}

QVariant BookModel::data(const QModelIndex &index, int role) const {
   if (role != Qt::DisplayRole && role != Qt::EditRole) {
       return QVariant();
   }

   const auto &book= books[index.row()];

   switch (index.column()) {
   case 0: return book.getAuthor();
   case 1: return book.getTitle();
   case 2: return book.getYear();
   default: return QVariant();
   };
}

QVariant BookModel::headerData(int section, Qt::Orientation orientation, int role) const {
   if (orientation != Qt::Horizontal || role != Qt::DisplayRole) {
       return QVariant();
   }

   switch (section) {
   case 0: return "Author";
   case 1: return "Title";
   case 2: return "Year";
   default: return QVariant();
   }
}

void BookModel::append(const Book &book) {
   beginInsertRows(QModelIndex(), books.count(), books.count());
   books.append(book);
   endInsertRows();
}

void BookModel::remove(const int& idx) {
    beginRemoveRows(QModelIndex(), idx, idx);
    books.removeAt(idx);
    endRemoveRows();
}
