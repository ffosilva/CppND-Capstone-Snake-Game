//
// Created by ffosilva on 29/04/2021.
//

#include <fstream>
#include "highscore.h"

int HighScore::GetHighScore() {
    if (_highScore < 0 && !_filename.empty()) {
        ReadFromFile(_highScore);
    } else if (_highScore < 0) {
        _highScore = 0;
    }

    return _highScore;
}

int HighScore::UpdateHighScore(int newHighScore) {
    if (newHighScore > _highScore) {
        _highScore = newHighScore;
        WriteToFile(newHighScore);
    }

    return _highScore;
}

HighScore::HighScore(std::string_view filename) : _filename(filename) {
    // try to open the file
    std::ifstream highScoreFile(_filename);
    if (highScoreFile.fail()) {
        InitializeFile();
    } else {
        highScoreFile.close();
    }
}

bool HighScore::InitializeFile() {
    std::ofstream highScoreFile(_filename);
    if (highScoreFile.fail()) {
        return false;
    }

    highScoreFile << 0;
    highScoreFile.close();

    return true;
}

bool HighScore::WriteToFile(int highScore) {
    if (_filename.empty()) {
        return false;
    }

    std::ofstream highScoreFile(_filename);
    highScoreFile << highScore;
    highScoreFile.close();

    return true;
}

bool HighScore::ReadFromFile(int &highScore) {
    if (_filename.empty()) {
        return false;
    }

    std::ifstream highScoreFile(_filename);
    highScoreFile >> highScore;
    highScoreFile.close();

    return true;
}
