#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model* model, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void redButton_clicked();
    void blueButton_clicked();
    void startButton_clicked();
    void nightmareModeCheckBox_toggled(bool checked);
    void disableButtons();
    void enableButtons();
    void lightUpBlue();
    void lightUpRed();

private:
    Ui::MainWindow *ui;
    Model* model;
};
#endif // MAINWINDOW_H
