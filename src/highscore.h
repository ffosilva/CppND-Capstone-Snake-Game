//
// Created by ffosilva on 29/04/2021.
//

#ifndef SNAKEGAME_HIGHSCORE_H
#define SNAKEGAME_HIGHSCORE_H

#include <string>

class HighScore {
private:
    const std::string _filename;
    int _highScore {-1};

    bool InitializeFile();
    bool WriteToFile(int highScore);
    bool ReadFromFile(int &highScore);
public:
    HighScore() = default;

    explicit HighScore(std::string_view filename);

    int GetHighScore();
    int UpdateHighScore(int newHighscore);
};


#endif //SNAKEGAME_HIGHSCORE_H
