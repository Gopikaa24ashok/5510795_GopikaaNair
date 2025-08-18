1.Sales by match
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, int ar_count, int* ar) {
    int color_count[101] ={0};
    int pairs = 0;
    for (int i=0;i<n;i++){
        color_count[ar[i]]++;
    }
    for (int i =1;i<=100;i++){
        pairs += color_count[i] / 2;
    }
    return pairs;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** ar_temp = split_string(rtrim(readline()));

    int* ar = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int ar_item = parse_int(*(ar_temp + i));

        *(ar + i) = ar_item;
    }

    int result = sockMerchant(n, n, ar);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

2.Zig Zag Sequence
#include <stdio.h>

int main() {
    int t;  // number of test cases
    printf("Enter number of test cases: ");
    scanf("%d", &t);

    while (t--) {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter array elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int mid = n / 2;

        printf("Zigzag output: ");
        // First half in normal order
        for (int i = 0; i < mid; i++) {
            printf("%d ", arr[i]);
        }

        // Second half in reverse order
        for (int i = n - 1; i >= mid; i--) {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }
    return 0;
}

3.Drawing Book
#include <stdio.h>

int pageCount(int n, int p) {
    int from_front = p / 2;
    int from_back = (n / 2) - (p / 2);
    return (from_front < from_back) ? from_front : from_back;
}

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);
    printf("%d\n", pageCount(n, p));
    return 0;
}

4.Tower Breakers
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'towerBreakers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int towerBreakers(int n, int m) {
    if(m == 1) return 2;
    if (n%2 == 0)return 2;
    return 1;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int n = parse_int(*(first_multiple_input + 0));

        int m = parse_int(*(first_multiple_input + 1));

        int result = towerBreakers(n, m);

        fprintf(fptr, "%d\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}


5.Caesar Cipher
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char* s, int k) {
    k = k % 26;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (isupper(c)) {
            s[i] = ((c - 'A' + k) % 26) + 'A';
        }
        else if (islower(c)) {
            s[i] = ((c - 'a' + k) % 26) + 'a';
        }
    }
}

int main() {
    int n, k;
    char s[105];

    scanf("%d", &n);     // length of string
    scanf("%s", s);      // string input (use %s not %d!)
    scanf("%d", &k);     // shift value

    caesarCipher(s, k);

    printf("%s\n", s);
    return 0;
}

6.Max Min
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxMin(int k, int arr_count, int *arr) {
    qsort(arr, arr_count, sizeof(int), cmpfunc);

    int minimum_unfairness = INT_MAX;
    for (int i = 0; i <= arr_count - k; i++) {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < minimum_unfairness) {
            minimum_unfairness = unfairness;
        }
    }
    return minimum_unfairness;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // read array size and subset size

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxMin(k, n, arr);
    printf("%d\n", result);

    return 0;
}

7.Dynamic Array
#include <stdio.h>
#include <stdlib.h>

int* dynamicArray(int n, int queries_rows, int** queries, int* queries_cols, int* result_count) {
    // create 2D dynamic array of lists
    int **seqList = malloc(n * sizeof(int *));
    int *seqSizes = calloc(n, sizeof(int)); // to track sizes of each list

    for (int i = 0; i < n; i++) {
        seqList[i] = malloc(1000 * sizeof(int)); // allocate enough space
        seqSizes[i] = 0;
    }

    int lastAnswer = 0;
    int *results = malloc(queries_rows * sizeof(int));
    int resIndex = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // append y to seqList[idx]
            seqList[idx][seqSizes[idx]++] = y;
        } else if (type == 2) {
            int size = seqSizes[idx];
            lastAnswer = seqList[idx][y % size];
            results[resIndex++] = lastAnswer;
        }
    }

    *result_count = resIndex;
    return results;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int **queries = malloc(q * sizeof(int *));
    int *queries_cols = malloc(q * sizeof(int));

    for (int i = 0; i < q; i++) {
        queries[i] = malloc(3 * sizeof(int));
        queries_cols[i] = 3;
        scanf("%d %d %d", &queries[i][0], &queries[i][1], &queries[i][2]);
    }

    int result_count;
    int *result = dynamicArray(n, q, queries, queries_cols, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}


