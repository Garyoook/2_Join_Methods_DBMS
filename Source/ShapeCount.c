#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

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
    int label_edge, from_node, to_node;
} HashEdge;

typedef struct HashJoinTable {
    HashEdge *hash_table;
    HashEdge **storage;
    int size;
    unsigned long max_alloc_size;
} HashJoinTable;

void printEdge(HashEdge *e) {
    printf("from: %d, to: %d, label: %d\n", e->from_node, e->to_node, e->label_edge);
}

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    HashJoinTable *table = (HashJoinTable *)malloc(sizeof(HashJoinTable));
    table->hash_table = (HashEdge *)malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
    memset(table->hash_table, -1, sizeof(int) * totalNumberOfEdgesInTheEnd);

    table->storage = (HashEdge **)malloc(sizeof(HashEdge *) * totalNumberOfEdgesInTheEnd);

//    for (int i = 0; i<totalNumberOfEdgesInTheEnd; i++) {
//        table->storage[i].label_edge = -1;
//    }
    table->size = 0;
    table->max_alloc_size = totalNumberOfEdgesInTheEnd;

    return table;
}

int hash(int input) {
    return input%10;
}

int nextSlot(hash_value) {
    return hash_value + hash(hash_value);
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
    HashJoinTable *build = (HashJoinTable *) database;
    for (int i = 0; i < build->size; i++) {
        HashEdge *buildInput = build->storage[i];
        int hash_value = hash(buildInput->from_node);
        while (((HashJoinTable *) database)->hash_table[hash_value].label_edge != -1) {
            hash_value = nextSlot(hash_value);
        }
        ((HashJoinTable *) database)->hash_table[hash_value] = *buildInput;
    }

    HashJoinTable *probe = (HashJoinTable *) database;
    for(int i = 0; i < probe->size; i++) {
        bool found = false;
        HashEdge *probeInput = probe->storage[i];
        int hash_value = hash(probeInput->from_node);
        while(probe->hash_table[hash_value].label_edge !=  -1 &&
              probe->hash_table[hash_value].from_node != probeInput->from_node) {
            hash_value = nextSlot(hash_value);
        }
        if (probe->hash_table[hash_value].from_node == probeInput->from_node) {
            found = true;
        }
    }
    return 0;
}

void HashjoinDeleteEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    HashJoinTable *db = (HashJoinTable *) database;
    for(int i = 0; i < db->size; i++) {
        free(db->storage[i]);
        free(db->hash_table);
    }

}

void HashjoinDeleteDatabase(HashjoinDatabase database) {
    free(database);
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
    printEdge(((HashJoinTable *) db)->storage[0]);
    for (int i = 0; i < ((HashJoinTable *) db)->size; i++) {
        HashEdge *a = ((HashJoinTable *) db)->storage[i];
        printEdge(a);
    }
    return 0;
}
