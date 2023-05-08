#include "MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    std::string letters = "abcdefgh";
    for(auto letter : letters) {
        for(int i = 1; i <= 8; ++i) {
            QString buttonName = letter + QString::number(i);
            QPushButton *button;
            button = MainWindow::findChild<QPushButton *>(buttonName);
            connect(button, SIGNAL(released()), this, SLOT(TilePressed()));
        }
    }

    previousButton = nullptr;
    board = new Chess::Board();
    player1 = new Chess::Player(Chess::PieceColor::eWhite);
    player2 = new Chess::Player(Chess::PieceColor::eBlack);
    currentPlayer = player1;
}

void MainWindow::TilePressed() {
    if (!previousButton) {
        previousButton = (QPushButton *)sender();
    }
    else {
        QPushButton *button;
        button = (QPushButton *) sender();

        std::string startTileName;
        startTileName = previousButton->objectName().toStdString();

        std::string endTileName;
        endTileName = button->objectName().toStdString();

        currentPlayer->SetCurrentMove(startTileName,endTileName);

        if (board->TakeNextMove(*currentPlayer)) {
            button->setIcon(previousButton->icon());
            previousButton->setIcon(QIcon());

            CheckGameEnded();
            SwitchPlayer();
            previousButton = nullptr;
        }
        else {
            previousButton = (QPushButton *)sender();
        }
    }
}

void MainWindow::CheckGameEnded() {
    if (board->IsCheckmate()) {
        QLabel *label;
        label = new QLabel("Checkmate", ui->centralwidget);

        QFont font("Verdana", 24, QFont::Bold, true);
        label->setFont(font);
        label->setStyleSheet("color: black");
        label->setAlignment(Qt::AlignCenter);
        label->resize(300, 100);
        label->move((ui->centralwidget->width() - label->width()) / 2,
                    (ui->centralwidget->height() - label->height()) / 2);

        QWidget *shadowWidget;
        shadowWidget = new QWidget(ui->centralwidget);
        shadowWidget->setGeometry(0, 0, 700, 700);
        shadowWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.6);");
        shadowWidget->show();
        label->show();
    }
}

void MainWindow::SwitchPlayer() {
    if (currentPlayer == player1) {
        currentPlayer = player2;
    }
    else if (currentPlayer == player2) {
        currentPlayer = player1;
    }
}

MainWindow::~MainWindow() {
    delete ui;
}


