#include <MSFS/MSFS_WindowsTypes.h>
#include <MSFS/MSFS.h>
#include <MSFS/Legacy/gauges.h>
#include "SimConnect.h"

PCSTRINGZ LVAR_EFIS_PANEL[] = {		// Index
	"XMLVAR_Baro1_Mode",			// 0
	"XMLVAR_Baro_Selector_HPA_1",	// 1
	"A320_Neo_MFD_NAV_MODE_1",		// 2
	"A320_Neo_MFD_Range_1",			// 3
	"A320_Neo_MFD_NAV_MODE_2",		// etc.
	"A320_Neo_MFD_Range_2",
	"BTN_CSTR_1_FILTER_ACTIVE",
	"BTN_VORD_1_FILTER_ACTIVE",
	"BTN_WPT_1_FILTER_ACTIVE",
	"BTN_NDB_1_FILTER_ACTIVE",
	"BTN_ARPT_1_FILTER_ACTIVE",
	"BTN_CSTR_2_FILTER_ACTIVE",
	"BTN_VORD_2_FILTER_ACTIVE",
	"BTN_WPT_2_FILTER_ACTIVE",
	"BTN_NDB_2_FILTER_ACTIVE",
	"BTN_ARPT_2_FILTER_ACTIVE",
	"A32NX_METRIC_ALT_TOGGLE",
	"XMLVAR_NAV_AID_SWITCH_L1_State",
	"XMLVAR_NAV_AID_SWITCH_L2_State",
	"XMLVAR_NAV_AID_SWITCH_R1_State",
	"XMLVAR_NAV_AID_SWITCH_R2_State",
	"PUSH_AUTOPILOT_CHRONO_L",
	"PUSH_AUTOPILOT_CHRONO_R",
};

/*
PCSTRINGZ LVAR_EFIS_B747_PANEL[] = {
	"XMLVAR_Mins_Selector_Baro",
	"B747_8_MFD_NAV_MODE",
	"B747_8_MFD_Range",
	"BTN_WX_ACTIVE",
	"BTN_NDB_FILTER_ACTIVE",
	"BTN_WPT_FILTER_ACTIVE",
	"BTN_ARPT_FILTER_ACTIVE",
	"", // Reserved for DAT button
	"BTN_VORD_FILTER_ACTIVE",
	"BTN_TERRONND", // Terrain on ND
	"BTN_NDB_FILTER_ACTIVE",
	"XMLVAR_NAV_AID_SWITCH_L1_State",
	"XMLVAR_NAV_AID_SWITCH_L2_State",
	"XMLVAR_NAV_AID_SWITCH_R1_State",
	"XMLVAR_NAV_AID_SWITCH_R2_State",
};
*/

