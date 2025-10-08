/****************************************************
 1. Linear Search with Count
****************************************************/
#include <stdio.h>

int main1() {
    int n, key, count = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    printf("Positions: ");
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            printf("%d ", i);
            count++;
        }
    }

    if(count == 0)
        printf("Not found");
    else
        printf("\nFound %d times.\n", count);

    return 0;
}

/****************************************************
 2. Binary Search (Iterative with trace)
****************************************************/
int main2() {
    int n, key;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array: ");
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    int low=0,high=n-1,mid,step=1;
    while(low<=high){
        mid=(low+high)/2;
        printf("Step %d → low=%d high=%d mid=%d\n", step++, low, high, mid);
        if(arr[mid]==key){ printf("Found at %d\n", mid); return 0; }
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    printf("Not found\n");
    return 0;
}

/****************************************************
 3. Jump Search vs Linear Search
****************************************************/
#include <math.h>
#include <time.h>
int linearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++) if(arr[i]==x) return i;
    return -1;
}
int jumpSearch(int arr[],int n,int x){
    int step=sqrt(n),prev=0;
    while(arr[(step<n?step:n)-1]<x){
        prev=step;
        step+=sqrt(n);
        if(prev>=n) return -1;
    }
    while(arr[prev]<x){
        prev++;
        if(prev>=n) return -1;
    }
    return (arr[prev]==x)?prev:-1;
}
int main3(){
    int n=10000,arr[n],x=9999;
    for(int i=0;i<n;i++) arr[i]=i;
    clock_t start,end;

    start=clock();
    linearSearch(arr,n,x);
    end=clock();
    double t1=(double)(end-start)/CLOCKS_PER_SEC;

    start=clock();
    jumpSearch(arr,n,x);
    end=clock();
    double t2=(double)(end-start)/CLOCKS_PER_SEC;

    printf("Linear Search time: %f\n",t1);
    printf("Jump Search time: %f\n",t2);
    return 0;
}

/****************************************************
 4. Interpolation vs Binary Search (step counts)
****************************************************/
int interpolationSearch(int arr[],int n,int x,int *steps){
    int low=0,high=n-1;
    while(low<=high && x>=arr[low] && x<=arr[high]){
        (*steps)++;
        int pos=low+(((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));
        if(arr[pos]==x) return pos;
        if(arr[pos]<x) low=pos+1; else high=pos-1;
    }
    return -1;
}
int binarySearchSteps(int arr[],int n,int x,int *steps){
    int low=0,high=n-1;
    while(low<=high){
        (*steps)++;
        int mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main4(){
    int n=1000,arr[n],x=700,steps1=0,steps2=0;
    for(int i=0;i<n;i++) arr[i]=i;
    interpolationSearch(arr,n,x,&steps1);
    binarySearchSteps(arr,n,x,&steps2);
    printf("Interpolation steps: %d\n",steps1);
    printf("Binary Search steps: %d\n",steps2);
    return 0;
}

/****************************************************
 5. Exponential Search
****************************************************/
int binarySearchRange(int arr[],int l,int r,int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid]<x) l=mid+1; else r=mid-1;
    }
    return -1;
}
int exponentialSearch(int arr[],int n,int x){
    if(arr[0]==x) return 0;
    int i=1;
    while(i<n && arr[i]<=x) i=i*2;
    return binarySearchRange(arr,i/2,(i<n?i:n-1),x);
}
int main5(){
    int n=100,arr[n];
    for(int i=0;i<n;i++) arr[i]=i*2;
    int x=64;
    int res=exponentialSearch(arr,n,x);
    if(res!=-1) printf("Found at %d\n",res);
    else printf("Not found\n");
    return 0;
}

/****************************************************
 6. Bubble Sort with Optimization
****************************************************/
int main6(){
    int arr[]={5,4,3,2,1};
    int n=5,pass=0;
    // normal bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];arr[j]=arr[j+1];arr[j+1]=temp;
            }
        }
        pass++;
    }
    printf("Normal Bubble Sort passes: %d\n",pass);

    int arr2[]={5,4,3,2,1},pass2=0,swapped;
    for(int i=0;i<n-1;i++){
        swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr2[j]>arr2[j+1]){
                int t=arr2[j];arr2[j]=arr2[j+1];arr2[j+1]=t;
                swapped=1;
            }
        }
        pass2++;
        if(!swapped) break;
    }
    printf("Optimized Bubble Sort passes: %d\n",pass2);
    return 0;
}

/****************************************************
 7. Selection Sort & Stability Check
****************************************************/
struct Student{int roll;int marks;};
int main7(){
    struct Student s[]={{1,50},{2,40},{3,40},{4,60}};
    int n=4;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(s[j].marks<s[min].marks) min=j;
        }
        if(min!=i){
            struct Student t=s[i];s[i]=s[min];s[min]=t;
        }
    }
    printf("After Selection Sort:\n");
    for(int i=0;i<n;i++) printf("Roll:%d Marks:%d\n",s[i].roll,s[i].marks);
    // if students with same marks (roll 2 & 3) swapped, then unstable
    return 0;
}

/****************************************************
 8. Insertion Sort (Playing Card Analogy)
****************************************************/
int main8(){
    int arr[]={5,3,4,1,2},n=5;
    for(int i=1;i<n;i++){
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        printf("Step %d: ",i);
        for(int k=0;k<n;k++) printf("%d ",arr[k]);
        printf("\n");
    }
    return 0;
}

