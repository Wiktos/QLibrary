#ifndef BOOKEDITDIALOG_H
#define BOOKEDITDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <array>

#include "book.h"
#include "mydialog.h"

class BookEditDialog final : public MyDialog
{
    Q_OBJECT

    Book *modified;

public:
    explicit BookEditDialog(QWidget *parent = nullptr);

    void show();
    void setBookToModification(Book *book);

    ~BookEditDialog() override = default;

private slots:
    void on_btn_clicked() override;

};

#endif // BOOKEDITDIALOG_H
