#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "persona.h"

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class QTreeWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
private slots:
    void on_comboBox_activated(int index);
    void on_listWidget_clicked(const QModelIndex &index);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_actionSalir_triggered();
private:
    void displayPerson(const Persona &person);
    void addPerson(const Persona &person);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
