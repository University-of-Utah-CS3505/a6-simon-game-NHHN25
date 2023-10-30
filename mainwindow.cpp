#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(Model* model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(model)
{
    ui->setupUi(this);
    connect(ui->redButton, &QPushButton::clicked, this, &MainWindow::redButton_clicked);
    connect(ui->blueButton, &QPushButton::clicked, this, &MainWindow::blueButton_clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startButton_clicked);
    connect(ui->nightmareModeCheckBox, &QCheckBox::toggled, this, &MainWindow::nightmareModeCheckBox_toggled);
    connect(model, &Model::startPatternView, this, &MainWindow::disableButtons);
    connect(model, &Model::endPatternView, this, &MainWindow::enableButtons);
    connect(model, &Model::isRed, this, &MainWindow::lightUpRed);
    connect(model, &Model::isBlue, this, &MainWindow::lightUpBlue);
    connect(model, &Model::updateProgressBar, this, &MainWindow::updateProgress);
    connect(model, &Model::gameOver, this, &MainWindow::displayGameOver);

    this->setStyleSheet("background-color: yellow;");
    this->setWindowTitle("Simon Game: Emoji");
    ui->gameOverLabel->setVisible(false);
    initProgressBar();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::displayGameOver(){
    ui->gameOverLabel->setVisible(true);
    ui->startButton->setEnabled(true);
    ui->startButton->setVisible(true);
    ui->nightmareModeCheckBox->setVisible(true);
    ui->nightmareModeCheckBox->setEnabled(true);
    QString originalStyleSheet = ui->gameOverLabel->styleSheet();

    if(nightmareMode){
        QPixmap pixmap(":img/img/djopen.png");
        ui->gameOverLabel->setPixmap(pixmap);
    } else {
        ui->gameOverLabel->setStyleSheet(originalStyleSheet);
    }
}
void MainWindow::initProgressBar(){
    ui->progressBar->setValue(0);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setTextVisible(false);
}
void MainWindow::redButton_clicked() {
    model->checkCurrentMove(Model::Color::Red);

    if(nightmareMode){
        QPoint bluePos = ui->blueButton->pos();
        ui->blueButton->move(ui->redButton->pos());
        ui->redButton->move(bluePos);
    }
}

void MainWindow::blueButton_clicked() {
    model->checkCurrentMove(Model::Color::Blue);

    if(nightmareMode){
        QPoint bluePos = ui->blueButton->pos();
        ui->blueButton->move(ui->redButton->pos());
        ui->redButton->move(bluePos);
    }
}

void MainWindow::startButton_clicked() {
    model->startGame();
    ui->startButton->setEnabled(false);
    ui->startButton->setVisible(false);
    ui->gameOverLabel->setVisible(false);
    ui->nightmareModeCheckBox->setVisible(false);
    ui->nightmareModeCheckBox->setEnabled(false);
}

void MainWindow::nightmareModeCheckBox_toggled(bool checked) {
    nightmareMode = checked;
}

void MainWindow::disableButtons(){
    ui->redButton->setEnabled(false);
    ui->blueButton->setEnabled(false);
    ui->progressBar->setValue(100);
}

void MainWindow::enableButtons(){
    ui->redButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
    ui->progressBar->setValue(0);
}

void MainWindow::lightUpRed(){
    QString originalStyleSheet = ui->redButton->styleSheet();
    ui->redButton->setStyleSheet("QPushButton {"
                                 "background-color: rgb(255,150,150);"
                                 "border: 3px solid black;"
                                 "width: 50px;"
                                 "height: 50px;"
                                 "border-radius: 25px;"
                                 "}");

    QTimer::singleShot(300, this, [this, originalStyleSheet]() { ui->redButton->setStyleSheet(originalStyleSheet); });
}

void MainWindow::lightUpBlue(){
    QString originalStyleSheet = ui->blueButton->styleSheet();
    ui->blueButton->setStyleSheet("QPushButton {"
                                  "background-color: rgb(100,100,255);"
                                  "border: 3px solid black;"
                                  "width: 50px;"
                                  "height: 50px;"
                                  "border-radius: 25px;"
                                  "}");

    QTimer::singleShot(300, this, [this, originalStyleSheet]() { ui->blueButton->setStyleSheet(originalStyleSheet);} );
}

void MainWindow::updateProgress(int progressPercentage){
    ui->progressBar->setValue(progressPercentage);
}

