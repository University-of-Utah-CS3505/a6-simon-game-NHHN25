#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



/**
 * @authors Names: Nam Nguyen and Thomas Kuhrke Limia
 * @authors GitHubs: NHHN25 and T-K-L
 *
 * @title Assignment 6: Qt Simon Game
 *
 * @brief The MainWindow class shows the user in a Graphical User Interface every visual element from the operations
 * performed in model, and includes methods to manipulate said elements. "Simon Says" consists of the game showing
 * a pattern, and the player replicating it, with the pattern getting longer the more patterns the player gets correctly.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor.
     * @param model a model object.
     * @param parent a QWidget object.
     */
    MainWindow(Model* model, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * @brief Handles the event when the red button is clicked.
     */
    void redButton_clicked();
    /**
     * @brief Handles the event when the blue button is clicked.
     */
    void blueButton_clicked();
    /**
     * @brief Initiates the game sequence when the start button is clicked.
     */
    void startButton_clicked();
    /**
     * @brief Toggles the game's nightmare mode based on the checkbox state.
     * @param checked Indicates the checkbox's state: true if checked, false otherwise.
     */
    void nightmareModeCheckBox_toggled(bool checked);
    /**
     * @brief Deactivates the red and blue buttons to prevent user input.
     */
    void disableButtons();
    /**
     * @brief Reactivates the red and blue buttons to allow user input.
     */
    void enableButtons();
    /**
     * @brief Emulates the lighting up effect for the blue button.
     */
    void lightUpBlue();
    /**
     * @brief Emulates the lighting up effect for the red button.
     */
    void lightUpRed();
    /**
     * @brief Updates the game's progress bar based on the progress percentage calculated in the Model.
     * @param The percentage of progress to be displayed on the progress bar.
     */
    void updateProgress(int progressPercentage);
    /**
     * @brief Displays a visual indication that the game is over.
     */
    void displayGameOver();

private:
    Ui::MainWindow *ui;
    Model *model;
    bool nightmareMode;
    void initProgressBar();
};
#endif // MAINWINDOW_H
