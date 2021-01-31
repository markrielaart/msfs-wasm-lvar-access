#include <MSFS/MSFS_WindowsTypes.h>
#include <MSFS/MSFS.h>
#include <MSFS/Legacy/gauges.h>

PCSTRINGZ LVAR_EFIS_PANEL[] = {
	"XMLVAR_Baro1_Mode",
	"XMLVAR_Baro_Selector_HPA_1",
	"A320_Neo_MFD_NAV_MODE_1",
	"A320_Neo_MFD_Range_1",
	"A320_Neo_MFD_NAV_MODE_2",
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

// MCDU Button calculator codes.
PCSTRINGZ MCDU_BUTTONS[] = {
	"(>H:A320_Neo_CDU_1_BTN_0)",
	"(>H:A320_Neo_CDU_1_BTN_1)",
	"(>H:A320_Neo_CDU_1_BTN_2)",
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
	"(>H:A320_Neo_CDU_1_BTN_SP)",
	"(>H:A320_Neo_CDU_1_BTN_DIV)",
	"(>H:A320_Neo_CDU_1_BTN_OVFY)",
	"(>H:A320_Neo_CDU_1_BTN_CLR)",
	"(>H:A320_Neo_CDU_1_BTN_BRT_S1)", // Experimental brightness increase (INOP)
	"(>H:A320_Neo_CDU_1_BTN_DIM_S2)", // Experimental brightness decrease (INOP).
	"(>H:A320_Neo_CDU_1_BTN_DOT)",
};


// Define the SimConnect custom eventHandler.
static void FSAPI EventHandler(ID32 event, UINT32 evdata, PVOID userdata) {
	// Any event number from 0x11000 through 0x1FFFF is available, but might collide with other mods.
	switch (event) {
	case 0x11000: {
		// Press MCDU button DIR
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
	}
}

// This is called when the WASM is loaded into the system.
extern "C" MSFS_CALLBACK void module_init(void) {
	register_key_event_handler((GAUGE_KEY_EVENT_HANDLER)EventHandler, NULL);
}

extern "C" MSFS_CALLBACK void module_deinit(void) {
	unregister_key_event_handler((GAUGE_KEY_EVENT_HANDLER)EventHandler, NULL);
}


