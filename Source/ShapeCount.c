#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>



typedef struct SMDB{
    int **edges;
    int size;
    unsigned long max_size;
} SMDB;

typedef void *SortMergeJoinDatabase;

SortMergeJoinDatabase SortMergeJoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd){
    struct SMDB *db = (struct SMDB *) malloc(sizeof(struct SMDB));
    int ** data = (int **) malloc(sizeof(int *) * totalNumberOfEdgesInTheEnd);
    memset(data, 0, sizeof(*data) * totalNumberOfEdgesInTheEnd);
    db->edges = data;
    db->size = 0;
    db->max_size = totalNumberOfEdgesInTheEnd;
    for (int i = 0; i < totalNumberOfEdgesInTheEnd; i++){
        db->edges[i] = (int *) malloc(sizeof(int) * 3);
        db->edges[i][0] = -1;
    }
    return (SortMergeJoinDatabase) db;
};


int **insert(int *e, SMDB *db);

void SortMergeJoinInsertEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    // TODO: finish this function.
    int e[] = {fromNodeID, toNodeID, edgeLabel};
    int *edge = &e[0];
    SMDB *db = (SMDB *) database;
    db->edges = insert(edge,db);
    db->size = db->size+1;

}

int **insert(int *e, SMDB *db) {
    int **cur = db->edges;
    int pos = 0;
    while (cur[pos][0] != -1){
        if ( *cur[pos] < e[0]){
            pos++;
        } else {
            break;
        }
    }
    int c;
    int n = db->size;
    for (c = n - 1; c >= pos - 1; c--)
        cur[c+1] =cur[c];
    cur[pos-1] = e;
    return cur;
}

void printDB(struct SMDB *db){
    int n = db->size;
    int **edges = db->edges;
    for(int i = 0; i < n; i++){
        printf("Label:%d, from:%d, to:%d\n",edges[i][2],edges[i][0],edges[i][1]);
    }
}

int SortMergeJoinRunQuery(SortMergeJoinDatabase database, int edgeLabel1, int edgeLabel2,
                          int edgeLabel3) {
    // TODO: finish this function.

    return 0;
}

void SortMergeJoinDeleteEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    // TODO: finish this function.

}

void SortMergeJoinDeleteDatabase(SortMergeJoinDatabase database) {
    // TODO: finish this function.
    free(database);
}

typedef void *HashjoinDatabase;

/*
typedef struct HashEdge{
    int label, from, to;
} HashEdge;
*/

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    /*HashEdge *data = (HashEdge *) malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
    memset(data, 0, sizeof(*data) * totalNumberOfEdgesInTheEnd);
    return (HashjoinDatabase) data;*/
    return NULL;
}

void HashjoinInsertEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
 /*   HashEdge *edge = (HashEdge *) malloc(sizeof(HashEdge));
    edge->label = edgeLabel;
    edge->from = fromNodeID;
    edge->to = toNodeID;*/
}

int HashjoinRunQuery(HashjoinDatabase database, int edgeLabel1, int edgeLabel2, int edgeLabel3) {
    // TODO: finish this function.

    return 0;
}

void HashjoinDeleteEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    // TODO: finish this function.

}

void HashjoinDeleteDatabase(HashjoinDatabase database) {
    // TODO: finish this function.

}

typedef void *CompetitionDatabase;

CompetitionDatabase CompetitionAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd){
	return NULL;
};

void CompetitionInsertEdge(CompetitionDatabase database, int fromNodeID, int toNodeID,
                           int edgeLabel) {
    // TODO: finish this function.

}

int CompetitionRunQuery(CompetitionDatabase database, int edgeLabel1, int edgeLabel2,
                        int edgeLabel3) {
    // TODO: finish this function.
    return 0;
}

void CompetitionDeleteEdge(CompetitionDatabase database, int fromNodeID, int toNodeID,
                           int edgeLabel) {
    // TODO: finish this function.

}

void CompetitionDeleteDatabase(CompetitionDatabase database) {
    // TODO: finish this function.

}

int main(void){
    printf("1");
    SortMergeJoinDatabase db = SortMergeJoinAllocateDatabase(3);
    SortMergeJoinInsertEdge(db, 0, 1, 0);
    SortMergeJoinInsertEdge(db, 1, 2, 0);
    SortMergeJoinInsertEdge(db, 2, 0, 0);
    printDB((struct SMDB *)db);
}
