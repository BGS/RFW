#ifndef QKFILEDIALOG_H
#define QKFILEDIALOG_H

#include <QWidget>
#include <QFileDialog>
#include <QSettings>
#include <QDebug>

class QKFileDialog : public QWidget
{
    Q_OBJECT
public:
    explicit QKFileDialog(QWidget *parent = 0);
    QStringList openFiles(void);
    void watchedFilesStore(QStringList file_paths);
    
signals:
    
public slots:
    
};

#endif // QKFILEDIALOG_H
