#include "qkaddfiledialog.h"
#include "ui_qkaddfiledialog.h"

QKAddFileDIalog::QKAddFileDIalog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QKAddFileDIalog)
{
    ui->setupUi(this);
}

QKAddFileDIalog::~QKAddFileDIalog()
{
    delete ui;
}
