#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "bookinputdialog.h"
#include "bookeditdialog.h"
#include "bookfilterproxymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    static const std::string DATA_FILE_PATH;

    BookModel model;
    BookFilterProxyModel proxyModel;
    BookInputDialog inputDialog;
    BookEditDialog editDialog;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_delete_btn_clicked();
    void on_add_btn_clicked();
    void on_clear_btn_clicked();
    void on_books_tv_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    void setBooksTableViewProp();
    void connectFilter();
    std::vector<int> getSelectedRowsIdx();
};

#endif // MAINWINDOW_H
