#include "qkmainwindow.h"
#include "ui_qkmainwindow.h"

QKMainWindow::QKMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QKMainWindow)
{
    watcher = new QFileSystemWatcher(this);

    connect(watcher,SIGNAL(fileChanged(QString)),
                  this, SLOT(fileWatchSigHandler(QString)));

    ui->setupUi(this);
    connect(ui->watchedFileQLW, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(openFile(QListWidgetItem*)));

    setWatchedFiles();


}

QKMainWindow::~QKMainWindow()
{
    delete ui;
    delete watcher;
}


void QKMainWindow::on_actionAdd_file_triggered()
{
    QKFileDialog t;
    QStringList paths = t.openFiles();
    t.watchedFilesStore(paths);
    setWatchedFiles();

    //qDebug() <<  paths;


}

void QKMainWindow::setWatchedFiles(void)
{
    ui->watchedFileQLW->clear();
    QSettings settings("QKFileWatchDT", "qkfw_settings");
    settings.beginGroup("Watched Files");

    QStringList keys = settings.allKeys();
    for (QStringList::iterator it = keys.begin(); it != keys.end(); ++it)
    {
        QString value = settings.value(*it).toString();
        QStringList pv =  value.split(":");

        if (pv[1] != "0")
        {
            QString mod_file = *it;
            mod_file.append("  (modified)");
            watcher->addPath(pv[0]);
            ui->watchedFileQLW->addItem(mod_file);
            qDebug() << watcher->files();


        }else{
            watcher->addPath(pv[0]);
            ui->watchedFileQLW->addItem(*it);
            qDebug() << watcher->files();

        }


    }


    settings.endGroup();

}

void QKMainWindow::fileWatchSigHandler(QString ch_file)
{
    QSettings settings("QKFileWatchDT", "qkfw_settings");
    settings.beginGroup("Watched Files");
    QFileInfo file(ch_file);
    if (file.exists())
    {
        QString value = file.absoluteFilePath();
        value.append(":1");
        settings.setValue(file.fileName(), value);

    }
    settings.endGroup();

    setWatchedFiles();

    qDebug() << "fch: " << ch_file;
}

void QKMainWindow::openFile(QListWidgetItem* item)
{
    QSettings settings("QKFileWatchDT", "qkfw_settings");
    settings.beginGroup("Watched Files");
    QProcess process;
    QString key = item->data(0).toString();
    QString fpath = settings.value(key).toString();

    process.startDetached("xdg-open", QStringList() << fpath.split(":")[0]);

    settings.endGroup();

}
