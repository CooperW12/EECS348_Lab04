#include <stdio.h>


//temp conversion functions
float FtoC (float temp){
    return ((temp - 32) * 5 / 9);
}

float CtoK (float temp){
    return temp + 273.15;
}

float KtoF (float temp){
    return ((temp - 273.15) * 9 / 5 + 32);
}

float CtoF (float temp){
    return (temp * 9 / 5 + 32);
}

float KtoC (float temp){
    return temp - 273.1;
}

float FtoK (float temp){
    return (((temp - 32) * 5 / 9) + 273.15);
}

//categorize temperature
char * tempCat (float tempInC){
    if (tempInC <= 0){
        return "Freezing";
    }
    else if (tempInC > 0 && tempInC <= 10){
        return "Cold";
    }
    else if (tempInC > 10 && tempInC <= 25){
        return "Comfortable";
    }
    else if (tempInC > 25 && tempInC <= 35){
        return "Hot";
    }
    else {
        return "Extreme Heat";
    }
}

int main(){

//initialize variables
int inputScaleIn, outputScaleIn;
float temp, outTemp;
char inputScale = 0;
char outputScale = 0;
int validIn = 0;

//loop until valid input
while (validIn == 0){
    printf("enter temperature: ");
    scanf("%f", &temp);
    getchar();

    printf("enter input scale (1)Celcius (2)Farenheit (3)Kelvin): ");
    scanf("%d", &inputScaleIn);
    getchar();

    printf("enter target scale (1)Celcius (2)Farenheit (3)Kelvin): ");
    scanf("%d", &outputScaleIn);
    getchar();

    //set input scale to temp symbol
    if (inputScaleIn == 1){
        inputScale = 'C';
    }
    else if (inputScaleIn == 2){
        inputScale = 'F';
    }
    else if (inputScaleIn == 3){
        inputScale = 'K';
    }
    else{
        printf("Detected input scale error. please enter 1,2, or 3 next time \n");
    }

    //set output scale to temp symbol
    if (outputScaleIn == 1){
        outputScale = 'C';
    }
    else if (outputScaleIn == 2){
        outputScale = 'F';
    }
    else if (outputScaleIn == 3){
        outputScale = 'K';
    }
    else{
        printf("Detected output scale error. please enter 1,2, or 3 next time \n");
    }

    //check fot valid input
    if (inputScale != 0 && outputScale != 0 ){
        validIn = 1;
    }

    //make sure input and output scales arent the same
    if (inputScaleIn == outputScaleIn){
        validIn = 0;
        printf("Input scale and output scale should be 1,2, or 3 and shouldnt be the same \n");
    }

    //check for negative K values
    if (inputScale == 'K' && temp < 0){
        validIn = 0;
        printf("Kelven cannot have negative value \n");
    }
}

//convert
if (inputScale == 'F' && outputScale == 'C'){
    outTemp =  FtoC(temp);
}
else if (inputScale == 'C' && outputScale == 'K'){
    outTemp = CtoK(temp);
}
else if (inputScale == 'K' && outputScale == 'F'){
    outTemp = KtoF(temp);
}
else if (inputScale == 'C' && outputScale == 'F'){
    outTemp = CtoF(temp);
}
else if (inputScale == 'K' && outputScale == 'C'){
    outTemp = KtoC(temp);
}
else if (inputScale == 'F' && outputScale == 'K'){
    outTemp = FtoK(temp);
}

//print converted temp
printf("Converted Temperature: ");
printf("%.2f",outTemp);
printf("%c", outputScale);
printf("\n");

//change to celcius for categorization
float tempInC;
if (outputScale == 'F'){
    tempInC = FtoC(outTemp);
}
else if (outputScale == 'C'){
    tempInC = outTemp;
}
else if (outputScale == 'K'){
    tempInC = KtoC(outTemp);
}

//print category
char *tempCategory;
tempCategory = tempCat(tempInC);
printf("Temperature category: ");
printf("%s", tempCategory);
printf("\n");

//set advice
char *advice;
if (tempCategory == "Freezing"){
    advice = "Stay indoors";
}
else if (tempCategory == "Cold"){
    advice = "Wear a jacket";
}
else if (tempCategory == "Comfortable"){
    advice = "Go outside";
}
else if (tempCategory == "Hot"){
    advice = "Turn on the AC";
}
else {
    advice = "Drink water and stay inside";
}

//print advice
printf("Advice: ");
printf("%s", advice);
printf("\n");

return 0;
}