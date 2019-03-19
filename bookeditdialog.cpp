#include "bookeditdialog.h"

BookEditDialog::BookEditDialog(QWidget *parent) : MyDialog("Library Edit Book Dialog", parent)
{
}

void BookEditDialog::show() {
    //clear previously setted values
    components[AUTHOR].second->setText(modified->getAuthor());
    components[TITLE].second->setText(modified->getTitle());
    components[YEAR].second->setText(modified->getYear());

    QWidget::show();
}

void BookEditDialog::setBookToModification(Book *book) {
    if(!book) {
        throw std::invalid_argument("BookEditDialog : Book pointer was not set");
    }
    modified = book;
}

void BookEditDialog::on_btn_clicked()
{
    QString author = components[AUTHOR].second->text();
    QString title = components[TITLE].second->text();
    QString year = components[YEAR].second->text();

    try {
        modified->setAuthor(author);
        modified->setTitle(title);
        modified->setYear(year);
        this->close();
    } catch (std::invalid_argument& ex) {
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", ex.what());
        return;
    }
}
