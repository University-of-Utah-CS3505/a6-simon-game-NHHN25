#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QColor>
#include <QVector>
#include <QTimer>

/**
 * @authors Names: Nam Nguyen and Thomas Kuhrke Limia
 * @authors GitHubs: NHHN25 and T-K-L
 *
 * @title Assignment 6: Qt Simon Game
 *
 * @brief The Model class performs operations needed for a "Simon-Says" type of game to function and lets
 * the view know when the required data is ready for the view to use/show. "Simon Says" consists of the game
 * showing a pattern, and the player replicating it, with the pattern getting longer the more patterns the player
 * gets correctly.
 */
class Model : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Model constructor
     * @param parent a QObject
     */
    explicit Model(QObject *parent = nullptr);

    /**
     * @brief The Color enum an enumerator to represent Red and Blue as Color type.
     */
    enum class Color {Red, Blue};

public slots:
    /**
     * @brief startGame sets private variables to its default, and calls necessary methods to start the game.
     */
    void startGame();

    /**
     * @brief checkCurrentMove checks if the move of the player is correct, emitting a game over signal if it isn't. It also
     * calls the method that generates the next level if the player finishes the pattern.
     * @param currentColor the color of the button the player clicked on.
     */
    void checkCurrentMove(Color currentColor);

    /**
     * @brief generateNextLevel calls a method that returns a random color, and puts it in the list that contains the current pattern.
     */
    void generateNextLevel();

    /**
     * @brief increaseGameSpeed increases the speed of the game based on the size of the pattern and a constant.
     */
    void increaseGameSpeed();

    /**
     * @brief showNextLevel emits a signal to disable the game buttons, show the pattern the player has to complete, and finally enable the buttons
     */
    void showNextLevel();

    /**
     * @brief isRedOrBlue takes a color, and emits a signal depending on the color.
     * @param currentColor a color that is either blue or red.
     */
    void isRedOrBlue(Color currentColor);

    /**
     * @brief randomColorGenerator generates a random number, assigns it to a color, and returns it.
     * @return a color (either red or blue)
     */
    Color randomColorGenerator();

signals:

    /**
     * @brief gameOver tells the view that the player clicked the wrong button.
     */
    void gameOver();

    /**
     * @brief startPatternView tells the view that the pattern will begin showing.
     */
    void startPatternView();

    /**
     * @brief endPatternView tells the view that the pattern has been shown already.
     */
    void endPatternView();

    /**
     * @brief isRed tells the view that the current color to show is red.
     */
    void isRed();

    /**
     * @brief isBlue tells the view that the current color to show is blue.
     */
    void isBlue();

    /**
     * @brief updateProgressBar tells the view the current progress of the player as a percentage.
     * @param percentage the percentage that the player has accomplished so far in the pattern.
     */
    void updateProgressBar(int percentage);

private:
    QVector<Color> currentPattern;
    int gameSpeed;
    int currentIteration;
};


#endif // MODEL_H
