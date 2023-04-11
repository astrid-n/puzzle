#include <stdio.h>
#include <string.h>
#include "puzzle.h"
#include "node.h"

void findMatchingPieces(puzzlePiece* startPiece1, puzzlePiece* startPiece2, int visited1[], int visited2[], puzzlePiece* matchingPieces[]);

int doPiecesMatch(puzzlePiece* startPiece1, puzzlePiece* startPiece2);

void recFindMatchingPieces(puzzlePiece* startPiece1, puzzlePiece* startPiece2, int visited1[], int visited2[], puzzlePiece* matchingPieces[], int numberVisited1, int sizePuzzle1);

void mergePuzzles(puzzle* puzzle1, puzzle* puzzle2); 