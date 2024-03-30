#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <QDialog>

namespace Ui {
class game_over;
}

class game_over : public QDialog
{
    Q_OBJECT

public:
    explicit game_over(QWidget *parent = nullptr);
    ~game_over();

private slots:
               // void on_label_linkActivated(const QString &link);

private:
    Ui::game_over *ui;
};

#endif // GAME_OVER_H
