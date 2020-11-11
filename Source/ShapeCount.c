#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef void *SortMergeJoinDatabase;

SortMergeJoinDatabase SortMergeJoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd){
	return NULL;
};

void SortMergeJoinInsertEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    // TODO: finish this function.
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

}

typedef void *HashjoinDatabase;

typedef struct HashEdge{
    int label, from, to;
} HashEdge;

void printEdge(HashEdge *e) {
    printf("label: %d, from: %d, to: %d\n", e->label, e->from, e->to);
}

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    HashEdge **data = NULL;
    data = (HashEdge **) malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
    memset(data, 0, sizeof(data) * totalNumberOfEdgesInTheEnd);
    return data;
}

int hash(int input) {
    return input%10;
}

int nextSlot(const int *hash_value) {
    return *(hash_value+1);
}

void HashjoinInsertEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    HashEdge *edge = (HashEdge *) malloc(sizeof(HashEdge));
    int index = hash(edgeLabel);
    edge->label = edgeLabel;
    edge->from = fromNodeID;
    edge->to = toNodeID;
    ((HashEdge **)database)[index] = edge;
}

int HashjoinRunQuery(HashjoinDatabase database, int edgeLabel1, int edgeLabel2, int edgeLabel3) {
    return 0;
}

void HashjoinDeleteEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    int index = hash(edgeLabel);
    free((HashEdge *)&database[index]);

}

void HashjoinDeleteDatabase(HashjoinDatabase database) {
    free(&database);
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

int main(void) {
    HashjoinDatabase db = (HashEdge *) HashjoinAllocateDatabase(5);
    HashjoinInsertEdge(db, 2,1,0);
    HashjoinInsertEdge(db, 0,2,1);
    HashjoinInsertEdge(db, 1,0,2);
    for (int i = 0; i < 3; i++) {
        int index = hash(i);
        HashEdge *a = ((HashEdge **) db)[index];
        printEdge(a);
    }
    return 0;
}
