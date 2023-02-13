#include <stdio.h>
#include <stdlib.h>

// function that displays the sales report
void printMonthlySales(char** monthsArray, double* salesArray){
    printf("\nMonthly sales report for 2022:");
    printf("\nMonth    \tSales\n");
    // prints values from sales and months arrays
    for (int i = 0; i < 12; i++) {
        printf("%s\t$%.2f\n", monthsArray[i], salesArray[i]);
    }
}

// function that displays minimum, maximum, and average of the monthly sales
void salesSummary(double* salesArray) {
    char* monthsArray[12] = {"January", "February", "March", "April",
    "May", "June", "July", "August", "September","October","November","December"};
    double totalSales = 0;
    int lowestSales = 0;
    int highestSales = 0;
    int lowestMonth = 0;
    int highestMonth = 0;
    // for loop that itirates through sales to count total and find largest and smallest values
    for (int i = 0; i < 12; i++) {
        totalSales += salesArray[i];
        if (i == 0) {
            lowestSales = salesArray[i];
            highestSales = salesArray[i];
        } else {
            if (salesArray[i] < lowestSales) {
                lowestSales = salesArray[i];
                lowestMonth = i;
            }
            if (salesArray[i] > highestSales) {
                highestSales = salesArray[i];
                highestMonth = i;
            }
        }
    }
    
    // printing results
    printf("\nSales summary:\n");
    printf("Minimum sales:\t$%.2f\t(%s)\n", salesArray[lowestMonth], monthsArray[lowestMonth]);
    printf("Maximum sales:\t$%.2f\t(%s)\n", salesArray[highestMonth], monthsArray[highestMonth]);
    printf("Average sales:\t$%.2f\n", totalSales / 12);
}

// function that displays six-month moving averages
void sixMonthMovingAverageReport(char** monthsArray, double* salesArray) {
    double average[12];
    printf("\nSix-Month Moving Average Report:\n");
    // checks average per 6 months sales
    for (int i = 0; i < 7; i++) {
        if (i < 5) {
            average[i] = (salesArray[i] + salesArray[i + 1] + salesArray[i + 2] + salesArray[i + 3] + 
            salesArray[i + 4] + salesArray[i + 5]) / 6;
        } else {
            average[i] = (salesArray[i] + salesArray[i + 1] + salesArray[i + 2] + salesArray[i + 3] + 
            salesArray[i + 4] + salesArray[i + 5]) / 6;
        }
        printf("%s\t- %s\t$%.2f\n", monthsArray[i], monthsArray[i + 5], average[i]);
    }
}

// function that displays monthly sales report from highest to lowest
void salesReport(char** monthsArray, double* salesArray) {
    printf("\nSales Report (Highest to Lowest):");
    printf("\nMonth    \tSales\n");
    double tempSales = 0;
    char* tempMonth[12] = {"January  ", "February", "March   ", "April   ",
    "May      ", "June    ", "July    ", "August  ", "September","October ","November","December"};
    // nested loop to swap score and correlating month values in accending order
    for (int i = 0; i < 12; i++) {     
        for (int j = i+1; j < 12; j++) {     
           if(salesArray[i] < salesArray[j]) {    
               tempSales = salesArray[i];
               tempMonth[i] = monthsArray[i];
               salesArray[i] = salesArray[j];
               monthsArray[i] = monthsArray[j];
               salesArray[j] = tempSales;
               monthsArray[j] = tempMonth[i];
           }
        }
    }

    // prints results
    for (int i = 0; i < 12; i++) {
        printf("%s\t$%.2f\n", monthsArray[i], salesArray[i]);
    }
}

int main()
{
    char* months[12] = {"January  ", "February", "March   ", "April   ",
    "May      ", "June    ", "July    ", "August  ", "September","October ","November","December"};
    double sales[12];
    
    // sets input file to open and checks if valid
    FILE* inputFile;
    inputFile = fopen("monthySalesNumbers.txt", "r");
    if (inputFile == NULL) {
        printf("ERROR: Failure to open input file named 'monthySalesNumbers.txt'.\n");
        return 1;
    }
    
    // input file content for reading
    char inputFileSize[255];
    char* inputFileContent;
    for(int i = 0; i < 12 && fgets(inputFileSize, 255, inputFile) != NULL; i++) {
        sales[i] = strtod(inputFileSize, &inputFileContent);
    }

    // use of functions created above
    printMonthlySales(months, sales);
    salesSummary(sales);
    sixMonthMovingAverageReport(months, sales);
    salesReport(months, sales);
    
    //close input file
    fclose(inputFile);
}
