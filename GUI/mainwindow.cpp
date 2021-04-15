#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

int betAmount = 0;
int depositedMoney = 200;
int guess = 0;
int correctGuess = -1;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Set the labels display value

    updateLabels();
    connect(ui->betBtn, SIGNAL(released()), this, SLOT(BtnPressed()));
}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::generateRandomNumber() {
    QRandomGenerator generator;
    int number = generator() % 11;
    return number;
}
void determinWinLose() {

}

void MainWindow::updateLabels() {
    ui->correctNumberLabel->setText("Answer: " + QString::number(correctGuess));
    ui->guessLabelDisplay->setText(QString::number(guess));
    ui->depositMoneyLabel->setText("Deposited amount: " + QString::number(depositedMoney));
    ui->currentBetLabel->setText("Current bet: " + QString::number(betAmount));
}

void MainWindow::BtnPressed() {
    correctGuess = generateRandomNumber();
    guess = ui->guessInput->toPlainText().toInt();
    betAmount = ui->betInput->toPlainText().toInt();
    updateLabels();
}
