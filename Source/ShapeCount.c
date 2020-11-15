#include <stddef.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#define FROM 0
#define TO 1

typedef struct Edge_table{
    int label_edge, from_node, to_node;
} Edge_table;

typedef struct SMDB{
    Edge_table **edges;
    int size;
    int max_size;
} SMDB;

typedef void *SortMergeJoinDatabase;
void printDB(struct SMDB *db);


SMDB *connectEdges(const SMDB *first_edges, const SMDB *second_edges,int max);

void InsertEdge(Edge_table *edge, SMDB *db);

SortMergeJoinDatabase SortMergeJoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd){
    struct SMDB *db = (struct SMDB *) malloc(sizeof(struct SMDB));
    Edge_table ** data = (Edge_table **) malloc(sizeof(Edge_table*) * totalNumberOfEdgesInTheEnd);
    db->edges = data;
    db->size = 0;
    db->max_size = (int) totalNumberOfEdgesInTheEnd;
    return (SortMergeJoinDatabase) db;
}

void SortMergeJoinInsertEdge(SortMergeJoinDatabase database, int fromNodeID, int toNodeID,
                             int edgeLabel) {
    Edge_table *edge = (Edge_table *) malloc(sizeof(Edge_table));
    edge->from_node = fromNodeID;
    edge->to_node = toNodeID;
    edge->label_edge = edgeLabel;
    SMDB *db = (SMDB *) database;

    InsertEdge(edge, db);

}

void InsertEdge(Edge_table *edge, SMDB *db) { *(db->edges + db->size++) = edge; }

void swap(Edge_table** a, Edge_table** b)
{
    Edge_table* t = *a;
    *a = *b;
    *b = t;
}


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
    Edge_table **edges = db->edges;
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

typedef struct HashEdge{
    int label, from, to;
} HashEdge;

HashjoinDatabase HashjoinAllocateDatabase(unsigned long totalNumberOfEdgesInTheEnd) {
    HashEdge *data = (HashEdge *) malloc(sizeof(HashEdge) * totalNumberOfEdgesInTheEnd);
    memset(data, 0, sizeof(*data) * totalNumberOfEdgesInTheEnd);
    return (HashjoinDatabase) data;
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
