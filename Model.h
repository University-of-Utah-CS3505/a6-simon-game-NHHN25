#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QColor>
#include <QVector>
#include <QTimer>

class Model : public QObject {
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    enum class Color {Red, Blue};

public slots:
    /**
     * @brief startGame
     */
    void startGame();

    /**
     * @brief checkMove
     * @param currentColor
     */
    void checkCurrentMove(Color currentColor);

    /**
     * @brief addMove
     * @param randomColor
     */
    void generateNextLevel();

    /**
     * @brief increaseGameSpeed
     */
    void increaseGameSpeed();

    /**
     * @brief showNextLevel
     */
    void showNextLevel();

    /**
     * @brief isRedOrBlue
     */
    void isRedOrBlue(Color);

    /**
     * @brief randomColorGenerator
     */
    Color randomColorGenerator();

signals:

    /**
     * @brief gameOver
     */
    void gameOver();

    /**
     * @brief startPatternView
     */
    void startPatternView();

    /**
     * @brief endPatternView
     */
    void endPatternView();

    /**
     * @brief isRed
     */
    void isRed();

    /**
     * @brief isBlue
     */
    void isBlue();

    void updateProgressBar(int);

private:
    QVector<Color> currentPattern;
    int gameSpeed;
    int currentIteration;
};


#endif // MODEL_H
