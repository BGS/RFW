#ifndef QKMAINWINDOW_H
#define QKMAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <QFileSystemWatcher>
#include <QListWidgetItem>
#include <QProcess>

#include "qkfiledialog.h"

namespace Ui {
class QKMainWindow;
}

class QKMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QKMainWindow(QWidget *parent = 0);
    ~QKMainWindow();
    void setWatchedFiles(void);

private slots:
    void fileWatchSigHandler(QString ch_file);
    void openFile(QListWidgetItem*);

    void on_actionAdd_file_triggered();


private:
    Ui::QKMainWindow *ui;
    QFileSystemWatcher* watcher;

};

#endif // QKMAINWINDOW_H
