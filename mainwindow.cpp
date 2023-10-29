#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Model* model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(model)
{
    ui->setupUi(this);


    connect(ui->redButton, &QPushButton::clicked, this, &MainWindow::redButton_clicked);
    connect(ui->blueButton, &QPushButton::clicked, this, &MainWindow::blueButton_clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startButton_clicked);
    connect(ui->nightmareModeCheckBox, &QCheckBox::toggled, this, &MainWindow::nightmareModeCheckBox_toggled);

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
}

void MainWindow::blueButton_clicked() {
    model->checkCurrentMove(Model::Color::Blue);
}

void MainWindow::startButton_clicked() {
    model->startGame();
}

void MainWindow::nightmareModeCheckBox_toggled(bool checked) {
    // TODO: Implement
}