8.Grid Challenge
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
 int cmpfunc(const void *a,const void *b){
    return (*(char*)a - *(char *)b);
 }
char* gridChallenge(int grid_count, char** grid) {
    int n= strlen(grid[0]);
    for (int i =0;i<grid_count;i++){
        qsort(grid[i],n,sizeof(char),cmpfunc);
    }
    for (int col =0;col <n;col++){
        for(int row = 1;row<grid_count;row++){
            if(grid[row][col]< grid[row-1][col]){
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char** grid = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            char* grid_item = readline();

            *(grid + i) = grid_item;
        }

        char* result = gridChallenge(n, grid);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}


9.Prime Dates
#include <stdio.h>

int main(void) {
    int d1, m1, y1, d2, m2, y2;
    scanf("%d-%d-%d" , &d1, &m1, &y1);
    scanf("%d-%d-%d", &d2, &m2, &y2);

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int count = 0;

    while (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 <= d2)) {
        long long num= d1;
        num = num*100 +m1;
        num = num *10000+y1;
        if (num % 4 == 0 || num % 7 == 0) count++;

        int dim = daysInMonth[m1 - 1];
        if (m1 == 2 && (y1 % 400 == 0 || (y1 % 4 == 0 && y1 % 100 != 0))) dim = 29;
        d1++;
        if (d1 > dim) { 
            d1 = 1; 
            m1++; 
        if (m1 > 12) {
             m1 = 1; 
             y1++;
              }
    }
    }

    /* print only the number (no extra text/newlines) */
    printf("%d", count);
    return 0;
}

10.Sherlock and Array
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'balancedSums' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* balancedSums(int arr_count, int* arr) {
    long long total_sum =0,left_sum=0;
    int i;
    for(int i =0;i<arr_count;i++){
    total_sum+= arr[i];
    }
     for(int i =0;i<arr_count;i++){
        long long right_sum =total_sum - left_sum-arr[i];
        if(left_sum == right_sum){
            char* ans = malloc(4);
            strcpy(ans,"YES");
            return ans;
        }
        left_sum+= arr[i];
    }
    char* ans = malloc(3+1);
    strcpy(ans,"NO");
        return  ans; 
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int T = parse_int(ltrim(rtrim(readline())));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char** arr_temp = split_string(rtrim(readline()));

        int* arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            int arr_item = parse_int(*(arr_temp + i));

            *(arr + i) = arr_item;
        }

        char* result = balancedSums(n, arr);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}


11.Recursive Digit Sum
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */

int superDigit(char* n, int k) {
    
      long long sum =0;
    for(int i =0;n[i] != '\0';i++){
        sum+=(n[i]-'0');
    }
    sum *=k;
    int result = sum %9;
    if(result ==0 && sum !=0)return 9;
    return result;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    char* n = *(first_multiple_input + 0);

    int k = parse_int(*(first_multiple_input + 1));

    int result = superDigit(n, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}


12.Counter game
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);
long parse_long(char*);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
 bool isPowerofTwo(unsigned long long n){
    return(n && !(n&(n-1)));
 }
 unsigned long long largestPowerofTwo(unsigned long long n){
    unsigned long long p =1;
    while (p<<1<=n){
        p <<=1;
    }
    return p;
 }
char* counterGame(long n) {
    int moves =0;
    unsigned long long num =n;
    while(num >1){
        if (isPowerofTwo(num)){
            num >>=1;
        }else{
            num -= largestPowerofTwo(num);
        }
        moves++;
    }
    if (moves %2 ==1)
        return "Louise";
    else
    return "Richard";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n = parse_long(ltrim(rtrim(readline())));

        char* result = counterGame(n);

        fprintf(fptr, "%s\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}


13.Sum vs XOR
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

long parse_long(char*);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
    if (n == 0)
    return 1;
long count =0;
while(n>0){
    if ((n &1)==0)
    count++;
n >>=1;
}
return 1l << count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    long n = parse_long(ltrim(rtrim(readline())));

    long result = sumXor(n);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

