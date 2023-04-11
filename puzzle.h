#ifndef PUZZLE
#define PUZZLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct puzzlePiece {
    /*a puzzle piece is represented as 4 numbers which are its edges. If two puzzle pieces have a matching edge, they fit together.
    Edges are > 0, unless they are on the global border in case they have the value -1. */
    int edges[4]; //array containing the four edges (ints)
    int index; //index in the puzzle
    struct puzzlePiece* neighbours[4]; //the four neighbours in the following order: [left, top, right, down]
    int numberNeighbours;
} puzzlePiece;

typedef struct puzzle {
    /*a puzzle is a group of puzzle pieces that fit together*/
    int size; //number of pieces
    puzzlePiece* startPiece; //a piece of the puzzle

} puzzle;

void setLeftNeighbour(puzzlePiece* piece, puzzlePiece* neighbour);
void setTopNeighbour(puzzlePiece* piece, puzzlePiece* neighbour);
void setRightNeighbour(puzzlePiece* piece, puzzlePiece* neighbour);
void setDownNeighbour(puzzlePiece* piece, puzzlePiece* neighbour);

int getNumberNeighbours(puzzlePiece* piece);

void printNeighboursIndices(puzzlePiece* piece);

void rotatePuzzle(puzzle* puzzle, int rotation);

void rotatePuzzlePiece(puzzlePiece* piece, int rotation, int visited[]);


#endif