#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "qpushbutton.h"
#include "../Board.h"
#include "../Player.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    Chess::Board* board;
    Chess::Player* player1;
    Chess::Player* player2;

    Chess::Player* currentPlayer;
    QPushButton* previousButton;

    void SwitchPlayer();

    void CheckGameEnded();

private slots:
    void TilePressed();
};

#endif // MAINWINDOW_H


