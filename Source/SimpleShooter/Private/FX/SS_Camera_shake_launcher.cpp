// Fill out your copyright notice in the Description page of Project Settings.

#include "FX/SS_Camera_shake_launcher.h"


USS_Camera_shake_launcher::USS_Camera_shake_launcher()
{
	// Oscillation Values.
	OscillationDuration                = 0.6f;
	OscillationBlendInTime             = 0.1f;
	OscillationBlendOutTime            = 0.2f;

	// RotOscillation Values.
	RotOscillation.Pitch.Amplitude     = 3.f;
	RotOscillation.Pitch.Frequency     = 10.f;
	RotOscillation.Pitch.InitialOffset = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Pitch.Waveform      = EOscillatorWaveform::SineWave;

	RotOscillation.Yaw.Amplitude       = 1.f;
	RotOscillation.Yaw.Frequency       = 10.f;
	RotOscillation.Yaw.InitialOffset   = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Yaw.Waveform        = EOscillatorWaveform::SineWave;

	RotOscillation.Roll.Amplitude      = 0.f;
	RotOscillation.Roll.Frequency      = 0.f;
	RotOscillation.Roll.InitialOffset  = EInitialOscillatorOffset::EOO_OffsetRandom;
	RotOscillation.Roll.Waveform       = EOscillatorWaveform::SineWave;

	// LocOscillation Values.
	LocOscillation.X.Amplitude         = 0.f;
	LocOscillation.X.Frequency         = 0.f;
	LocOscillation.X.InitialOffset     = EInitialOscillatorOffset::EOO_OffsetRandom;
	LocOscillation.X.Waveform          = EOscillatorWaveform::SineWave;

	LocOscillation.Y.Amplitude         = 2.f;
	LocOscillation.Y.Frequency         = 10.f;
	LocOscillation.Y.InitialOffset     = EInitialOscillatorOffset::EOO_OffsetRandom;
	LocOscillation.Y.Waveform          = EOscillatorWaveform::SineWave;

	LocOscillation.Z.Amplitude         = 2.f;
	LocOscillation.Z.Frequency         = 10.f;
	LocOscillation.Z.InitialOffset     = EInitialOscillatorOffset::EOO_OffsetRandom;
	LocOscillation.Z.Waveform          = EOscillatorWaveform::SineWave;
}