/****************************************************
 9. Merge Sort with Messages
****************************************************/
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
    printf("Merged from %d to %d\n",l,r);
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main9(){
    int arr[]={5,2,4,7,1,3,2,6},n=8;
    mergeSort(arr,0,n-1);
    printf("Sorted: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}

/****************************************************
 10. Quick Sort (Worst-case count)
****************************************************/
int comparisons=0;
int partition(int arr[],int low,int high){
    int pivot=arr[low],i=low+1,j=high;
    while(1){
        while(i<=high && arr[i]<=pivot){i++;comparisons++;}
        while(j>=low && arr[j]>pivot){j--;comparisons++;}
        if(i<j){int t=arr[i];arr[i]=arr[j];arr[j]=t;}
        else break;
    }
    int t=arr[low];arr[low]=arr[j];arr[j]=t;
    return j;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main10(){
    int arr1[]={3,7,8,5,2,1,9,5,4},n1=9;
    quickSort(arr1,0,n1-1);
    printf("Random array comparisons:%d\n",comparisons);

    comparisons=0;
    int arr2[]={1,2,3,4,5,6,7,8,9};
    quickSort(arr2,0,8);
    printf("Sorted array comparisons:%d\n",comparisons);
    return 0;
}

/****************************************************
 11. Fixed-Size Stack (Function Call Simulation)
****************************************************/
#define MAX 5
int stack[MAX],top=-1;
void push(int val){
    if(top==MAX-1) printf("Stack Overflow\n");
    else stack[++top]=val;
}
void pop(){
    if(top==-1) printf("Stack Underflow\n");
    else printf("Popped return addr %d\n",stack[top--]);
}
void display(){
    printf("Stack: ");
    for(int i=0;i<=top;i++) printf("%d ",stack[i]);
    printf("\n");
}
int main11(){
    push(100);push(200);display();
    pop();display();
    pop();pop();
    return 0;
}

/****************************************************
 12. Dynamic Stack (Browser History using Linked List)
****************************************************/
#include <stdlib.h>
struct Node{char url[50];struct Node* next;};
struct Node* topNode=NULL;
void pushURL(char* url){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url,url);
    newNode->next=topNode;
    topNode=newNode;
}
void popURL(){
    if(topNode==NULL){printf("No history!\n");return;}
    printf("Back from %s\n",topNode->url);
    struct Node* temp=topNode;
    topNode=topNode->next;
    free(temp);
}
void showHistory(){
    struct Node* t=topNode;
    printf("History: ");
    while(t){printf("%s -> ",t->url);t=t->next;}
    printf("NULL\n");
}
int main12(){
    pushURL("google.com");pushURL("youtube.com");showHistory();
    popURL();showHistory();
    return 0;
}

/****************************************************
 13. Circular Buffer Stack
****************************************************/
#define SIZE 5
int buffer[SIZE],head=0,count=0;
void pushCirc(int val){
    buffer[head]=val;
    head=(head+1)%SIZE;
    if(count<SIZE) count++;
}
void showCirc(){
    printf("Buffer: ");
    for(int i=0;i<count;i++) printf("%d ",buffer[(head-i-1+SIZE)%SIZE]);
    printf("\n");
}
int main13(){
    for(int i=1;i<=7;i++){pushCirc(i);showCirc();}
    return 0;
}

/****************************************************
 14. Priority Stack – Task Scheduler
****************************************************/
struct Task{int id;int priority;};
struct Task tstack[50];int ttop=-1;
void pushTask(int id,int p){ tstack[++ttop]=(struct Task){id,p}; }
void popTask(){
    if(ttop==-1){printf("Empty\n");return;}
    int idx=0;
    for(int i=1;i<=ttop;i++){
        if(tstack[i].priority>tstack[idx].priority ||
          (tstack[i].priority==tstack[idx].priority && i==ttop)) idx=i;
    }
    printf("Executing Task %d priority %d\n",tstack[idx].id,tstack[idx].priority);
    for(int i=idx;i<ttop;i++) tstack[i]=tstack[i+1];
    ttop--;
}
int main14(){
    pushTask(1,2);pushTask(2,5);pushTask(3,5);pushTask(4,1);
    popTask();popTask();popTask();
    return 0;
}

/****************************************************
 15. Undo Stack – Text Editor
****************************************************/
char doc[100]="";
char undoStack[10][100];int uTop=-1;
void saveState(){ strcpy(undoStack[++uTop],doc); }
void writeText(char* text){
    saveState();
    strcat(doc,text);
    printf("Doc: %s\n",doc);
}
void undo(){
    if(uTop==-1){printf("Nothing to undo\n");return;}
    strcpy(doc,undoStack[uTop--]);
    printf("Undo → %s\n",doc);
}
int main15(){
    writeText("Hello ");
    writeText("World");
    undo();undo();undo();
    return 0;
}

/****************************************************
 16. Double Stack in One Array
****************************************************/
#define MAX2 10
int stackArr[MAX2],top1=-1,top2=MAX2;
void push1(int val){ if(top1<top2-1) stackArr[++top1]=val; else printf("Overflow\n"); }
void push2(int val){ if(top1<top2-1) stackArr[--top2]=val; else printf("Overflow\n"); }
void pop1(){ if(top1>=0) printf("Pop1 %d\n",stackArr[top1--]); else printf("Underflow1\n"); }
void pop2(){ if(top2<MAX2) printf("Pop2 %d\n",stackArr[top2++]); else printf("Underflow2\n"); }
void display2(){
    printf("Array: ");
    for(int i=0;i<MAX2;i++) printf("%d ",stackArr[i]);
    printf("\nTop1=%d Top2=%d\n",top1,top2);
}
int main16(){
    push1(1);push2(9);push1(2);display2();
    pop1();pop2();display2();
    return 0;
}
