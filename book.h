#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <iostream>

class Book
{
    QString author;
    QString title;
    QString year;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);

public:
    static int numberOfAttributes() { return 3; }

    Book(const QString &author, const QString &title, const QString &year);

    //getters
    const QString& getAuthor() const { return author; }
    const QString& getTitle() const { return title; }
    const QString& getYear() const { return year; }

    //setters
    void setAuthor(const QString& author) { this->author = author; }
    void setTitle(const QString& title) { this->title = title; }
    void setYear(const QString& year) {
        if(checkYear(year)) {
            throw std::invalid_argument("Book invalid year passed");
        }
        this->year = year;
    }

private:
    bool checkYear(const QString& year);
};

#endif // BOOK_H
