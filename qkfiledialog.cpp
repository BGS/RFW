#include "qkfiledialog.h"
QKFileDialog::QKFileDialog(QWidget *parent) :
    QWidget(parent)
{


}

QStringList QKFileDialog::openFiles(void)
{
    QStringList filenames = QFileDialog::getOpenFileNames(
                this, tr("Open Files"), QDir::currentPath(),
                tr("All Files (*.*)") );
    if ( !filenames.isEmpty() )
        qDebug( filenames.join(":").toAscii() );
        return  filenames;

}

void QKFileDialog::watchedFilesStore(QStringList file_paths)
{
    QSettings settings("QKFileWatchDT", "qkfw_settings");
    settings.beginGroup("Watched Files");

    for (QStringList::iterator it = file_paths.begin(); it != file_paths.end(); ++it)
    {
        QFileInfo file(*it);
        if (file.exists())
        {
            QString value = file.absoluteFilePath();
            value.append(":0");
            qDebug() << value;
            settings.setValue(file.fileName(), value);
        }

    }
    settings.endGroup();

}