// MCDU Button calculator codes.
PCSTRINGZ MCDU_BUTTONS[] = {		// Index
	"(>H:A320_Neo_CDU_1_BTN_0)",	// 0
	"(>H:A320_Neo_CDU_1_BTN_1)",	// 1
	"(>H:A320_Neo_CDU_1_BTN_2)",	// etc.
	"(>H:A320_Neo_CDU_1_BTN_3)",
	"(>H:A320_Neo_CDU_1_BTN_4)",
	"(>H:A320_Neo_CDU_1_BTN_5)",
	"(>H:A320_Neo_CDU_1_BTN_6)",
	"(>H:A320_Neo_CDU_1_BTN_7)",
	"(>H:A320_Neo_CDU_1_BTN_8)",
	"(>H:A320_Neo_CDU_1_BTN_9)",
	"(>H:A320_Neo_CDU_1_BTN_A)",
	"(>H:A320_Neo_CDU_1_BTN_B)",
	"(>H:A320_Neo_CDU_1_BTN_C)",
	"(>H:A320_Neo_CDU_1_BTN_D)",
	"(>H:A320_Neo_CDU_1_BTN_E)",
	"(>H:A320_Neo_CDU_1_BTN_F)",
	"(>H:A320_Neo_CDU_1_BTN_G)",
	"(>H:A320_Neo_CDU_1_BTN_H)",
	"(>H:A320_Neo_CDU_1_BTN_I)",
	"(>H:A320_Neo_CDU_1_BTN_J)",
	"(>H:A320_Neo_CDU_1_BTN_K)",
	"(>H:A320_Neo_CDU_1_BTN_L)",
	"(>H:A320_Neo_CDU_1_BTN_M)",
	"(>H:A320_Neo_CDU_1_BTN_N)",
	"(>H:A320_Neo_CDU_1_BTN_O)",
	"(>H:A320_Neo_CDU_1_BTN_P)",
	"(>H:A320_Neo_CDU_1_BTN_Q)",
	"(>H:A320_Neo_CDU_1_BTN_R)",
	"(>H:A320_Neo_CDU_1_BTN_S)",
	"(>H:A320_Neo_CDU_1_BTN_T)",
	"(>H:A320_Neo_CDU_1_BTN_U)",
	"(>H:A320_Neo_CDU_1_BTN_V)",
	"(>H:A320_Neo_CDU_1_BTN_W)",
	"(>H:A320_Neo_CDU_1_BTN_X)",
	"(>H:A320_Neo_CDU_1_BTN_Y)",
	"(>H:A320_Neo_CDU_1_BTN_Z)",
	"(>H:A320_Neo_CDU_1_BTN_DIR)",
	"(>H:A320_Neo_CDU_1_BTN_PROG)",
	"(>H:A320_Neo_CDU_1_BTN_PERF)",
	"(>H:A320_Neo_CDU_1_BTN_INIT)",
	"(>H:A320_Neo_CDU_1_BTN_DATA)",
	"(>H:A320_Neo_CDU_1_BTN_FPLN)",
	"(>H:A320_Neo_CDU_1_BTN_NAVRAD)",
	"(>H:A320_Neo_CDU_1_BTN_FUEL)",
	"(>H:A320_Neo_CDU_1_BTN_SEC)",
	"(>H:A320_Neo_CDU_1_BTN_ATC)",
	"(>H:A320_Neo_CDU_1_BTN_MENU)",
	"(>H:A320_Neo_CDU_1_BTN_AIRPORT)",
	"(>H:A320_Neo_CDU_1_BTN_UP)",
	"(>H:A320_Neo_CDU_1_BTN_DOWN)",
	"(>H:A320_Neo_CDU_1_BTN_PREVPAGE)",
	"(>H:A320_Neo_CDU_1_BTN_NEXTPAGE)",
	"(>H:A320_Neo_CDU_1_BTN_L1)",
	"(>H:A320_Neo_CDU_1_BTN_L2)",
	"(>H:A320_Neo_CDU_1_BTN_L3)",
	"(>H:A320_Neo_CDU_1_BTN_L4)",
	"(>H:A320_Neo_CDU_1_BTN_L5)",
	"(>H:A320_Neo_CDU_1_BTN_L6)",
	"(>H:A320_Neo_CDU_1_BTN_R1)",
	"(>H:A320_Neo_CDU_1_BTN_R2)",
	"(>H:A320_Neo_CDU_1_BTN_R3)",
	"(>H:A320_Neo_CDU_1_BTN_R4)",
	"(>H:A320_Neo_CDU_1_BTN_R5)",
	"(>H:A320_Neo_CDU_1_BTN_R6)",
	"(>H:A320_Neo_CDU_1_BTN_PLUSMINUS)",
	"(>H:A320_Neo_CDU_1_BTN_SP)",		// Space
	"(>H:A320_Neo_CDU_1_BTN_DIV)",		// Slash
	"(>H:A320_Neo_CDU_1_BTN_OVFY)",
	"(>H:A320_Neo_CDU_1_BTN_CLR)",
	"(>H:A320_Neo_CDU_1_BTN_BRT_S1)", // Experimental brightness increase (INOP)
	"(>H:A320_Neo_CDU_1_BTN_DIM_S2)", // Experimental brightness decrease (INOP).
	"(>H:A320_Neo_CDU_1_BTN_DOT)",
};

PCSTRINGZ CJ4_BUTTONS[] = {
	"(>H:CJ4_FMC_1_BTN_A)",
	"(>H:CJ4_FMC_1_BTN_IDX)",
};

/* Attempt to get SimConnect_CLientDataArea functionality implemented. */
HRESULT hr;
HANDLE hSimConnect;

SIMCONNECT_CLIENT_DATA_ID ClientDataID = 1;
DWORD dwSize = 8;

static enum DATA_DEFINE_ID {
	DEFINITION_1 = 12,
};

static enum DATA_REQUEST_ID {
	REQUEST_1 = 10,
};

static enum EVENT_ID {
	EVENT_RANGE = 1,
};

static enum GROUP_ID {
	GROUP_A = 1,
};
// Definition of the client data area format
double data = 1.;



