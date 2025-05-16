#include <iostream>

int main() {
    int G, M, K;
    std::cin >> G >> M >> K;

    int glass = 0, mug = 0;

    for (int i = 0; i < K; i++) {
        if (glass == G ) {
            glass = 0;
        } else if (mug == 0) {
            mug = M;
        } else {
            glass = glass + (G-glass);
            mug = mug-(G-glass);
            if (mug == 0 || glass == G) {
                break;
            }
        }
    }

    std::cout << glass << " " << mug << std::endl;

    return 0;
}