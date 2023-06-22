/**  ***LEVEL-2*** 
  
   1. Data Parser:
   A data logger transmits the data in ascii format as shown below
   "S1-T:36.5-H:100-L:50"
   Write a function to populate all the data in an array of structure. The output should be like
   Sensor Info:
   ---------------------
   Sensor ID: S1
   Temperature: 36.5 C
   Humidity: 100
   Light Intensity: 50%  **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SensorInfo {
    char sensorId;
    double temperature;
    int humidity;
    int light;
};

void parseData(const char* data, struct SensorInfo* sensorInfo) {
    // Tokenize the input data using "-" and ":"
    char* token = strtok(data, "-:");

    while (token != NULL) {
        if (token[0] == 'S') {
            // Parse sensor ID
            sensorInfo->sensorId = token[1];
        } else if (token[0] == 'T') {
            // Parse temperature
            token = strtok(NULL, "-:");
            sensorInfo->temperature = atof(token);
        } else if (token[0] == 'H') {
            // Parse humidity
            token = strtok(NULL, "-:");
            sensorInfo->humidity = atoi(token);
        } else if (token[0] == 'L') {
            // Parse light
            token = strtok(NULL, "-:");
            sensorInfo->light = atoi(token);
        }

        token = strtok(NULL, "-:");
    }
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensorInfo;

    // Parse the data and populate the sensorInfo structure
    parseData(data, &sensorInfo);

    // Display the parsed sensor information
    printf("Sensor Info:\n");
    printf("Sensor ID: %c\n", sensorInfo.sensorId);
    printf("Temperature: %.2f\n", sensorInfo.temperature);
    printf("Humidity: %d\n", sensorInfo.humidity);
    printf("Light: %d\n", sensorInfo.light);

    return 0;
}