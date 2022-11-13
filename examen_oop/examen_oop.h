#pragma once

#include <QtWidgets/QWidget>
#include "ui_examen_oop.h"

class examen_oop : public QWidget
{
    Q_OBJECT

public:
    examen_oop(QWidget *parent = Q_NULLPTR);

private:
    Ui::examen_oopClass ui;
};
