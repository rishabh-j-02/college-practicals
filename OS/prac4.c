#include <stdio.h>
#include <pthread.h>

int m3[3][3];
int m1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};    
int m2[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
int row = 0;

void* matMultiply(){
    int i = row;
    for(int j =0; j < 3; j++){
        for (int k = 0; k < 3; k++){
            m3[i][j] += m1[i][k] * m2[k][j];     
        }
    }
    i++;
}

void fillmat(int m[3][3], int val){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            m[i][j] = val;
        }
    }
}

void printMatrix(int m[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {

    fillmat(m3, 0);
    printMatrix(m3);
    
    pthread_t th1, th2, th3;
    int *p1, *p2, *p3;
    
    int v; 
    v = pthread_create(&th1, NULL, matMultiply(), (void *)p1);
    printf("%d\n", v);
    v = pthread_create(&th2, NULL, matMultiply(), (void *)p2);
    printf("%d\n", v);
    v = pthread_create(&th3, NULL, matMultiply(), (void *)p3);
    printf("%d\n", v);

    v = pthread_join(th1, NULL);
    printf("%d\n", v);

    v = pthread_join(th2, NULL);
    printf("%d\n", v);

    v = pthread_join(th3, NULL);
    printf("%d\n", v);

    return 0;
}