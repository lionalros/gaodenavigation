#include "startupform.h"
#include "ui_startupform.h"

startupForm::startupForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startupForm)
{
    ui->setupUi(this);
}

startupForm::~startupForm()
{
    delete ui;
}
