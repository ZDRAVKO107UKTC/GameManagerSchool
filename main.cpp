#include <iostream>

class GameManager {
    private:
        bool isPaused;

    GameManager() : isPaused(false) {
        std::cout << "GameManager initialized.\n";
    }

public:
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    static GameManager& getInstance() {
        static GameManager instance;
        return instance;
    }

    void togglePause() {
        isPaused = !isPaused;
        if (isPaused) {
            std::cout << "[Game]: Game is now Paused!\n";
        } else {
            std::cout << "[Game]: Game is now Running!\n";
        }
    }

    bool getIsPaused() const {
        return isPaused;
    }
};

int main() {
    GameManager& gm1 = GameManager::getInstance();
    GameManager& gm2 = GameManager::getInstance();

    std::cout << "\nCalling togglePause() from gm1...\n";
    gm1.togglePause();

    std::cout << "Checking state from gm2: ";
    if (gm2.getIsPaused()) {
        std::cout << "Game is Paused!\n";
    } else {
        std::cout << "Game is Running!\n";
    }

    std::cout << "\n";

    if (&gm1 == &gm2) {
        std::cout << "SUCCESS: Both variables point to the same GameManager instance.\n";
    } else {
        std::cout << "FAILURE: Variables point to different instances!\n";
    }

    return 0;
}