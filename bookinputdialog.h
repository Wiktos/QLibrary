#ifndef BOOKINPUTDIALOG_H
#define BOOKINPUTDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <array>

#include "bookmodel.h"
#include "mydialog.h"

class BookInputDialog : public MyDialog
{
    Q_OBJECT

    BookModel *modified;

public:
    explicit BookInputDialog(BookModel *modified, QWidget *parent = nullptr);

    void show();

private slots:
    void on_btn_clicked() override;
};

#endif // BOOKINPUTDIALOG_H
