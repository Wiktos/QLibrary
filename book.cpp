#include "book.h"

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.getAuthor().toStdString() << '\n';
    os << book.getTitle().toStdString() << '\n';
    os << book.getYear().toStdString() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    std::string author;
    std::string title;
    std::string year;

    std::getline(is, author);
    std::getline(is, title);
    std::getline(is, year);

    book.author = QString::fromUtf8(author.c_str());
    book.title = QString::fromUtf8(title.c_str());
    book.year = QString::fromUtf8(year.c_str());

    return is;
}

Book::Book(const QString &author, const QString &title, const QString &year)
    : author(author), title(title), year(year)
{
    if(checkYear(year)) {
        throw std::invalid_argument("Book invalid year passed");
    }
}

bool Book::checkYear(const QString& year){
    bool ok;
    int val = year.toInt(&ok);
    return (!ok || val < 0 || val > 9999);
}
