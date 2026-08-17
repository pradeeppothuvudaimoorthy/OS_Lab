#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int req[20], n, head, max_cylinder, i, seek = 0;
    printf("Enter Number of Requests: ");
    scanf("%d", &n);
    printf("Enter Request Queue:\n");
    for(i=0; i<n; i++) scanf("%d", &req[i]);
    printf("Enter Initial Head Position: ");
    scanf("%d", &head);
    printf("Enter Max Cylinder Size: ");
    scanf("%d", &max_cylinder);
    
    req[n] = head;
    req[n+1] = max_cylinder;
    req[n+2] = 0;
    n += 3;
    qsort(req, n, sizeof(int), compare);
    
    int index;
    for(i=0; i<n; i++) {
        if(req[i] == head) {
            index = i;
            break;
        }
    }
    
    // Circular SCAN
    seek = (max_cylinder - head) + max_cylinder + req[index-1];
    printf("Total Head Movement = %d\n", seek);
    return 0;
}