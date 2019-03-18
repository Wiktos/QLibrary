#include "mydialog.h"

MyDialog::MyDialog(const QString& title, QWidget *parent) : QWidget(parent), title(title)
{
    setDialogProperties();
    setComponents();
}

void MyDialog::setDialogProperties()
{
    setWindowTitle(title);
}

void MyDialog::setComponents()
{
    QWidget *inputGridPanel = createInputGridPanel();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(inputGridPanel);

    QWidget *btnPanel = createButtonPanel();

    mainLayout->addWidget(btnPanel);
    setLayout(mainLayout);
}

QWidget* MyDialog::createInputGridPanel()
{
    QGridLayout *gridLayout = new QGridLayout;

    for(unsigned int i = 0; i < components.size(); i++) {
        auto label = components[i].first;
        auto lineEdit = components[i].second;
        gridLayout->addWidget(label, static_cast<int>(i), 0);
        gridLayout->addWidget(lineEdit, static_cast<int>(i), 1);
    }

    QWidget *retv = new QWidget;
    retv ->setLayout(gridLayout);
    return retv;
}

QWidget* MyDialog::createButtonPanel()
{
    QWidget *retv = new QWidget;
    createButton();

    QHBoxLayout *btnLayout = new QHBoxLayout;

    int spacerWidth = static_cast<int>(size().width() * 0.15);
    btnLayout->addItem(new QSpacerItem(spacerWidth, 0, QSizePolicy::Expanding));
    btnLayout->addWidget(btn);
    btnLayout->addItem(new QSpacerItem(spacerWidth, 0, QSizePolicy::Expanding));

    retv->setLayout(btnLayout);
    return retv;
}

void MyDialog::createButton()
{
    btn = new QPushButton("OK");
    connect(btn, SIGNAL(clicked()), this, SLOT(on_btn_clicked()));
}
