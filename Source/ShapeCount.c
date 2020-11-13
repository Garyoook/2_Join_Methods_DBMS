#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

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
    HashJoinTable *table = (HashJoinTable *)malloc(sizeof(HashJoinTable));
//    table->hash_table = (HashEdge *)malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
//    memset(table->hash_table, -1, sizeof(int) * totalNumberOfEdgesInTheEnd);

    table->storage = (HashEdge **)malloc(sizeof(HashEdge *) * totalNumberOfEdgesInTheEnd);

    table->size = 0;
    table->max_alloc_size = totalNumberOfEdgesInTheEnd;

    return table;
}

int hash_mod(int input);
int nextSlot(int hash_value);

int hash_mod(int input) {
    return input%10;
}

int nextSlot(int hash_value) {
    return hash_value + hash_mod(hash_value) + 1;
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

int HashJoin(HashEdge **edges1, int edges1_size, HashEdge **edges2, int edges2_size, HashEdge **edges3, int edges3_size, unsigned long max_alloc_size) {
    int count = 0;
    int result_size = 0;
    HashEdge **result1 = (HashEdge **)malloc(sizeof(HashEdge*) * edges2_size);
    int result2_size = 0;
    HashEdge **result2 = (HashEdge **)malloc(sizeof(HashEdge*) * edges3_size);
    HashEdge hash_table[max_alloc_size + 1]; // = (HashEdge *)malloc(sizeof(HashEdge) * max_alloc_size);
    HashEdge hash_table2[max_alloc_size + 1];
    HashEdge hash_table3[max_alloc_size + 1];

    for (int i = 0; i < max_alloc_size + 1; i++) {
        (hash_table + i)->label_edge = -1;
        (hash_table + i)->from_node = -1;
        (hash_table + i)->to_node = -1;
        (hash_table2 + i)->label_edge = -1;
        (hash_table2 + i)->from_node = -1;
        (hash_table2 + i)->to_node = -1;
        (hash_table3 + i)->label_edge = -1;
        (hash_table3 + i)->from_node = -1;
        (hash_table3 + i)->to_node = -1;
    }

    // build phase:
    for (int i = 0; i < edges1_size; i++) {
        HashEdge *buildInput = edges1[i];
        int hash_value = hash_mod(buildInput->to_node);
        while (hash_table[hash_value].label_edge != -1) {
            hash_value = nextSlot(hash_value);
        }
        hash_table[hash_value] = *buildInput;
    }

    // probe phase:
    for(int i = 0; i < edges2_size; i++) {
        HashEdge *probeInput = edges2[i];
        int hash_value = hash_mod(probeInput->from_node);

        while(hash_table[hash_value].label_edge !=  -1 &&
              hash_table[hash_value].to_node != probeInput->from_node) {
            hash_value = nextSlot(hash_value);
        }
        if (hash_table[hash_value].to_node == probeInput->from_node) {
            *(result1 + (result_size++)) = probeInput;
        }
    }

    // build phase for edges3:
    for (int i = 0; i < edges3_size; i++) {
        HashEdge *probeInput = edges3[i];
        // build for 2nd hash table:
        int hash_value2 = hash_mod(probeInput->from_node);
        while(hash_table2[hash_value2].label_edge != -1) {
            hash_value2 = nextSlot(hash_value2);
        }
        hash_table2[hash_value2] = *probeInput;
    }

    // second probe phase:
    for (int j = 0; j < result_size; j++) {
        HashEdge *probeInput = result1[j];
        int hash_value2 = hash_mod(probeInput->to_node);

        while(hash_table2[hash_value2].label_edge !=  -1 &&
              hash_table2[hash_value2].from_node != probeInput->to_node) {
            hash_value2 = nextSlot(hash_value2);
        }
        if (hash_table2[hash_value2].from_node == probeInput->to_node) {
            *(result2 + (result2_size++)) = probeInput;
            count++;
        }
    }

//    // build phase from edges3 to edges1:
//    for (int i = 0; i < edges1_size; i++) {
//        HashEdge *probeInput = edges1[i];
//        // build for 2nd hash table:
//        int hash_value3 = hash_mod(probeInput->from_node);
//        while(hash_table3[hash_value3].label_edge != -1) {
//            hash_value3 = nextSlot(hash_value3);
//        }
//        hash_table3[hash_value3] = *probeInput;
//    }
//
//    // 3rd probe phase:
//    for (int j = 0; j < result2_size; j++) {
//        HashEdge *probeInput = result2[j];
//        int hash_value3 = hash_mod(probeInput->to_node);
//
//        while(hash_table3[hash_value3].label_edge !=  -1 &&
//              hash_table2[hash_value3].from_node != probeInput->to_node) {
//            hash_value3 = nextSlot(hash_value3);
//        }
//        if (hash_table2[hash_value3].from_node == probeInput->to_node) {
//            count++;
//        }
//    }


    return count;
}

int HashjoinRunQuery(HashjoinDatabase database, int edgeLabel1, int edgeLabel2, int edgeLabel3) {
    HashJoinTable *db = (HashJoinTable *) database;

    HashEdge **db_label1 = (HashEdge **)malloc(sizeof(HashEdge *) * db->size);
    HashEdge **db_label2 = (HashEdge **)malloc(sizeof(HashEdge *) * db->size);
    HashEdge **db_label3 = (HashEdge **)malloc(sizeof(HashEdge *) * db->size);
    int size1 = 0, size2 = 0, size3 = 0;


    for (int i = 0; i < db->size; i++) {
        if (db->storage[i]->label_edge == edgeLabel1) {
            *(db_label1 + size1) = db->storage[i];
            size1++;
        }
        if (db->storage[i]->label_edge == edgeLabel2) {
            *(db_label2 + size2) = db->storage[i];
            size2++;
        }
        if (db->storage[i]->label_edge == edgeLabel3) {
            *(db_label3 + size3) = db->storage[i];
            size3++;
        }
    }

    int count_result = HashJoin(db_label1, size1, db_label2, size2, db_label3, size3, db->max_alloc_size);

    free(db_label1);
    free(db_label2);
    free(db_label3);

    return count_result;
}

void HashjoinDeleteEdge(HashjoinDatabase database, int fromNodeID, int toNodeID, int edgeLabel) {
    HashJoinTable *db = (HashJoinTable *) database;
    for(int i = 0; i < db->size; i++) {
        if(db->storage[i]->label_edge == edgeLabel
           && db->storage[i]->from_node == fromNodeID
           && db->storage[i]->to_node == toNodeID) {
            db->storage[i]->label_edge = -1;
            db->storage[i]->from_node = -1;
            db->storage[i]->to_node = -1;
        }
    }
}

void HashjoinDeleteDatabase(HashjoinDatabase database) {
    HashJoinTable *db = (HashJoinTable *) database;
    free(db->storage);
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

//int main(void) {
//    HashJoinTable *db = (HashJoinTable *) HashjoinAllocateDatabase(100);
//
//
////    HashjoinInsertEdge(db, 0, 1, 0);
////    HashjoinInsertEdge(db, 0, 2, 0);
////    HashjoinInsertEdge(db, 0, 3, 0);
////    HashjoinInsertEdge(db, 1, 3, 1);
////    HashjoinInsertEdge(db, 1, 4, 1);
////    HashjoinInsertEdge(db, 1, 2, 1);
////    HashjoinInsertEdge(db, 3, 4, 1);
////    HashjoinInsertEdge(db, 3, 2, 1);
////    HashjoinInsertEdge(db, 2, 0, 2);
////    HashjoinInsertEdge(db, 4, 0, 2);
////    HashjoinInsertEdge(db, 3, 0, 2);
////    HashjoinDeleteEdge(db, 3, 4, 1);
////    HashjoinDeleteEdge(db, 3, 2, 1);
//
//
//    HashjoinInsertEdge(db, 0, 1, 0);
//    HashjoinInsertEdge(db, 0, 2, 0);
//    HashjoinInsertEdge(db, 0, 3, 0);
//    HashjoinInsertEdge(db, 1, 3, 1);
//    HashjoinInsertEdge(db, 1, 4, 1);
//    HashjoinInsertEdge(db, 1, 2, 1);
//    HashjoinInsertEdge(db, 3, 4, 1);
//    HashjoinInsertEdge(db, 3, 2, 1);
//    HashjoinInsertEdge(db, 2, 0, 2);
//    HashjoinInsertEdge(db, 4, 0, 2);
//    HashjoinInsertEdge(db, 3, 0, 2);
//    HashjoinDeleteEdge(db, 1, 3, 1);
//    HashjoinDeleteEdge(db, 3, 4, 1);
//
////    printEdge(((HashJoinTable *) db)->storage[0]);
//    for (int i = 0; i < ((HashJoinTable *) db)->size; i++) {
//        HashEdge *a = ((HashJoinTable *) db)->storage[i];
//        printEdge(a);
//    }
//    int count = HashjoinRunQuery(db, 0, 1, 2);
//    printf("triangle detected: %d\n", count);
//
//    HashjoinDeleteDatabase(db);
//    return 0;
//}
