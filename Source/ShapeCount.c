#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

typedef struct Edge_sp{
    int label_edge, from_node, to_node;
} Edge_sp;

typedef struct SMDB{
    Edge_sp **edges;
    int size;
    int max_size;
} SMDB;

typedef void *SortMergeJoinDatabase;
Edge_sp **insert(Edge_sp *e, SMDB *db);
void printDB(struct SMDB *db);


SMDB *connectEdges(const SMDB *first_edges, const SMDB *second_edges,int max);

void InsertEdge(Edge_table *edge, SMDB *db);

SortMergeJoinDatabase SortMergeJoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd){
    struct SMDB *db = (struct SMDB *) malloc(sizeof(struct SMDB));
    Edge_sp ** data = (Edge_sp **) malloc(sizeof(Edge_sp*) * totalNumberOfEdgesInTheEnd);
    db->edges = data;
    db->size = 0;
    db->max_size = (int) totalNumberOfEdgesInTheEnd;
    return (SortMergeJoinDatabase) db;
}

void SortMergeJoinInsertEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    Edge_sp *edge = (Edge_sp *) malloc(sizeof(Edge_sp));
    edge->from_node = fromNodeID;
    edge->to_node = toNodeID;
    edge->label_edge = edgeLabel;
    SMDB *db = (SMDB *) database;

    InsertEdge(edge, db);

}

Edge_sp **insert(Edge_sp *e, SMDB *db) {
    //sorting while inserting, sorted by from

    Edge_sp **cur = db->edges;
    int pos = 0;
    int n = db->size;


int partition (Edge_table **arr, int low, int high, int attribute)
{ //from 0, to 1;
    Edge_table *pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (attribute == 0) {
            if (arr[j]->from_node < pivot->from_node)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        } else if (attribute == 1){
            if (arr[j]->to_node < pivot->to_node)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Edge_table **arr, int low, int high,int attribute)
{
    if (low < high)
    {

        int pi = partition(arr, low, high, attribute);
        quickSort(arr, low, pi - 1,attribute);
        quickSort(arr, pi + 1, high,attribute);
    }
}

void printDB(struct SMDB *db){
    int n = db->size;
    Edge_sp **edges = db->edges;
    for(int i = 0; i < n; i++){
        printf("from:%d, to:%d, Label:%d\n",edges[i]->from_node,edges[i]->to_node,edges[i]->label_edge);

    }
}

int SortMergeJoinRunQuery(SortMergeJoinDatabase database, int edgeLabel1, int edgeLabel2,
                          int edgeLabel3) {
    SMDB *db = (SMDB *) database;
    int n = db->size;
    Edge_table **edges = db->edges;
    SMDB *first_edges = (SMDB *) SortMergeJoinAllocateDatabase(n);
    SMDB *second_edges = (SMDB *) SortMergeJoinAllocateDatabase(n);
    SMDB *third_edges = (SMDB *) SortMergeJoinAllocateDatabase(n);
    for (int i = 0; i < n; i++){
        if (edges[i]->label_edge == edgeLabel1){
            InsertEdge(edges[i],first_edges);
        }
        if (edges[i]->label_edge == edgeLabel2){
            InsertEdge(edges[i],second_edges);
        }
        if (edges[i]->label_edge == edgeLabel3)   {
            InsertEdge(edges[i],third_edges);
        }
    }

    //compare firstEdge.to = secondEdge.from and firstEdge.label = 0
    SMDB *first_result = connectEdges(first_edges, second_edges,second_edges->size);
    //compare secondEdge.to = thirdEdge.from and firstEdge.label = 1
    SMDB *second_result = connectEdges(first_result,third_edges,first_result->max_size);
    return second_result->max_size;
}

struct SMDB*connectEdges(const SMDB *first_edges, const SMDB *second_edges,int max) {
    quickSort(first_edges->edges, 0, first_edges->size - 1, TO);
    quickSort(second_edges->edges,0,second_edges->size - 1,FROM);
    int lefti = 0;
    int righti = 0;
    int leftsize = first_edges->size;
    int rightsize = second_edges->size;
    int resultsize = 0;
    Edge_table **leftEdges = first_edges->edges;
    Edge_table **rightEdges = second_edges->edges;
    Edge_table **result = (Edge_table **) malloc(sizeof(Edge_table*) * rightsize);
    int count = 0;
    while (lefti < leftsize && righti < rightsize){
        if (leftEdges[lefti]->to_node < rightEdges[righti]->from_node){
            lefti++;
        } else if(leftEdges[lefti]->to_node > rightEdges[righti]->from_node){
            righti++;
        } else {
            int j = lefti;
            while (j < leftsize && leftEdges[j]->to_node == rightEdges[righti]->from_node){
                resultsize++;
                j++;
            }
            *(result + count) = rightEdges[righti++];
            count++;
        }
    }
    SMDB *db = (SMDB *) SortMergeJoinAllocateDatabase(rightsize);
    db->edges = result;
    db->size = count;
    db->max_size = resultsize;
    return db;
}

void SortMergeJoinDeleteEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    //search the position of the given edge
    SMDB *db = (SMDB *) database;
    int n = db->size;
    Edge_table **edges = db->edges;
    int i;
    for (i = 0; i < n; i ++){
        Edge_table *cur = edges[i];
        if (cur->label_edge == edgeLabel && cur->to_node == toNodeID && cur->from_node == fromNodeID){
            break;
        }
    }
    if (i < n)
    {
        n = n - 1;
        for (int j=i; j<n; j++)
            edges[j] = edges[j+1];
    }
    db->edges = edges;
    db->size--;
}

void SortMergeJoinDeleteDatabase(SortMergeJoinDatabase database) {
    SMDB *db = (SMDB *) database;
    free(db->edges);
    free(db);
}

typedef void *HashjoinDatabase;

typedef struct HashJoinTable {
//    Edge_sp *hash_table;
    Edge_sp **storage;
    int size;
    unsigned long max_alloc_size;
} HashJoinTable;

void printEdge(Edge_sp *e) {
    printf("from: %d, to: %d, label: %d\n", e->from_node, e->to_node, e->label_edge);
}

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    HashJoinTable *table = (HashJoinTable *)malloc(sizeof(HashJoinTable));
//    table->hash_table = (Edge_sp *)malloc(sizeof(Edge) * totalNumberOfEdgesInTheEnd);
//    memset(table->hash_table, -1, sizeof(int) * totalNumberOfEdgesInTheEnd);

    table->storage = (Edge_sp **)malloc(sizeof(Edge_sp *) * totalNumberOfEdgesInTheEnd);

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
    Edge_sp *edge = (Edge_sp *) malloc(sizeof(Edge_sp));
    edge->label_edge = edgeLabel;
    edge->from_node = fromNodeID;
    edge->to_node = toNodeID;
    db->storage[db->size] = edge;
    db->size += 1;
}

