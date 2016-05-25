#include <cstdio>
#include <iostream>
#include <ctime>
#include <climits>

using namespace std;

#define MAX INT_MAX
#define ROW 6
#define NUM 256

int abs(int i) {
    return i < 0 ? -i : i;
}

int main(int argc, char const* argv[]) {
    srand((unsigned)time(NULL));

    for (int i = 1; i * ROW < NUM; i++) {
        for (int j = 0; j < ROW; j++) {
            printf("%d, ", abs(rand()));
        }

        printf("\n");
    }

    for (int i = 0; i < NUM % ROW; i++) {
        printf("%d, ", abs(rand()));
    }

    return 0;
}
