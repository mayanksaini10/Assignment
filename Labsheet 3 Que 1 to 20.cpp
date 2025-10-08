#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Struct for employee details
struct Employee {
    char name[50];
    int age;
    float salary;
};

// 2. Union example
union Data {
    int i;
    float f;
};

// 3. Pointer to swap two integers
void swapPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 4. Double pointer to allocate 2D array
int** allocate2D(int rows, int cols) {
    int **arr = (int**)malloc(rows * sizeof(int*));
    for(int i=0;i<rows;i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    return arr;
}

// 5. Swap using call by value (fails)
void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// 6. Swap using call by reference (works)
void swapReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 7. Nested function simulation
int add(int a, int b) { return a+b; }
int multiply(int a, int b) { return a*b; }

// 8. Max value from array
int maxArray(int arr[], int n) {
    int max = arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>max) max = arr[i];
    return max;
}

// 9. Modify variable via pointer
void modifyValue(int *x) {
    *x = *x + 10;
}

// 10. Passing struct with pointer
struct Box {
    int *value;
};
void modifyBox(struct Box *b) {
    *(b->value) += 5;
}

// 11. Pointer arithmetic in array
void traverseArray(int *arr, int n) {
    for(int i=0;i<n;i++)
        printf("%d ", *(arr+i));
    printf("\n");
}

// 12. Struct for book with dynamic allocation
struct Book {
    char title[50];
    char author[50];
    float price;
};

// 13. Return pointer to largest element
int* largestElement(int *arr, int n) {
    int *max = &arr[0];
    for(int i=1;i<n;i++)
        if(arr[i] > *max) max = &arr[i];
    return max;
}

// 14. Array of pointers to strings
void inputNames() {
    char *names[5];
    for(int i=0;i<5;i++) {
        names[i] = (char*)malloc(50*sizeof(char));
        printf("Enter name %d: ", i+1);
        scanf("%s", names[i]);
    }
    printf("Names are:\n");
    for(int i=0;i<5;i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }
}

// 15. Struct car with pointer
struct Car {
    char model[50];
    int year;
    float price;
};

// 16. Struct with union
struct Mixed {
    int type;
    union {
        int x;
        float y;
    } data;
};

// 17. Function pointer arithmetic
int addOp(int a, int b){ return a+b; }
int subOp(int a, int b){ return a-b; }
int mulOp(int a, int b){ return a*b; }

// 18. Sum of 2D array
int sum2D(int arr[3][3], int rows, int cols) {
    int sum=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            sum += arr[i][j];
    return sum;
}

// 19. Recursive factorial with pointer
void factorial(int n, int *result) {
    if(n==0 || n==1) {
        *result = 1;
        return;
    }
    int temp;
    factorial(n-1, &temp);
    *result = n * temp;
}

// 20. Struct student sorting
struct Student {
    char name[50];
    int marks;
};

void sortStudents(struct Student s[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(s[i].marks < s[j].marks) {
                struct Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    printf("========= PROGRAM DEMONSTRATIONS =========\n");

    // 1. Struct employee
    struct Employee e[3] = {
        {"Alice", 25, 45000},
        {"Bob", 30, 50000},
        {"Charlie", 28, 47000}
    };
    printf("\n1. Employee Details:\n");
    for(int i=0;i<3;i++)
        printf("%s %d %.2f\n", e[i].name, e[i].age, e[i].salary);

    // 2. Union
    union Data d;
    d.i = 10;
    printf("\n2. Union int: %d\n", d.i);
    d.f = 3.14;
    printf("Union float (overwrites int): %.2f\n", d.f);

    // 3. Swap using pointer
    int a=5,b=10;
    swapPointer(&a,&b);
    printf("\n3. Swapped values: a=%d b=%d\n",a,b);

    // 4. 2D array allocation
    int **arr = allocate2D(2,2);
    arr[0][0]=1; arr[0][1]=2; arr[1][0]=3; arr[1][1]=4;
    printf("\n4. 2D Array values: %d %d %d %d\n", arr[0][0],arr[0][1],arr[1][0],arr[1][1]);

    // 5. Swap call by value
    a=5;b=10;
    swapValue(a,b);
    printf("\n5. Call by Value swap fails: a=%d b=%d\n",a,b);

    // 6. Swap call by reference
    swapReference(&a,&b);
    printf("\n6. Call by Reference swap works: a=%d b=%d\n",a,b);

    // 7. Function pointer
    int (*func)(int,int) = add;
    printf("\n7. Add using function pointer: %d\n", func(3,4));
    func = multiply;
    printf("Multiply using function pointer: %d\n", func(3,4));

    // 8. Max value
    int arr2[5] = {10, 50, 30, 90, 70};
    printf("\n8. Max value = %d\n", maxArray(arr2,5));

    // 9. Modify variable
    int x=20;
    modifyValue(&x);
    printf("\n9. Modified value: %d\n", x);

    // 10. Struct with pointer
    struct Box b1;
    int val=100;
    b1.value=&val;
    modifyBox(&b1);
    printf("\n10. Modified struct value: %d\n", val);

    // 11. Pointer arithmetic
    printf("\n11. Traversing array:\n");
    traverseArray(arr2,5);

    // 12. Book allocation
    struct Book *books = (struct Book*)malloc(5*sizeof(struct Book));
    for(int i=0;i<5;i++) {
        sprintf(books[i].title, "Book%d", i+1);
        sprintf(books[i].author, "Author%d", i+1);
        books[i].price = 100+i*10;
    }
    printf("\n12. Books:\n");
    for(int i=0;i<5;i++)
        printf("%s by %s - %.2f\n", books[i].title, books[i].author, books[i].price);
    free(books);

    // 13. Largest element
    int *max = largestElement(arr2,5);
    printf("\n13. Largest element: %d\n", *max);

    // 14. Input names
    printf("\n14. Input and display names:\n");
    inputNames();

    // 15. Car struct
    struct Car c1={"BMW",2020,50000};
    struct Car *pc=&c1;
    pc->year=2022;
    printf("\n15. Car: %s %d %.2f\n", pc->model, pc->year, pc->price);

    // 16. Struct with union
    struct Mixed m;
    m.type=1;
    m.data.x=10;
    printf("\n16. Union in struct: %d\n", m.data.x);

    // 17. Function pointer arithmetic
    int (*op)(int,int);
    op=addOp;
    printf("\n17. Add = %d\n", op(5,3));
    op=subOp;
    printf("Subtract = %d\n", op(5,3));
    op=mulOp;
    printf("Multiply = %d\n", op(5,3));

    // 18. Sum of 2D array
    int arr3[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    printf("\n18. Sum of 2D array = %d\n", sum2D(arr3,3,3));

    // 19. Recursive factorial
    int result;
    factorial(5,&result);
    printf("\n19. Factorial of 5 = %d\n", result);

    // 20. Sort students
    struct Student s[3] = {
        {"John", 80},
        {"Alice", 95},
        {"Bob", 85}
    };
    sortStudents(s,3);
    printf("\n20. Sorted Students by marks:\n");
    for(int i=0;i<3;i++)
        printf("%s %d\n", s[i].name, s[i].marks);

    return 0;
}
