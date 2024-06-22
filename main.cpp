#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, aSize;
    int *randomNums;
    time_t t;
    double total = 0;
    int biggest, smallest;
    float average;

    srand(time(&t));

    printf("Ile liczb losowych chcesz zapisac w tablicy? ");
    scanf("%d", &aSize);

    // alokacja tablicy tylu liczb całkowitych, ile zażądał użytkownik
    randomNums = (int *)malloc(aSize * sizeof(int));

    // sprawdzenie czy tablica została prawidłowo alokowana
    if (!randomNums) {
        printf("Nie udało się alokować tablicy!\n");
        exit(1);
    }

    // przegląda tablicę i przypisuje jej elementom
    // losowe liczby z przedziału od 1 do 500
    for (i = 0; i < aSize; i++) {
        randomNums[i] = (rand() % 500) + 1;
    }

    printf("Tablica przed sortowaniem:\n");
    for (i = 0; i < aSize; i++) {
        printf("%d ", randomNums[i]);
    }
    printf("\n");


    // Sortowanie tablicy za pomocą sortowania bąbelkowego
    for (i = 0; i < aSize - 1; i++) {
        for (j = 0; j < aSize - i - 1; j++) {
            if (randomNums[j] > randomNums[j + 1]) {
                // Zamiana miejscami
                int temp = randomNums[j];
                randomNums[j] = randomNums[j + 1];
                randomNums[j + 1] = temp;
            }
        }
    }

    printf("Posortowana tablica:\n");
    for (i = 0; i < aSize; i++) {
        printf("%d ", randomNums[i]);
    }
    printf("\n");

    biggest = randomNums[aSize - 1];
    smallest = randomNums[0];

    for (i = 0; i < aSize; i++) {
        total += randomNums[i];
    }

    average = ((float)total) / ((float)aSize);

    printf("Najwieksza liczba: %d.\n", biggest);
    printf("Najmniejsza liczba: %d.\n", smallest);
    printf("Srednia: %.2f.\n", average);

    free(randomNums);
    return (0);
}
