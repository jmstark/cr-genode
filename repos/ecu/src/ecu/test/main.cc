#include <iostream>
#include <string>

#include <base/printf.h>
#include <ecu_api/CoreAPI.h>
#include <ecu_api/ErrorCodes.h>
#include <ecu_api/Defines.h>
#include <timer_session/connection.h>

using namespace std;

int main(int argc, char *argv[])
{
	PDBG("Hello, ECU is ready to begin.\n");

	int status = RQ_SUCCESS, var = 100;
	// Create the Core
	PDBG("Initializing core.\n");
	CoreAPI* core = new CoreAPI(CONNECTION_COM);

	// Example Setter
	PDBG("Setting motor speed to %d.\n", var);
	if ((status = core->SetMotorSpeedAbs(var)) != RQ_SUCCESS)
	{
		PDBG("Error SetCommand Failed: %d\n", status);
	}
	// Example Getter
	PDBG("Getting MCU Temperature.\n");
	if ((status = core->GetMCUTemperature(var)) != RQ_SUCCESS)
	{
		PDBG("Error SetCommand Failed: %d\n", status);
	}
	PDBG("MCU Temperature: %d\n", var);

	// Load Config
	string version, firmware;
	int index = 2;
	int EMOD, EPPR, ELL, EHL, EHOME, ELLA, EHLA, DINL, DINA, AMOD, AINA, AMIN, ACTR, AMAX, APOL, ADB, AMINA, AMAXA, AMS;
	int PMOD, PINA, PMIN, PCTR, PMAX, PDB, PMINA, PMAXA, DOL, DOA, PWMF, OVL, UVL, BKD, THLD, BPOL, BLFB, BLSTD, BLL;
	int BHL, BHOME, BLLA, BHLA, ALIM, ATRIG, ATGA, ATGD, MXPF, MXPR, MXRPM, MAC, MDEC, MMOD, MVEL, MXTRN, KP, KI, KD, ICAP, CLERD;
	int tmpM, tmpC, BatVolt, ContVolt, VOut, rpm, rel, motAmps;
	if ((status = core->SetAnalogCenterSafety(false)) != RQ_SUCCESS)           PDBG("Error Setting Value: %d\n", status);
	if ((status = core->GetMotorTemperature(tmpM)) != RQ_SUCCESS)            PDBG("Error reading Motor Temp: %d \n", status);
	if ((status = core->GetMCUTemperature(tmpC)) != RQ_SUCCESS)             PDBG("Error reading Controller Temp: %d \n", status);
	if ((status = core->GetBatteryVolt(BatVolt)) != RQ_SUCCESS)             PDBG("Error reading Battery Voltage: %d\n", status);
	if ((status = core->GetControllerVolt(ContVolt)) != RQ_SUCCESS)           PDBG("Error reading Controller Voltage: %d\n", status);
	if ((status = core->Get5VOutput(VOut)) != RQ_SUCCESS)                PDBG("Error reading 5V Output: %d\n", status);
	if ((status = core->GetMotorRPM(rpm)) != RQ_SUCCESS)                 PDBG("Error Motor RPM: %d\n", status);
	if ((status = core->GetMotorPower(rel)) != RQ_SUCCESS)                PDBG("Error Motor Power: %d\n", status);
	if ((status = core->GetMotorAmps(motAmps)) != RQ_SUCCESS)              PDBG("Error reading Motor Amps %d\n", status);
	if ((status = core->GetMotorControllerFirmware(firmware)) != RQ_SUCCESS)       PDBG("Error Getting Firmware %d\n", status);
	if ((status = core->GetMotorControllerType(version)) != RQ_SUCCESS)         PDBG("Error Getting Version %d\n", status);
	if ((status = core->GetAnalogMinMaxSafety(AMS)) != RQ_SUCCESS)            PDBG("Error AMS %d\n", status);
	if ((status = core->GetEncoderMode(MOT1, EMOD)) != RQ_SUCCESS)            PDBG("Error EMOD %d\n", status);
	if ((status = core->GetEncoderPPR(EPPR)) != RQ_SUCCESS)               PDBG("Error EPPR %d\n", status);
	if ((status = core->GetEncoderLowLimitCount(ELL)) != RQ_SUCCESS)           PDBG("Error ELL %d\n", status);
	if ((status = core->GetEncoderHighLimitCount(EHL)) != RQ_SUCCESS)          PDBG("Error EHL %d\n", status);
	if ((status = core->GetEncoderCounterLoadAtHomePosition(EHOME)) != RQ_SUCCESS)    PDBG("Error EHOME %d\n", status);
	if ((status = core->GetEncoderLowLimitAction(MOT1, ELLA)) != RQ_SUCCESS)       PDBG("Error ELLA %d\n", status);
	if ((status = core->GetEncoderHighLimitAction(MOT1, EHLA)) != RQ_SUCCESS)      PDBG("Error EHLA %d\n", status);
	if ((status = core->GetDigitalInput(index, DINL)) != RQ_SUCCESS)           PDBG("Error DINL %d\n", status);
	if ((status = core->GetDigitalInputAction(index, DINA_MOT1, DINA)) != RQ_SUCCESS)  PDBG("Error DINA %d\n", status);
	if ((status = core->GetAnalogInputMode(index, AMOD)) != RQ_SUCCESS)         PDBG("Error AMOD %d\n", status);
	if ((status = core->GetAnalogInputAction(index, AINA)) != RQ_SUCCESS)        PDBG("Error AINA %d\n", status);
	if ((status = core->GetAnalogInputMin(index, AMIN)) != RQ_SUCCESS)          PDBG("Error AMIN %d\n", status);
	if ((status = core->GetAnalogInputCenter(index, ACTR)) != RQ_SUCCESS)        PDBG("Error ACTR %d\n", status);
	if ((status = core->GetAnalogInputMax(index, AMAX)) != RQ_SUCCESS)          PDBG("Error AMAX %d\n", status);
	if ((status = core->GetAnalogInputPolarity(index, APOL)) != RQ_SUCCESS)       PDBG("Error APOL %d\n", status);
	if ((status = core->GetAnalogDeadband(index, ADB)) != RQ_SUCCESS)          PDBG("Error ADB %d\n", status);
	if ((status = core->GetAnalogMinAction(index, AMINA)) != RQ_SUCCESS)         PDBG("Error AMINA %d\n", status);
	if ((status = core->GetAnalogMaxAction(index, AMAXA)) != RQ_SUCCESS)         PDBG("Error AMAXA%d\n", status);
	if ((status = core->GetPulseInputMode(index, PMOD) ) != RQ_SUCCESS)         PDBG("Error PMOD%d\n", status);
	if ((status = core->GetPulseInputAction(index, MOT1, PINA) ) != RQ_SUCCESS)     PDBG("Error PINA%d\n", status);
	if ((status = core->GetPulseMin(index, PMIN) ) != RQ_SUCCESS)            PDBG("Error PMIN%d\n", status);
	if ((status = core->GetPulseCenter(index, PCTR) ) != RQ_SUCCESS)           PDBG("Error PCTR%d\n", status);
	if ((status = core->GetPulseMax(index, PMAX) ) != RQ_SUCCESS)            PDBG("Error PMAX%d\n", status);
	if ((status = core->GetPulseDeadbeand(index, PDB) ) != RQ_SUCCESS)          PDBG("Error PDB%d\n", status);
	if ((status = core->GetPulseMinAction(index, MOT1, PMINA) ) != RQ_SUCCESS)      PDBG("Error PMINA%d\n", status);
	if ((status = core->GetPulseMaxAction(index, MOT1, PMAXA) ) != RQ_SUCCESS)      PDBG("Error PMAXA%d\n", status);
	if ((status = core->GetDigitalOutputActiveLevel(index, DOL) ) != RQ_SUCCESS)     PDBG("Error DOL%d\n", status);
	if ((status = core->GetDigitalOutputAction(index, MOT1, DOA) ) != RQ_SUCCESS)    PDBG("Error PMOD%d\n", status);
	if ((status = core->GetPWMFrequency(PWMF) ) != RQ_SUCCESS)              PDBG("Error PWMF%d\n", status);
	if ((status = core->GetOvervoltageLimit(OVL) ) != RQ_SUCCESS)            PDBG("Error PMOD%d\n", status);
	if ((status = core->GetUndervoltageLimit(UVL) ) != RQ_SUCCESS)            PDBG("Error UVL%d\n", status);
	if ((status = core->GetBrakeActivationDelay(BKD) ) != RQ_SUCCESS)          PDBG("Error BKD%d\n", status);
	if ((status = core->GetShortCircuitThreshold(THLD) ) != RQ_SUCCESS)         PDBG("Error THLD%d\n", status);
	if ((status = core->GetNumPoles(1, BPOL) ) != RQ_SUCCESS)            PDBG("Error BPOL%d\n", status);
	if ((status = core->GetBrushlessFeedback(1, BLFB) ) != RQ_SUCCESS)        PDBG("Error BLFB%d\n", status);
	if ((status = core->GetBrushlessStallDetection(1, BLSTD) ) != RQ_SUCCESS)    PDBG("Error BLSTD%d\n", status);
	if ((status = core->GetEncoderLowLimit(1, BLL) ) != RQ_SUCCESS)         PDBG("Error BLL%d\n", status);
	if ((status = core->GetEncoderHighLimit(1, BHL) ) != RQ_SUCCESS)         PDBG("Error BHL%d\n", status);
	if ((status = core->GetBrushlessHomeCounter(1, BHOME) ) != RQ_SUCCESS)      PDBG("Error BHOME%d\n", status);
	if ((status = core->GetEncoderLowLimitAction(1, MOT1, BLLA) ) != RQ_SUCCESS)   PDBG("Error BLLA%d\n", status);
	if ((status = core->GetEncoderHighLimitAction(1, MOT1, BHLA) ) != RQ_SUCCESS)   PDBG("Error BHLA%d\n", status);
	if ((status = core->GetMotorAmpsLimit(ALIM) ) != RQ_SUCCESS)             PDBG("Error ALIM%d\n", status);
	if ((status = core->GetMotorAmpsTriggerValue(ATRIG) ) != RQ_SUCCESS)         PDBG("Error ATRIG%d\n", status);
	if ((status = core->GetMotorAmpsTriggerAction(MOT1, ATGA) ) != RQ_SUCCESS)      PDBG("Error ATGA%d\n", status);
	if ((status = core->GetMotorAmpsTriggerDelay(ATGD) ) != RQ_SUCCESS)         PDBG("Error ATGD%d\n", status);
	if ((status = core->GetMotorMaxPowerForward(MXPF) ) != RQ_SUCCESS)          PDBG("Error MXPF%d\n", status);
	if ((status = core->GetMotorMaxPowerReverse(MXPR) ) != RQ_SUCCESS)          PDBG("Error MXPR%d\n", status);
	if ((status = core->GetMotorMaxRPM(MXRPM) ) != RQ_SUCCESS)             PDBG("Error MXRPM%d\n", status);
	if ((status = core->GetAcceleration(MAC) ) != RQ_SUCCESS)              PDBG("Error MAC%d\n", status);
	if ((status = core->GetDeacceleration(MDEC) ) != RQ_SUCCESS)            PDBG("Error MDEC%d\n", status);
	if ((status = core->GetMotorOperatingMode(MMOD) ) != RQ_SUCCESS)           PDBG("Error MMOD%d\n", status);
	if ((status = core->GetMotorDefaultVelocity(MVEL) ) != RQ_SUCCESS)          PDBG("Error MVEL%d\n", status);
	if ((status = core->GetMotorMaxTurns(MXTRN) ) != RQ_SUCCESS)             PDBG("Error MXTRN%d\n", status);
	if ((status = core->GetProportionalGain(KP) ) != RQ_SUCCESS)             PDBG("Error KP%d\n", status);
	if ((status = core->GetIntegrationalGain(KI) ) != RQ_SUCCESS)            PDBG("Error KI%d\n", status);
	if ((status = core->GetDifferentialGain(KD) ) != RQ_SUCCESS)             PDBG("Error KD%d\n", status);
	if ((status = core->GetMotorIntCap(ICAP) ) != RQ_SUCCESS)              PDBG("Error ICAP%d\n", status);
	if ((status = core->GetLoopErrorMode(CLERD) ) != RQ_SUCCESS)             PDBG("Error CLERD%d\n", status);

	cout << "---------------------------------" << endl;
	PDBG("Action on AMS: %d\n", AMS);
	PDBG("Action on EMOD: %d\n", EMOD);
	PDBG("Action on EPPR: %d\n", EPPR);
	PDBG("Action on ELL: %d\n", ELL);
	PDBG("Action on EHL: %d\n", EHL);
	PDBG("Action on EHOME: %d\n", EHOME);
	PDBG("Action on ELLA: %d\n", ELLA);
	PDBG("Action on EHLA: %d\n", EHLA);
	PDBG("Action on DINL: %d\n", DINL);
	PDBG("Action on DINA: %d\n", DINA);
	PDBG("Action on AMOD: %d\n", AMOD);
	PDBG("Action on AINA: %d\n", AINA);
	PDBG("Action on AMIN: %d\n", AMIN);
	PDBG("Action on ACTR: %d\n", ACTR);
	PDBG("Action on AMAX: %d\n", AMAX);
	PDBG("Action on APOL: %d\n", APOL);
	PDBG("Action on ADB: %d\n", ADB);
	PDBG("Action on AMINA: %d\n", AMINA);
	PDBG("Action on AMAX: %d\n", AMAXA);
	PDBG("Action on PMOD: %d\n", PMOD);
	PDBG("Action on PINA: %d\n", PINA);
	PDBG("Action on PMIN: %d\n", PMIN);
	PDBG("Action on PCTR: %d\n", PCTR);
	PDBG("Action on PMAX: %d\n", PMAX);
	PDBG("Action on PDB: %d\n", PDB);
	PDBG("Action on PMINA: %d\n", PMINA);
	PDBG("Action on PMAXA: %d\n", PMAXA);
	PDBG("Action on DOL: %d\n", DOL);
	PDBG("Action on DOA: %d\n", DOA);
	PDBG("Action on PWMF: %d\n", PWMF);
	PDBG("Action on OVL: %d\n", OVL);
	PDBG("Action on UVL: %d\n", UVL);
	PDBG("Action on BKD: %d\n", BKD);
	PDBG("Action on THLD: %d\n", THLD);
	PDBG("Action on BPOL: %d\n", BPOL);
	PDBG("Action on BLFB: %d\n", BLFB);
	PDBG("Action on BLSTD: %d\n", BLSTD);
	PDBG("Action on BLL: %d\n", BLL);
	PDBG("Action on BHL: %d\n", BHL);
	PDBG("Action on BHOME: %d\n", BHOME);
	PDBG("Action on BLLA: %d\n", BLLA);
	PDBG("Action on BHLA: %d\n", BHLA);
	PDBG("Action on ALIM: %d\n", ALIM);
	PDBG("Action on ATRIG: %d\n", ATRIG);
	PDBG("Action on ATGA: %d\n", ATGA);
	PDBG("Action on ATGD: %d\n", ATGD);
	PDBG("Action on MXPF: %d\n", MXPF);
	PDBG("Action on MXPR: %d\n", MXPR);
	PDBG("Action on MXRPM: %d\n", MXRPM);
	PDBG("Action on MAC: %d\n", MAC);
	PDBG("Action on MDEC: %d\n", MDEC);
	PDBG("Action on MMOD: %d\n", MMOD);
	PDBG("Action on MVEL: %d\n", MVEL);
	PDBG("Action on MXTRN: %d\n", MXTRN);
	PDBG("Action on KP: %d\n", KP);
	PDBG("Action on KI: %d\n", KI);
	PDBG("Action on KD: %d\n", KD);
	PDBG("Action on ICAP: %d\n", ICAP);
	PDBG("Action on CLERD: %d\n", CLERD);
	PDBG("---------------------------------\n");
	PDBG("Motorcontroler: %s\n", version.c_str());
	PDBG("Firmware: %s\n", firmware.c_str());
	PDBG("Temp Motor: %d \t Temp MCU: %d \n", tmpM, tmpC);
	PDBG("Bat Volts %d \t Controller Volt %d \t 5V Out %d\n", BatVolt, ContVolt, VOut );
	PDBG("RPM: %d \t Power: %d \t Motor Amps: %d \n", 1, rel, motAmps );

	delete core;

	return 0;
}
