1.plus minus

void plusMinus(int arr_count, int* arr) {
    int positive = 0, negative =0,zero=0;
    for (int i = 0; i< arr_count;i++){
        if(arr[i] > 0)
        positive++;
        else if(arr[i] < 0)
        negative++;
        else
        zero++;
          }
    printf("%f\n", (float)positive /arr_count);
    printf("%f\n", (float)negative /arr_count);
    printf("%f\n", (float)zero /arr_count);
}

    


int main ()  
{
    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    plusMinus(n, arr);

    return 0;
}

2.Min_max sum
void miniMaxSum(int arr_count, int* arr) {
    long total = 0;
    int min = arr[0];
    int max =arr[0];
    for (int i =0; i < arr_count;i++){
        total += arr[i];
        if (arr[i] < min)
           min = arr[i];
        if (arr[i] > max)
           max = arr[i];
    }
    long min_sum = total-max;
    long max_sum = total-min;
    printf ("%ld %ld\n", min_sum,max_sum);    

}

int main()
{

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    miniMaxSum(5, arr);

    return 0;
}

3.Time Conversion
char* timeConversion(char* s) {
    static char result [9];
    int hour;
    char period[3];
    sscanf(s, "%2d:%*2d:%*2d%2s", &hour, period );
    if(strncmp(period, "AM", 2)==0){
        if (hour == 12) hour = 0;
    }else{
        if (hour != 12) hour+=12;
    }
    
    snprintf(result, sizeof(result), "%02d%s", hour, s+2);
    result[8] ='\0';
    return result;
    }

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}


4.Spare Arrays
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int *result =malloc(queries_count *sizeof (int));
    for (int i=0; i< queries_count; i++){
        result[i] =0;
        for (int j =0 ;j < strings_count; j++){
            if (strcmp(queries[i], strings[j] )== 0){
                result[i]++;
            }
        }
    }
    *result_count = queries_count;
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int strings_count = parse_int(ltrim(rtrim(readline())));

    char** strings = malloc(strings_count * sizeof(char*));

    for (int i = 0; i < strings_count; i++) {
        char* strings_item = readline();

        *(strings + i) = strings_item;
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    char** queries = malloc(queries_count * sizeof(char*));

    for (int i = 0; i < queries_count; i++) {
        char* queries_item = readline();

        *(queries + i) = queries_item;
    }


5.Lonely Integer
int lonelyinteger(int a_count, int* a) {
    int num =0;
    for (int i =0;i<a_count;i++){
        num ^=a[i];
        
    }
    return num;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int a_item = parse_int(*(a_temp + i));

        *(a + i) = a_item;
    }

    int result = lonelyinteger(n, a);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

6.Flipping bits
long flippingBits(long n) {
    return n^ 0xFFFFFFFF;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n = parse_long(ltrim(rtrim(readline())));

        long result = flippingBits(n);

        fprintf(fptr, "%ld\n", result);
    }

    fclose(fptr);

    return 0;
}

7.Diagonal Difference

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int primary =0,secondary =0;
    for (int i =0 ;i <arr_rows; i++){
        primary += arr[i][i];
        secondary += arr[i][arr_columns-i-1];
    }
    int num = primary - secondary;
    if(num <0) num = -num;
    return num;
    

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int** arr = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(arr + i) = malloc(n * (sizeof(int)));

        char** arr_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < n; j++) {
            int arr_item = parse_int(*(arr_item_temp + j));

            *(*(arr + i) + j) = arr_item;
        }
    }

8.counting sort 1
int* countingSort(int arr_count, int* arr, int* result_count) {
    int* freq =calloc(100,sizeof(int));
    for (int i=0;i<arr_count; i++){
        freq[arr[i]]++;
    }
    * result_count =100;
    return freq;
    
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }


9.pangrams
char* pangrams(char* s) {
    int alphabets[26] = {0};
    int num =0;
    for (int i =0;s[i] !='\0';i++){
        char c = tolower(s[i]);//tolower converts to lower case
        if (c>= 'a' && c<= 'z'){
            int index =c- 'a';
            if(alphabets[index] == 0){
                alphabets[index] = 1;
                num ++;
            }
        }
        
    }
    if(num == 26)
    return "pangram";
    else 
     return "not pangram";

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = pangrams(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}
10.permuting two arrays
char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    for (int i =0;i< A_count-1;i++){
        for (int j=i+1;j<A_count;j++){
            if(A[i] >A[j]){
                int temp = A[i];
                A[i] =A[j];
                A[j] = temp;
            }
        }
    }
    for(int i =0;i<B_count-1;i++){
        for (int j=i+1;j<B_count;j++){
            if(B[i] < B[j]){
                int temp = B[i];
                B[i] =B[j];
                B[j] = temp;
    }
   }
    }
    for (int i=0;i<A_count;i++){
        if(A[i] + B[i] < k)
        return "NO";
    }
    return "YES";

}

11.subarray diivison 1
int birthday(int s_count, int* s, int d, int m) {
    int ways = 0;
    for (int i = 0;i <=s_count-m; i++){
        int sum = 0;
        for (int j = 0;j<m;j++){
            sum+= s[i+j];
            
        }
        if (sum == d){
            ways++;
        }
    }
    return ways;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** s_temp = split_string(rtrim(readline()));

    int* s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int s_item = parse_int(*(s_temp + i));

        *(s + i) = s_item;
    }
12.xor stringa 2int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char a[10001], b[10001];
    scanf("%s",a);
    scanf("%s",b);
    for (int i=0;a[i]!='\0';i++){
        putchar(a[i] == b[i]?'0':'1');
    }
    putchar('\n');
    return 0;
}





