#ifndef NAVIGATIONFORM_H
#define NAVIGATIONFORM_H

#include <QWidget>

namespace Ui {
class NavigationForm;
}

class NavigationForm : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationForm(QWidget *parent = nullptr);
    ~NavigationForm();

private:
    Ui::NavigationForm *ui;
};

#endif // NAVIGATIONFORM_H
