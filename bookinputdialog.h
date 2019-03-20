#ifndef BOOKINPUTDIALOG_H
#define BOOKINPUTDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <array>

#include "bookmodel.h"
#include "mydialog.h"

class BookInputDialog final : public MyDialog
{
    Q_OBJECT

    BookModel *modified;

public:
    explicit BookInputDialog(BookModel *modified, QWidget *parent = nullptr);

    void show();

    ~BookInputDialog() override = default;

private slots:
    void on_btn_clicked() override;
};

#endif // BOOKINPUTDIALOG_H
