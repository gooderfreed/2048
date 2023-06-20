#include "../inc/Board.h"
#include "../inc/Cell.h"
#include "../inc/utils.h"
#include <iostream>
#include <cmath>


Board::Board(float size) {
    this->size = size;

    float dsize = size / N;
    float b = 0.2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = new Cell(j * dsize - size / 2 + dsize / 2, i * dsize - size / 2 + dsize / 2, 0.2, dsize - b);
        }
    }

    gen_new();
    gen_new();

};

Board::~Board() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            delete matrix[i][j];
}

void Board::draw() {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            matrix[i][j]->draw();
        }
    }
}

void Board::gen_new() {
    int li, ri;
    srand(time(0));
    while (1)
    {
        li = rand() % 4;
        ri = rand() % 4;
        if (matrix[li][ri]->get_val() == 0) {
            matrix[li][ri]->set_val(pow(2, li % 2 + 1));
            break;
        }
    }
}

int Board::check() {
    bool null = false;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (matrix[y][x]->get_val() == 0 || matrix[y][x]->get_val() == 2048) {
                null = true;
                if (matrix[y][x]->get_val() != 0) {
                    return 1;
                }

            }
        }
    }
    if (!null) return -1;
    return 0;
}

void Board::move(char dur) {
    switch (dur) {
    case 'w':
        for (int t = 0; t < 5; t++) {
            for (int y = 0; y < N - 1; y++) {
                for (int x = 0; x < N; x++) {
                    if (((matrix[y + 1][x]->get_val()) == matrix[y][x]->get_val()) || ((matrix[y + 1][x]->get_val()) == 0)) {
                        if ((matrix[y + 1][x]->get_val()) != 0 && (matrix[y][x]->get_val()) != 0) {
                            score += matrix[y + 1][x]->get_val();
                        }
                        matrix[y + 1][x]->set_val(matrix[y + 1][x]->get_val() + matrix[y][x]->get_val());
                        matrix[y][x]->set_val(0);
                    }
                }
            }
        }
        break;
    case 's':
        for (int t = 0; t < 5; t++) {
            for (int y = N - 1; y > 0; y--) {
                for (int x = 0; x < N; x++) {
                    if (((matrix[y - 1][x]->get_val()) == matrix[y][x]->get_val()) || ((matrix[y - 1][x]->get_val()) == 0)) {
                        if ((matrix[y - 1][x]->get_val()) != 0 && (matrix[y][x]->get_val()) != 0) {
                            score += matrix[y - 1][x]->get_val();
                        }
                        matrix[y - 1][x]->set_val(matrix[y - 1][x]->get_val() + matrix[y][x]->get_val());
                        matrix[y][x]->set_val(0);
                    }
                }
            }
        }
        break;
    case 'a':
        for (int t = 0; t < 5; t++) {
            for (int x = N - 1; x > 0; x--) {
                for (int y = 0; y < N; y++) {
                    if (((matrix[y][x - 1]->get_val()) == matrix[y][x]->get_val()) || ((matrix[y][x - 1]->get_val()) == 0)) {
                        if ((matrix[y][x - 1]->get_val()) != 0 && (matrix[y][x]->get_val()) != 0) {
                            score += matrix[y][x - 1]->get_val();
                        }
                        matrix[y][x - 1]->set_val(matrix[y][x - 1]->get_val() + matrix[y][x]->get_val());
                        matrix[y][x]->set_val(0);
                    }
                }
            }
        }
        break;
    case 'd':
        for (int t = 0; t < 5; t++) {
            for (int x = 0; x < N - 1; x++) {
                for (int y = 0; y < N; y++) {
                    if (((matrix[y][x + 1]->get_val()) == matrix[y][x]->get_val()) || ((matrix[y][x + 1]->get_val()) == 0)) {
                        if ((matrix[y][x + 1]->get_val()) != 0 && (matrix[y][x]->get_val()) != 0) {
                            score += matrix[y][x + 1]->get_val() * 2;
                        }
                        matrix[y][x + 1]->set_val(matrix[y][x + 1]->get_val() + matrix[y][x]->get_val());
                        matrix[y][x]->set_val(0);
                    }
                }
            }
        }
        break;
    }
}
