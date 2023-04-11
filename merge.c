#include "merge.h"

void findMatchingPieces(puzzlePiece* startPiece1, puzzlePiece* startPiece2, int visited1[], int visited2[], puzzlePiece* matchingPieces[]) {
    /*find two puzzle pieces in the puzzles connected to startPiece1 and startPiece2 with a matching edge, and put them in matchingPieces*/
    //TODO: stop when matching pieces are found!!!
    node_t queuePuzzle2; //queue containing pieces from puzzle2 (which starts with startPiece2)
    //queue for puzzle 2
    //queue for puzzle 1 or recursive?
    //TODO: check if all is well with the queue!
}

int doPiecesMatch(puzzlePiece* startPiece1, puzzlePiece* startPiece2) {
    /*returns 1 iif startPiece1 and* startPiece2 have a matching edge*/
    for (int i1 = 0; i1 < 4; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
            if (startPiece1->edges[i1] == startPiece2->edges[i2]) { //found a matching edge
                printf("matching edge found: %d between pieces:\n", startPiece1->edges[i1]);
                printNeighboursIndices(startPiece1);
                printNeighboursIndices(startPiece2);
                return 1;
            }
        }
    }
    //no matching edge found
    return 0;
}

void recFindMatchingPieces(puzzlePiece* startPiece1, puzzlePiece* startPiece2, int visited1[], int visited2[], puzzlePiece* matchingPieces[], int numberVisited1, int sizePuzzle1) {
    /*find two puzzle pieces in the puzzles 1 and 2 (connected to startPiece1 and startPiece2) with a matching edge, and put them in matchingPieces*/
    //TODO: stop when matching pieces are found!!!
    printf("...matching puzzle1[%d]+puzzle2[%d]\n", startPiece1->index, startPiece2->index);
    //update visit arrays
    visited1[startPiece1->index] = 1;
    visited2[startPiece2->index] = 1;
    numberVisited1++;
    //check if pieces match
    int piecesMatch = doPiecesMatch(startPiece1, startPiece2);
    if (piecesMatch) {
        matchingPieces[0] = startPiece1;
        matchingPieces[1] = startPiece2;
    }
    //if not, try to match other pieces
    else if (numberVisited1 < sizePuzzle1) { //try to match startPiece2 to another piece of puzzle1
        for (int i = 0; i < 4; i++) {
            puzzlePiece* neighbour = (startPiece1->neighbours)[i]; //neighbour in puzzle1
            if ((neighbour)&&(!visited1[neighbour->index]) && (!matchingPieces[0])) { //if neighbour exists, has not been visited and match has not been found yet
                recFindMatchingPieces(neighbour, startPiece2, visited1, visited2, matchingPieces, numberVisited1, sizePuzzle1);
            }
        }
    }
    else { //startPiece2 has no match in puzzle1 so we try with another piece from puzzle2
        for (int i = 0; i < 4; i++) {
            puzzlePiece* neighbour = (startPiece2->neighbours)[i]; //neighbour in puzzle2
            //if neighbour exists, has not been visited and match has not been found yet 
            if ((neighbour)&&(!visited2[neighbour->index]) && (!matchingPieces[0])) { 
                memset(visited1, 0, sizePuzzle1*sizeof(int)); //reset visit array of puzzle1 with zeros
                numberVisited1 = 0; //reset visited number of puzzle pieces from puzzle1 
                recFindMatchingPieces(startPiece1, neighbour, visited1, visited2, matchingPieces, numberVisited1, sizePuzzle1);
            }
        }
    }
}


void mergePuzzles(puzzle* puzzle1, puzzle* puzzle2) {
    /*attempt to merge two groups of puzzle pieces puzzle1 and puzzle2*/
    //initialize visit arrays
    printf("hello!\n");
    int visited1[puzzle1 -> size]; //visited1[piece.index] = 1 iif piece has been visited
    memset(visited1, 0, (puzzle1 -> size)*sizeof(int)); //initialize with zeros
    int visited2[puzzle2 -> size]; //visited1[piece.index] = 1 iif piece has been visited
    memset(visited2, 0, (puzzle2 -> size)*sizeof(int)); //initialize with zeros
    //find two pieces from the puzzles with a matching edge
    puzzlePiece* matchingPieces[2] = {NULL, NULL};
    recFindMatchingPieces(puzzle1->startPiece, puzzle2->startPiece, visited1, visited2, matchingPieces, 0, puzzle1->size);
    //TODO: see what is done in case no match found (return false?)
}

int main(int argc, char **argv) {
    //initialize puzzle pieces
    puzzlePiece piece1 = { .edges = {4, 1, 2, 3}, .index = 0, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece2 = { .edges = {6, 7, 4, 5}, .index = 1, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece3 = { .edges = {10, 5, 8, 9}, .index = 2, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece4 = { .edges = {8, 3, 11, 12}, .index = 3, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece5 = { .edges = {16, 13, 14, 15}, .index = 0, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece6 = { .edges = {14, 10, 17, 18}, .index = 1, .neighbours = {NULL, NULL, NULL, NULL}};
    //initialize neighbours relationships
    setLeftNeighbour(&piece1, &piece2); setDownNeighbour(&piece1, &piece4);
    setRightNeighbour(&piece2, &piece1); setDownNeighbour(&piece2, &piece3);
    setTopNeighbour(&piece3, &piece2); setRightNeighbour(&piece3, &piece4);
    setLeftNeighbour(&piece4, &piece3); setTopNeighbour(&piece4, &piece1);
    setRightNeighbour(&piece5, &piece6);
    setLeftNeighbour(&piece6, &piece5);
    //initialize puzzles
    puzzle puzzy1 = { .size = 4, .startPiece = &piece1};
    puzzle puzzy2 = { .size = 2, .startPiece = &piece5};
    //tests
    //mergePuzzles(&puzzy1, &puzzy2);  
    //printf("%d", getNumberNeighbours(&piece1));
}