int HashJoin(Edge_sp **edges1, int edges1_size, Edge_sp **edges2, int edges2_size, Edge_sp **edges3, int edges3_size, unsigned long max_alloc_size) {
    int count = 0;
    int result_size = 0;
    Edge_sp **result1 = (Edge_sp **)malloc(sizeof(Edge_sp *) * edges2_size);
    int result2_size = 0;
    Edge_sp **result2 = (Edge_sp **)malloc(sizeof(Edge_sp *) * edges3_size);
    Edge_sp hash_table[max_alloc_size + 1]; // = (Edge_sp *)malloc(sizeof(Edge) * max_alloc_size);
    Edge_sp hash_table2[max_alloc_size + 1];
    Edge_sp hash_table3[max_alloc_size + 1];

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
        Edge_sp *buildInput = edges1[i];
        int hash_value = hash_mod(buildInput->to_node);
        while (hash_table[hash_value].label_edge != -1) {
            hash_value = nextSlot(hash_value);
        }
        hash_table[hash_value] = *buildInput;
    }

    // probe phase:
    for(int i = 0; i < edges2_size; i++) {
        Edge_sp *probeInput = edges2[i];
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
        Edge_sp *probeInput = edges3[i];
        // build for 2nd hash table:
        int hash_value2 = hash_mod(probeInput->from_node);
        while(hash_table2[hash_value2].label_edge != -1) {
            hash_value2 = nextSlot(hash_value2);
        }
        hash_table2[hash_value2] = *probeInput;
    }

    // second probe phase:
    for (int j = 0; j < result_size; j++) {
        Edge_sp *probeInput = result1[j];
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
//        Edge_sp *probeInput = edges1[i];
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
//        Edge_sp *probeInput = result2[j];
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

    Edge_sp **db_label1 = (Edge_sp **)malloc(sizeof(Edge_sp *) * db->size);
    Edge_sp **db_label2 = (Edge_sp **)malloc(sizeof(Edge_sp *) * db->size);
    Edge_sp **db_label3 = (Edge_sp **)malloc(sizeof(Edge_sp *) * db->size);
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

