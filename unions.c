#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum devices {
    DIGITAL, ANALOG, PRECISION, MANUAL
} device_type;

union data {
    int loadEstimate;
    float loadRating;
    double loadFactor;
    char loadStatus[10];
};

typedef union data data_u;

struct device_status {
    unsigned int online : 1;
    unsigned int inCatalog : 1;
    device_type device;
    data_u devices_readout;
};

typedef struct device_status device_t;

device_t * createDevice(unsigned int online, unsigned int inCatalog, void *data, device_type device) {
    device_t * newDevice = malloc(sizeof(device_t));
    newDevice->device = device;
    newDevice->inCatalog = inCatalog;
    newDevice->online = online;
    switch(device) {
        case DIGITAL:
            newDevice->devices_readout.loadEstimate = *((int *) data);
            break;
        case ANALOG:
            newDevice->devices_readout.loadRating = *((float *) data);
            break;
        case PRECISION:
            newDevice->devices_readout.loadFactor = *((double *) data);
            break;
        case MANUAL:
            strcpy(newDevice->devices_readout.loadStatus, (char *) data);
            break;
    }
    return newDevice;
}

void printDevice(device_t * device) {
    char onlineStatus[8];
    char catalogStatus[20];
    char device_type[20];
    char readout[20];
    if (device->online) {
        strcpy(onlineStatus, "Online");
    } else {
        strcpy(onlineStatus, "Offline");
    }
    if (device->inCatalog) {
        strcpy(catalogStatus, "Cataloged");
    } else {
        strcpy(catalogStatus, "Not Cataloged");
    }
    switch(device->device) {
        case DIGITAL:
            strcpy(device_type, "Digital");
            sprintf(readout, "%d", device->devices_readout.loadEstimate);
            break;
        case ANALOG:
            strcpy(device_type, "Analog");
            sprintf(readout, "%f", device->devices_readout.loadRating);
            break;
        case PRECISION:
            strcpy(device_type, "Precision");
            sprintf(readout, "%lf", device->devices_readout.loadFactor);
            break;
        case MANUAL:
            strcpy(device_type, "Manual");
            strcpy(readout, device->devices_readout.loadStatus);
            break;
    }


    printf("Status: %s\n", onlineStatus);
    printf("Is it cataloged? %s\n", catalogStatus);
    printf("Device Type: %s\n", device_type);
    printf("Device Readout: %s\n", readout);
}

void destroyDevice(device_t * device) {
    free(device);
}

int main(void) {
    device_t * myDevice = malloc(sizeof(device_t));
    char myData[20] = "Happy Monday";
    myDevice = createDevice(1, 1, myData, MANUAL);
    printDevice(myDevice);
    destroyDevice(myDevice);


}