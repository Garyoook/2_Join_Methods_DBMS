#include <stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

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

int HashJoin(HashEdge **build, int build_size, HashEdge **probe2, int probe2_size, HashEdge **probe3, int probe3_size, unsigned long max_alloc_size) {
    int count = 0;
    HashEdge **result1 = (HashEdge **)malloc(sizeof(HashEdge*) * probe2_size);
    HashEdge hash_table[(int) pow(2, (double) max_alloc_size)]; // = (HashEdge *)malloc(sizeof(HashEdge) * max_alloc_size);
    HashEdge hash_table2[(int) pow(2, (double) max_alloc_size)];

    for (int i = 0; i < pow(2, (double)max_alloc_size); i++) {
        (hash_table + i)->label_edge = -1;
        (hash_table2 + i)->label_edge = -1;
    }

    // build phase:
    for (int i = 0; i < build_size; i++) {
        HashEdge *buildInput = build[i];
        int hash_value = hash_mod(buildInput->to_node);
        while (hash_table[hash_value].label_edge != -1) {
            hash_value = nextSlot(hash_value);
        }
        hash_table[hash_value] = *buildInput;
    }

    // probe phase:
    for(int i = 0; i < probe2_size; i++) {
        HashEdge *probeInput = probe2[i];
        int hash_value = hash_mod(probeInput->from_node);

        while(hash_table[hash_value].label_edge !=  -1 &&
              hash_table[hash_value].to_node != probeInput->from_node) {
            hash_value = nextSlot(hash_value);
        }
        if (hash_table[hash_value].to_node == probeInput->from_node) {
            *(result1 + count) = probeInput;
            // build for 2nd hash table:
            int hash_value2 = hash_mod(probeInput->to_node);
            while(hash_table2[hash_value2].label_edge != -1) {
                hash_value2 = nextSlot(hash_value2);
            }
            hash_table2[hash_value2] = *probeInput;
        }
    }

    // second probe phase:
    for (int i = 0; i < probe3_size; i++) {
        HashEdge *probeInput = probe3[i];
        int hash_value2 = hash_mod(probeInput->from_node);

        while(hash_table2[hash_value2].label_edge !=  -1 &&
              hash_table2[hash_value2].to_node != probeInput->from_node) {
            hash_value2 = nextSlot(hash_value2);
        }
        if (hash_table2[hash_value2].to_node == probeInput->from_node) {
            count++;
        }

        // probe from the 2nd hash table:
    }
    return count;
}

int HashjoinRunQuery(HashjoinDatabase database, int edgeLabel1, int edgeLabel2, int edgeLabel3) {
    int count = 0;

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

//int main(void) {
//    HashjoinDatabase db = (HashEdge *) HashjoinAllocateDatabase(10);
//    HashjoinInsertEdge(db, 1,5,0);
//    HashjoinInsertEdge(db, 5,6,1);
//    HashjoinInsertEdge(db, 6,1,2);
//    HashjoinInsertEdge(db, 5,6,1);
//    HashjoinInsertEdge(db, 3,6,1);
//    HashjoinInsertEdge(db, 3,6,1);
//    HashjoinInsertEdge(db, 3,6,1);
//    HashjoinInsertEdge(db, 3,6,1);
//
//    HashjoinRunQuery(db, 0, 1, 2);
////    printEdge(((HashJoinTable *) db)->storage[0]);
//    for (int i = 0; i < ((HashJoinTable *) db)->size; i++) {
//        HashEdge *a = ((HashJoinTable *) db)->storage[i];
//        printEdge(a);
//    }
//    HashjoinDeleteDatabase(db);
//    return 0;
//}
