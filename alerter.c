#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
void PrintTemp(float celcius);

int networkAlertStub(float celcius) {
    PrintTemp(celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius<=200)
        return 200;
    else
        return 500;
}

void PrintTemp(float celcius)
{
   printf("ALERT: Temperature is %.1f celcius.\n", celcius);
}
    

float FarenheitToCelsius(float farenheit)
{
     float celcius = (farenheit - 32) * 5 / 9;
     return celcius;
}

void alertInCelcius(float farenheit) {
    float celcius=FarenheitToCelsius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(572);
    assert(alertFailureCount==2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
