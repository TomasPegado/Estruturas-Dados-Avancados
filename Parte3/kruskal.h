struct subset {
    int parent;
    int rank;
};

struct Edge {
    int src, dest, weight;
};

int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);