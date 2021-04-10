// A32NX_EFIS_PANEL.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Windows.h is necessary to make SimConnect.h recognize DWORDS.
#include <Windows.h>
// SimConnect.h interfaces the SimConnect library.
#include "SimConnect.h"
// In/output stream interface.
#include <iostream>

HRESULT hr;
HANDLE hSimconnect;

SIMCONNECT_CLIENT_DATA_ID ClientDataID = 1;
DWORD dwSize = 8;

// Reference to user aircraft.
SIMCONNECT_OBJECT_ID objectID = SIMCONNECT_OBJECT_ID_USER;

// Note that there is no practical reason to specifically assign enum values.

static enum DATA_DEFINE_ID {
    DEFINITION_1 = 12,
};

static enum DATA_REQUEST_ID {
    REQUEST_1 = 10,
};

static enum EVENT_ID {
    EVENT_1 = 1,
    EVENT_WASM = 2,
};

static enum GROUP_ID {
    GROUP_A = 1,
};

// Definition of the client data area format
double data = 1.;

// SimConnect dispatch routine.
void CALLBACK dispatchRoutine(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext) {
    printf("Dispatch ID = %d.\n", pData->dwID);
    DWORD receivedID = pData->dwID;
    switch (receivedID)
    {
    case SIMCONNECT_RECV_ID_OPEN: {

        break;
    }
    case SIMCONNECT_RECV_ID_CLIENT_DATA: {
        // Cast incoming data into interpretable format for this event.
        SIMCONNECT_RECV_CLIENT_DATA* pObjData = (SIMCONNECT_RECV_CLIENT_DATA*)pData;

        // Obtain the client data area contents in the expected format.
        double* pUserData = (double*)&pObjData->dwData;

        // For demonstration, the actual data value is pointed to by pUserData.
        double myData = *pUserData;
        
        printf("Request ID = %d.\n", pObjData->dwRequestID);
        printf("Received client data = %f.\n", *pUserData);
        break;
    }
    default:
        break;
    }
}

int main()
{
    std::cout << "Simconnect Client Data Area testing.\n";

    // Open the connection.
    hr = SimConnect_Open(&hSimconnect, "EFIS", nullptr, 0, 0, 0);
    if (S_OK == hr) {
        std::cout << "Connected to the Simulator.\n";
        /**************** SET UP a CLIENT DATA AREA ******************/
        
        // Map an ID to the Client Data Area.
        hr = SimConnect_MapClientDataNameToID(hSimconnect, "EFIS_CDA", ClientDataID);
        
        // Add a double to the data definition.
        hr &= SimConnect_AddToClientDataDefinition(hSimconnect, DEFINITION_1, SIMCONNECT_CLIENTDATAOFFSET_AUTO, sizeof(data));

        // Set up a custom Client Data Area.
        hr &= SimConnect_CreateClientData(hSimconnect, ClientDataID, sizeof(data), SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED);

        // Request the client data periodically.
        hr &= SimConnect_RequestClientData(hSimconnect, ClientDataID, REQUEST_1, DEFINITION_1, SIMCONNECT_CLIENT_DATA_PERIOD_SECOND, SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_DEFAULT);

        /*************** REQUEST DATA FROM THE AIRCRAFT ***************/
        // Trigger custom user event #0x11020. This should set the A32NX RANGE into the Client data area.
        //hr = SimConnect_MapClientEventToSimEvent(hSimconnect, EVENT_1, "#0x11020");

        // Instead, can I add this event into a notification group so I won't risk overlapping #-code?
        // In the LVAR module I should then have a dispatch procedure that is looking for this notification?
        hr = SimConnect_MapClientEventToSimEvent(hSimconnect, EVENT_WASM, "LVAR_ACCESS.EFIS");
        hr = SimConnect_AddClientEventToNotificationGroup(hSimconnect, GROUP_A, EVENT_WASM, true);
        hr = SimConnect_SetNotificationGroupPriority(hSimconnect, GROUP_A, SIMCONNECT_GROUP_PRIORITY_HIGHEST);

        /*************** RUN THE DISPATCH *****************************/
        if (S_OK == hr) {
            std::cout << "Setup client data area: OK.\n";
            // Set initial client data.
            hr = SimConnect_SetClientData(hSimconnect, ClientDataID, DEFINITION_1, SIMCONNECT_CLIENT_DATA_SET_FLAG_DEFAULT, 0, sizeof(data), &data);
            int quit = 0;
            while (!quit) {
                // Perform callback routine.
                SimConnect_CallDispatch(hSimconnect, dispatchRoutine, NULL);
                
                // Wait for data from the WASM.
                SimConnect_TransmitClientEvent(hSimconnect, objectID, EVENT_WASM, 2, SIMCONNECT_GROUP_PRIORITY_HIGHEST, SIMCONNECT_EVENT_FLAG_GROUPID_IS_PRIORITY);
                
                // Take it easy, no need to rush these events.
                Sleep(1000);
            }
           
        }
    }
    else {
        std::cout << "Error: Not connected to the Simulator.\n";
    }


    // Clear the client data area.
    SimConnect_ClearClientDataDefinition(hSimconnect, DEFINITION_1);
    // Close the connection.
    SimConnect_Close(hSimconnect);

    system("PAUSE");
}
