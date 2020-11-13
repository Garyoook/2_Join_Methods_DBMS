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
    int label_edge, from_node, to_node;
} HashEdge;

typedef struct HashJoinTable {
//    HashEdge *hash_table;
    HashEdge **storage;
    int size;
    unsigned long max_alloc_size;
} HashJoinTable;

void printEdge(HashEdge *e) {
    printf("from: %d, to: %d, label: %d\n", e->from_node, e->to_node, e->label_edge);
}

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    HashEdge *data = (HashEdge *) malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
    memset(data, 0, sizeof(*data) * totalNumberOfEdgesInTheEnd);
    return (HashjoinDatabase) data;
    return NULL;
}

int hash_mod(int input);
int nextSlot(int hash_value);

int hash_mod(int input) {
    return input%10;
}

int nextSlot(int hash_value) {
    return hash_value + hash_mod(hash_value);
}



void HashjoinInsertEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    HashJoinTable *db = ((HashJoinTable *)database);
    if (db->size + 1 > db->max_alloc_size) {
        printf("Exceeds maximum size limit!\n");
        return;
    }
    HashEdge *edge = (HashEdge *) malloc(sizeof(HashEdge));
    edge->label_edge = edgeLabel;
    edge->from_node = fromNodeID;
    edge->to_node = toNodeID;
    db->storage[db->size] = edge;
    db->size += 1;
}

int HashjoinRunQuery(HashjoinDatabase database, int edgeLabel1, int edgeLabel2, int edgeLabel3) {
    int count = 0;
    HashJoinTable *build = (HashJoinTable *) database;
    HashEdge * hash_table = (HashEdge *)malloc(sizeof(HashEdge) * build->max_alloc_size);

    for (int i = 0; i < build->max_alloc_size; i++) {
        (hash_table + i)->from_node = -1;
    }

    // build phase:
    for (int i = 0; i < build->size; i++) {
        HashEdge *buildInput = build->storage[i];
        int hash_value = hash_mod(buildInput->from_node);
        while (hash_table[hash_value].from_node != -1) {
            hash_value = nextSlot(hash_value);
        }
        hash_table[hash_value] = *buildInput;
    }

    HashJoinTable *probe = (HashJoinTable *) database;
    for(int i = 0; i < probe->size; i++) {
        bool found = false;
        HashEdge *probeInput = probe->storage[i];
        int hash_value = hash_mod(probeInput->from_node);
        while(hash_table[hash_value].label_edge !=  -1 &&
              hash_table[hash_value].from_node != probeInput->from_node) {
            hash_value = nextSlot(hash_value);
        }
        if (hash_table[hash_value].from_node == probeInput->from_node) {
            found = true;
        }
    }
    free(hash_table);
    return count;
}

void HashjoinDeleteEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    HashJoinTable *db = (HashJoinTable *) database;
    for(int i = 0; i < db->max_alloc_size; i++) {
        free(db->storage[i]);
    }
}

void HashjoinDeleteDatabase(HashjoinDatabase database) {
    HashJoinTable *db = (HashJoinTable *) database;
    for(int i = 0; i < db->size; i++) {
        free(db->storage[i]);
    }
    free(db);
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

    HashjoinRunQuery(db, 0, 1, 2);
    printEdge(((HashJoinTable *) db)->storage[0]);
    for (int i = 0; i < ((HashJoinTable *) db)->size; i++) {
        HashEdge *a = ((HashJoinTable *) db)->storage[i];
        printEdge(a);
    }
    HashjoinDeleteDatabase(db);
    return 0;
}
