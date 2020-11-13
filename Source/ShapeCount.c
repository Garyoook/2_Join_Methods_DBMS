#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>

typedef struct Edge{
    int label_edge, from_node, to_node;
} Edge;

typedef struct SMDB{
     Edge **edges;
    int size;
    unsigned long max_size;
} SMDB;

typedef void *SortMergeJoinDatabase;
Edge **insert(Edge *e, SMDB *db);
void printDB(struct SMDB *db);

SortMergeJoinDatabase SortMergeJoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd){
    struct SMDB *db = (struct SMDB *) malloc(sizeof(struct SMDB));
    Edge ** data = (Edge **) malloc(sizeof(Edge*) * totalNumberOfEdgesInTheEnd);
    db->edges = data;
    db->size = 0;
    db->max_size = totalNumberOfEdgesInTheEnd;
    return (SortMergeJoinDatabase) db;
}

void SortMergeJoinInsertEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->from_node = fromNodeID;
    edge->to_node = toNodeID;
    edge->label_edge = edgeLabel;
    SMDB *db = (SMDB *) database;
    db->edges = insert(edge,db);
    db->size++;
}

Edge **insert(Edge *e, SMDB *db) {
    //sorting while inserting, sorted by from

    Edge **cur = db->edges;
    int pos = 0;
    int n = db->size;

    if (n == 0){
        cur[0] = e;

        return cur;
    }
    for (int i = 0; i < n; i++){
        if ( cur[i]->from_node > e->from_node){
          pos = i;
          break;
        }
    }


    for (int c = n - 1; c >= pos; c--){
        cur[c+1] =cur[c];
    }
    cur[pos] = e;
    return cur;
}

void printDB(struct SMDB *db){
    int n = db->size;
    Edge **edges = db->edges;
    for(int i = 0; i < n; i++){
        printf("from:%d, to:%d, Label:%d\n",edges[i]->from_node,edges[i]->to_node,edges[i]->label_edge);

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

typedef struct HashEdge{
    int label, from, to;
} HashEdge;

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    HashEdge *data = (HashEdge *) malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
    memset(data, 0, sizeof(*data) * totalNumberOfEdgesInTheEnd);
    return (HashjoinDatabase) data;
    return NULL;
}

void HashjoinInsertEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    HashEdge *edge = (HashEdge *) malloc(sizeof(HashEdge));
    edge->label = edgeLabel;
    edge->from = fromNodeID;
    edge->to = toNodeID;
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
    SortMergeJoinDatabase db = SortMergeJoinAllocateDatabase(3);
    SortMergeJoinInsertEdge(db, 0, 1, 0);
    printDB((struct SMDB *)db);
    SortMergeJoinInsertEdge(db, 1, 2, 0);
    SortMergeJoinInsertEdge(db, 2, 0, 0);
    free(db);
}
