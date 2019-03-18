#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <array>

class MyDialog : public QWidget
{
    Q_OBJECT

    const QString title;

protected:
    std::array<std::pair<QLabel*, QLineEdit*>, 3> components = { std::make_pair<>(new QLabel("Author"), new QLineEdit()),
                                                                 std::make_pair<>(new QLabel("Title"), new QLineEdit()),
                                                                 std::make_pair<>(new QLabel("Year"), new QLineEdit()) };
    QPushButton *btn;

    enum COMPONENTS_IDX {AUTHOR = 0, TITLE = 1, YEAR = 2};

public:
    explicit MyDialog(const QString& title, QWidget *parent = nullptr);

private slots:
    virtual void on_btn_clicked() = 0;

private:
    void setDialogProperties();
    void setComponents();
    QWidget* createInputGridPanel();
    QWidget* createButtonPanel();
    void createButton();
};

#endif // MYDIALOG_H
