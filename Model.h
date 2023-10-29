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

signals:

    /**
     * @brief gameOver
     */
    void gameOver();

    /**
     * @brief succesfulPattern
     */
    void succesfulPattern();

    /**
     * @brief showNextIteration
     */
    void showNextIteration();

private:
    QVector<Color> currentPattern;
    QTimer gameSpeed;
    int currentIteration;
};


#endif // MODEL_H
