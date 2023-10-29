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

public slots:
    /**
     * @brief startGame
     */
    void startGame();

    /**
     * @brief checkMove
     * @param currentColor
     */
    void checkCurrentMove(QColor currentColor);

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
     * @brief UpdateNextLevel
     */
    void UpdateNextLevel(QVector<QColor>);

private:
    QVector<QColor> currentPattern;
    QTimer gameSpeed;
    int index;
};


#endif // MODEL_H