// Define the SimConnect custom eventHandler.
/* This can be replaced by the DispatchHandler below. */
/** 
static void FSAPI EventHandler(ID32 event, UINT32 evdata, PVOID userdata) {
	// Any event number from 0x11000 through 0x1FFFF is available, but might collide with other mods.
	switch (event) {
	case 0x11000: {
		// Press MCDU button DIR
		FLOAT64* a;
		SINT32* b;
		PCSTRINGZ* c;
		//execute_calculator_code("(>H:A320_Neo_CDU_1_BTN_DIR)", a, b, c);
		execute_calculator_code(MCDU_BUTTONS[evdata], nullptr, nullptr, nullptr);
		break;
	}
	case 0x11001: {
		// EFIS Panel modes
		UINT8 LVAR_INDEX = (evdata & 0xFF);
		ID idA320 = check_named_variable(LVAR_EFIS_PANEL[LVAR_INDEX]);
		// Set a value
		FLOAT64 LVAR_VALUE = (evdata & 0xFF00) >> 8;
		set_named_variable_value(idA320, LVAR_VALUE);
		break;
	}
	case 0x11010: {
		// Press MCDU button DIR
		FLOAT64* a;
		SINT32* b;
		PCSTRINGZ* c;
		execute_calculator_code(CJ4_BUTTONS[evdata], nullptr, nullptr, nullptr);
		break;
	}
	case 0x11020: {
		// Experimental LVAR read back.
		ID lvarID = check_named_variable(LVAR_EFIS_PANEL[3]); // A32NX Range 1 (0...5).
		// Get the value
		FLOAT64 lvarValue;
		lvarValue = get_named_variable_value(lvarID);
		// Now, where to send it?
		fprintf(stderr, "Range 1 value = %f.\n", lvarValue);
		
		data = lvarValue;
		SimConnect_SetClientData(hSimConnect, ClientDataID, DEFINITION_1, SIMCONNECT_CLIENT_DATA_SET_FLAG_DEFAULT, 0, sizeof(data), &data);
		
	}
	
	}
}
**/

// Define a SimConnect callback handler for custom events.
void CALLBACK myDispatchHandler(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext) {
	// Check for any incoming custom events.
	DWORD requestID = pData->dwID;
	switch (requestID) {
	case SIMCONNECT_RECV_ID_EVENT: {
		SIMCONNECT_RECV_EVENT* evt = (SIMCONNECT_RECV_EVENT*)pData;
		// Detect what event was triggered.
		switch (evt->uEventID) {
		  // This is just to demonstrate access to the LVAR_EFIS_PANEL array.
      case EVENT_RANGE: {
			// RANGE, return the current RANGE setting.
			UINT32 evData = evt->dwData;
			fprintf(stderr, "Event data number = %i", evData);
			ID lvarID = check_named_variable(LVAR_EFIS_PANEL[evData]); // A32NX Range 1 (0...5).
			// Get the value
			FLOAT64 lvarValue;
			lvarValue = get_named_variable_value(lvarID);
			data = lvarValue;
			SimConnect_SetClientData(hSimConnect, ClientDataID, DEFINITION_1, SIMCONNECT_CLIENT_DATA_SET_FLAG_DEFAULT, 0, sizeof(data), &data);
			break;
		}
		default: {
			// No default for now.
			break;
		}
		}
		}
	}
}



// This is called when the WASM is loaded into the system.
extern "C" MSFS_CALLBACK void module_init(void) {
	register_key_event_handler((GAUGE_KEY_EVENT_HANDLER)EventHandler, NULL);
	
	/* SimConnect_ClientDataArea attempt. */
	hr = SimConnect_Open(&hSimConnect, "Standalone Module", nullptr, 0, 0, 0);
	if (hr == S_OK)
	{
		fprintf(stderr, "WASM lvar-access module initialized.");
		// Map an ID to the Client Data Area.
		hr = SimConnect_MapClientDataNameToID(hSimConnect, "EFIS_CDA", ClientDataID);

		// Add a double to the data definition.
		hr &= SimConnect_AddToClientDataDefinition(hSimConnect, DEFINITION_1, SIMCONNECT_CLIENTDATAOFFSET_AUTO, sizeof(data));

		// Set up a custom Client Data Area.
		hr &= SimConnect_CreateClientData(hSimConnect, ClientDataID, sizeof(data), SIMCONNECT_CLIENT_DATA_REQUEST_FLAG_CHANGED);

		/******* Define custom user events. *******/
		// Make the dispatch sensitive to the RANGE event.
		hr &= SimConnect_MapClientEventToSimEvent(hSimConnect, EVENT_RANGE, "LVAR_ACCESS.EFIS");
		hr &= SimConnect_AddClientEventToNotificationGroup(hSimConnect, GROUP_A, EVENT_RANGE, true);
		hr &= SimConnect_SetNotificationGroupPriority(hSimConnect, GROUP_A, SIMCONNECT_GROUP_PRIORITY_HIGHEST);

		// Define the callback handler.
		SimConnect_CallDispatch(hSimConnect, myDispatchHandler, NULL);
	}

}

extern "C" MSFS_CALLBACK void module_deinit(void) {
	unregister_key_event_handler((GAUGE_KEY_EVENT_HANDLER)EventHandler, NULL);
	SimConnect_Close(hSimConnect);
}


