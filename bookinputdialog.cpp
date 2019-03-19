#include "bookinputdialog.h"

BookInputDialog::BookInputDialog(BookModel *modified, QWidget *parent) : MyDialog("Library Input New Book Dialog", parent), modified(modified)
{
}

void BookInputDialog::show() {
    //clear previously setted values
    for(auto comp : components) {
        comp.second->setText("");
    }
    QWidget::show();
}

void BookInputDialog::on_btn_clicked()
{
    QString author = components[AUTHOR].second->text();
    QString title = components[TITLE].second->text();
    QString year = components[YEAR].second->text();

    try {
        Book newBook(author, title, year);
        modified->append(newBook);
        this->close();
    } catch (std::invalid_argument& ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        return;
    }
}
