#include "game_over.h"
#include "ui_game_over.h"

game_over::game_over(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::game_over)
{
    ui->setupUi(this);

    this->setVisible(false);
}

game_over::~game_over()
{
    delete ui;
}

