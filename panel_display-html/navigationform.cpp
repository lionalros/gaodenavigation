#include "navigationform.h"
#include "ui_navigationform.h"

NavigationForm::NavigationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavigationForm)
{
    ui->setupUi(this);
}

NavigationForm::~NavigationForm()
{
    delete ui;
}
