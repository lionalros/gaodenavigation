#ifndef STARTUPFORM_H
#define STARTUPFORM_H

#include <QWidget>

namespace Ui {
class startupForm;
}

class startupForm : public QWidget
{
    Q_OBJECT

public:
    explicit startupForm(QWidget *parent = nullptr);
    ~startupForm();

private:
    Ui::startupForm *ui;
};

#endif // STARTUPFORM_H
