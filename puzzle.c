#include "puzzle.h"

void setLeftNeighbour(puzzlePiece* piece, puzzlePiece* neighbour) {
    if ((piece -> neighbours)[0]) printf("Left neighbour has already been set!!!");
    (piece -> neighbours)[0] = neighbour;
    piece->numberNeighbours++;
}

void setTopNeighbour(puzzlePiece* piece, puzzlePiece* neighbour) {
    if ((piece -> neighbours)[1]) printf("Left neighbour has already been set!!!");
    (piece -> neighbours)[1] = neighbour;
    piece->numberNeighbours++;
}

void setRightNeighbour(puzzlePiece* piece, puzzlePiece* neighbour) {
    if ((piece -> neighbours)[2]) printf("Left neighbour has already been set!!!");
    (piece -> neighbours)[2] = neighbour;
    piece->numberNeighbours++;
}

void setDownNeighbour(puzzlePiece* piece, puzzlePiece* neighbour) {
    if ((piece -> neighbours)[3]) printf("Left neighbour has already been set!!!");
    (piece -> neighbours)[3] = neighbour;
    piece->numberNeighbours++;
}

int getNumberNeighbours(puzzlePiece* piece) {
    /*get number of non-NULL neighbours*/
    int numberNeighbours = 0;
    for (int i = 0; i < 4; i++) {
        if ((piece->neighbours)[i])
            numberNeighbours++;
    }
    return numberNeighbours;
}

void printNeighboursIndices(puzzlePiece* piece) {
    printf("Neighbours of puzzle piece %d: ", piece->index);
    for (int i = 0; i < 4; i++) {
        if (!((piece->neighbours)[i])) 
            printf("NULL ");
        else
            printf("%d ", (piece->neighbours)[i]->index);
    }
    printf("\n");
}

void rotatePuzzlePiece(puzzlePiece* piece, int rotation, int visited[]) {
    if ((rotation > 0) && (visited[piece -> index] == 0)) {
        visited[piece -> index] = 1;
        //rotate the puzzle piece by changing the order of its neighbours and of its edges
        puzzlePiece* rotatedNeighbours[4];
        int rotatedEdges[4];
        for (int i = 0; i < 4; i++) {
            rotatedNeighbours[i] = (piece -> neighbours)[(4+i-rotation)%4];
            rotatedEdges[i] = (piece -> edges)[(4+i-rotation)%4];
        }
        for (int i = 0; i < 4; i++) {
            (piece -> neighbours)[i] = rotatedNeighbours[i];
            (piece -> edges)[i] = rotatedEdges[i];
        }   
        //rotate its existing neighbours
        for (int i = 0; i < 4; i++) {
            if (((piece->neighbours)[i])) {
                rotatePuzzlePiece((piece -> neighbours)[i], rotation, visited);
            }
        }
    }
}

void rotatePuzzle(puzzle* puzzle, int rotation) {
    /*rotate the puzzle clockwise by increments of 45 degrees. rotation (0-3) defines the number of clockwise 45 degrees rotations*/
    //initialize visit array
    int visited[puzzle -> size]; //visited[piece.index] = 1 iif piece has been visited
    memset(visited, 0, (puzzle -> size)*sizeof(int)); //initialize with zeros
    //rotate starting piece, move on to its neighbours and repeat
    rotatePuzzlePiece(puzzle->startPiece, rotation, visited);    
}

/*
int main(int argc, char **argv) {
    //initialize puzzle pieces
    puzzlePiece piece1 = { .edges = {4, 1, 2, 3}, .index = 0, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece2 = { .edges = {6, 7, 4, 5}, .index = 1, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece3 = { .edges = {10, 5, 8, 9}, .index = 2, .neighbours = {NULL, NULL, NULL, NULL}};
    puzzlePiece piece4 = { .edges = {8, 3, 11, 12}, .index = 3, .neighbours = {NULL, NULL, NULL, NULL}};
    //initialize neighbours relationships
    setLeftNeighbour(&piece1, &piece2); setDownNeighbour(&piece1, &piece4);
    setRightNeighbour(&piece2, &piece1); setDownNeighbour(&piece2, &piece3);
    setTopNeighbour(&piece3, &piece2); setRightNeighbour(&piece3, &piece4);
    setLeftNeighbour(&piece4, &piece3); setTopNeighbour(&piece4, &piece1);
    //initialize puzzle
    puzzle puzzy = { .size = 4, .startPiece = &piece1};
    //test rotation
    printNeighboursIndices(&piece3);
    rotatePuzzle(&puzzy, 2);
    printNeighboursIndices(&piece3);    
}
*/