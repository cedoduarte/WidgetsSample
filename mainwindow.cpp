#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTreeWidgetItem *headerItem = new QTreeWidgetItem;
    headerItem->setText(0, "Personas");
    ui->treeWidget->setHeaderItem(headerItem);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Nombre","Edad","Salario"});
    ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);
    ui->tableWidget->setSelectionMode(QTableWidget::SingleSelection);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);

    addPerson(Persona("Carlos",27,50000.0));
    addPerson(Persona("Ana",20,60000.0));
    addPerson(Persona("Gabriel",33,40000.0));
    addPerson(Persona("Luis",45,30000.0));
    addPerson(Persona("Juan",22,20000.0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPerson(const Persona &person)
{
    ui->comboBox->addItem(QIcon(":/img/person.png"), person.nombre(), QVariant::fromValue(person));

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(person.nombre());
    item->setIcon(QIcon(":/img/person.png"));
    item->setData(Qt::UserRole, QVariant::fromValue(person));
    ui->listWidget->addItem(item);

    QTreeWidgetItem *topItem = new QTreeWidgetItem;
    QTreeWidgetItem *nombreItem = new QTreeWidgetItem;
    QTreeWidgetItem *edadItem = new QTreeWidgetItem;
    QTreeWidgetItem *salarioItem = new QTreeWidgetItem;
    topItem->setIcon(0, QIcon(":/img/person.png"));
    topItem->setText(0, person.nombre());
    topItem->setData(0, Qt::UserRole, QVariant::fromValue(person));
    nombreItem->setText(0, person.nombre());
    edadItem->setText(0, QString::number(person.edad()));
    salarioItem->setText(0, QString::number(person.salario()));
    topItem->addChild(nombreItem);
    topItem->addChild(edadItem);
    topItem->addChild(salarioItem);
    ui->treeWidget->addTopLevelItem(topItem);

    QTableWidgetItem *nombreItemTbl = new QTableWidgetItem;
    QTableWidgetItem *edadItemTbl = new QTableWidgetItem;
    QTableWidgetItem *salarioItemTbl = new QTableWidgetItem;
    nombreItemTbl->setText(person.nombre());
    edadItemTbl->setText(QString::number(person.edad()));
    salarioItemTbl->setText(QString::number(person.salario()));
    nombreItemTbl->setIcon(QIcon(":/img/person.png"));
    nombreItemTbl->setData(Qt::UserRole, QVariant::fromValue(person));
    const int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row, 0, nombreItemTbl);
    ui->tableWidget->setItem(row, 1, edadItemTbl);
    ui->tableWidget->setItem(row, 2, salarioItemTbl);
}

void MainWindow::on_comboBox_activated(int index)
{
    displayPerson(ui->comboBox->itemData(index).value<Persona>());
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    displayPerson(ui->listWidget->item(index.row())->data(Qt::UserRole).value<Persona>());
}

void MainWindow::displayPerson(const Persona &person)
{
    ui->nombreLineEdit->setText(person.nombre());
    ui->edadLineEdit->setText(QString::number(person.edad()));
    ui->salarioLineEdit->setText(QString::number(person.salario()));
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    (void) column;
    if (item->childCount() >= 3)
    {
        displayPerson(item->data(0, Qt::UserRole).value<Persona>());
    }
}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    displayPerson(ui->tableWidget->item(index.row(), 0)->data(Qt::UserRole).value<Persona>());
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

