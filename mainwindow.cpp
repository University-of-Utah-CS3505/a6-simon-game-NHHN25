#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(Model* model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(model)
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

    this->setStyleSheet(
        "QPushButton#redButton {"
        "background-color: red;"
        "border: 2px solid black;"
        "border-radius: 5px;"
        "padding: 5px;"
        "}"
        "QPushButton#redButton:pressed {"
        "background-color: darkred;"
        "}"
        "QPushButton#redButton:hover {"
        "border: 2px solid darkred;"
        "}"
        "QPushButton#blueButton {"
        "border: 2px solid black;"
        "border-radius: 5px;"
        "background-color: blue;"
        "}"
        "QPushButton#blueButton:pressed {"
        "background-color: darkblue;"
        "}"
        "QPushButton#blueButton:hover {"
        "border: 2px solid darkblue;"
        "}"
        );
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redButton_clicked() {
    model->checkCurrentMove(Model::Color::Red);
    //std::cout << "Red button clicked" << std::endl;
}

void MainWindow::blueButton_clicked() {
    model->checkCurrentMove(Model::Color::Blue);
    //std::cout << "Blue button clicked" << std::endl;
}

void MainWindow::startButton_clicked() {
    model->startGame();
    ui->startButton->setEnabled(false);
    //std::cout << "start button clicked" << std::endl;
}

void MainWindow::nightmareModeCheckBox_toggled(bool checked) {
    // TODO: Implement
}

void MainWindow::disableButtons(){
    ui->redButton->setEnabled(false);
    ui->blueButton->setEnabled(false);
}

void MainWindow::enableButtons(){
    ui->redButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
}

void MainWindow::lightUpRed(){

}

void MainWindow::lightUpBlue(){

}
