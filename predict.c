#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// structure representing a single node in the tree - which column it checks, the threshold value to compare against,
// the
struct TreeNode{
    long int column;
    float threshold;
    long int left_child;
    long int right_child;
    float value;
};

float predict(int argc, char *argv[]){
    int ntrees;
    int nrows;
    long int current_node;
    float prediction_sum = 0;
    FILE *binary_file = fopen("forest.bin", "rb");
    fread(&ntrees, sizeof(int), 1, binary_file);

    int i;
    int j;
    float predictors[13];
    for(i=0; i<13; i++){
        predictors[i] = strtof(argv[i+1], NULL);
    };

    long int column;
    float value;
    float threshold;
    for(i=0; i<ntrees; i++){
        fread(&nrows, sizeof(int), 1, binary_file);
        struct TreeNode tree[nrows];
        fread(tree, sizeof(struct TreeNode)*nrows, 1, binary_file);
        
        // work through the 
        current_node = 0;
        while(tree[current_node].column > -1){
            value = predictors[tree[current_node].column];
            threshold = tree[current_node].threshold;
            current_node = value < threshold ? tree[current_node].left_child : tree[current_node].right_child;
        };
        prediction_sum = prediction_sum + tree[current_node].value;
    };
    return(prediction_sum/ntrees);
};

void main(int argc, char *argv[]){
    float prediction;
    prediction = predict(argc, argv);
    printf("Prediction: %f\n", prediction);
}