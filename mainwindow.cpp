#include <fstream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

const std::string MainWindow::DATA_FILE_PATH = "data.txt";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    inputDialog(&model, this),
    editDialog(this),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resizeDialogWindows();

    //read data
    std::ifstream fs(DATA_FILE_PATH);
    fs >> model;

    setBooksTableViewProp();
    connectFilter();
}

MainWindow::~MainWindow()
{
    delete ui;
    //write data
    std::ofstream fs(DATA_FILE_PATH);
    fs << model;
}

void MainWindow::on_delete_btn_clicked()
{
    std::vector<int> indices = getSelectedRowsIdx();
    std::sort(indices.begin(), indices.end(), std::greater<int>());

    for(auto idx : indices) {
        model.remove(idx);
    }
}

std::vector<int> MainWindow::getSelectedRowsIdx()
{
    QTableView *tv = ui->books_tv;
    QItemSelectionModel *selectedModels = tv->selectionModel();
    QModelIndexList selectedRows = selectedModels->selectedRows();

    std::vector<int> retv;
    for(auto modelIdx : selectedRows) {
        retv.push_back(modelIdx.row());
    }

    return retv;
}

void MainWindow::on_add_btn_clicked()
{
    inputDialog.show();
}

void MainWindow::on_clear_btn_clicked()
{
    ui->title_le->clear();
    ui->author_le->clear();
    ui->year_sb->setValue(0);
}

void MainWindow::resizeDialogWindows()
{
    const float scaleFactor= 0.4f;
    int width = static_cast<int>(size().width() * scaleFactor);
    int height = static_cast<int>(size().height() * scaleFactor);

    inputDialog.resize(width, height);
    editDialog.resize(width, height);
}

void MainWindow::setBooksTableViewProp()
{
    QTableView *booksTv = ui->books_tv;

    proxyModel.setSourceModel(&model);
    booksTv->setModel(&proxyModel);

    booksTv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    booksTv->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color: gray;}");
    booksTv->verticalHeader()->setVisible(false);
}

void MainWindow::connectFilter()
{
    connect(ui->title_le, SIGNAL(textChanged(QString)), &proxyModel, SLOT(setTitleFilter(QString)));
    connect(ui->author_le, SIGNAL(textChanged(QString)), &proxyModel, SLOT(setAuthorFilter(QString)));
    connect(ui->year_sb, SIGNAL(valueChanged(QString)), &proxyModel, SLOT(setYearFilter(QString)));
}

void MainWindow::on_books_tv_doubleClicked(const QModelIndex &index)
{
    Book *selected = model.getBook(index.row());
    editDialog.setBookToModification(selected);
    editDialog.show();
}
