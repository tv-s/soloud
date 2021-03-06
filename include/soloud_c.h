/* **************************************************
 *  WARNING: this is a generated file. Do not edit. *
 *  Any edits will be overwritten by the generator. *
 ************************************************** */

/*
SoLoud audio engine
Copyright (c) 2013 Jari Komppa

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

/* SoLoud C-Api Code Generator (c)2013 Jari Komppa http://iki.fi/sol/ */

#ifndef SOLOUD_C_H_INCLUDED
#define SOLOUD_C_H_INCLUDED

#ifdef  __cplusplus
extern "C" {
#endif
// Collected enumerations
enum SOLOUD_ENUMS
{
	SOLOUD_CLIP_ROUNDOFF = 1,
	SOLOUD_ENABLE_VISUALIZATION = 2,
	BIQUADRESONANTFILTER_NONE = 0,
	BIQUADRESONANTFILTER_LOWPASS = 1,
	BIQUADRESONANTFILTER_HIGHPASS = 2,
	BIQUADRESONANTFILTER_BANDPASS = 3,
	BIQUADRESONANTFILTER_SAMPLERATE = 0,
	BIQUADRESONANTFILTER_FREQUENCY = 1,
	BIQUADRESONANTFILTER_RESONANCE = 2,
	BIQUADRESONANTFILTER_WET = 3,
	FFTFILTER_OVER = 0,
	FFTFILTER_SUBSTRACT = 1,
	FFTFILTER_MULTIPLY = 2
};

// Object handle typedefs
typedef void * Soloud;
typedef void * AudioSource;
typedef void * BiquadResonantFilter;
typedef void * Bus;
typedef void * EchoFilter;
typedef void * Fader;
typedef void * FFTFilter;
typedef void * Filter;
typedef void * Speech;
typedef void * Wav;
typedef void * WavStream;

/*
 * Soloud
 */
void Soloud_destroy(Soloud * aSoloud);
Soloud * Soloud_create();
void Soloud_deinit(Soloud * aSoloud);
int Soloud_play(Soloud * aSoloud, AudioSource * aSound);
int Soloud_playEx(Soloud * aSoloud, AudioSource * aSound, float aVolume /* = 1.0f */, float aPan /* = 0.0f */, int aPaused /* = 0 */, int aBus /* = 0 */);
void Soloud_seek(Soloud * aSoloud, int aVoiceHandle, float aSeconds);
void Soloud_stop(Soloud * aSoloud, int aVoiceHandle);
void Soloud_stopAll(Soloud * aSoloud);
void Soloud_stopSound(Soloud * aSoloud, AudioSource * aSound);
void Soloud_setFilterParameter(Soloud * aSoloud, int aVoiceHandle, int aFilterId, int aAttributeId, float aValue);
float Soloud_getFilterParameter(Soloud * aSoloud, int aVoiceHandle, int aFilterId, int aAttributeId);
void Soloud_fadeFilterParameter(Soloud * aSoloud, int aVoiceHandle, int aFilterId, int aAttributeId, float aTo, float aTime);
void Soloud_oscillateFilterParameter(Soloud * aSoloud, int aVoiceHandle, int aFilterId, int aAttributeId, float aFrom, float aTo, float aTime);
float Soloud_getStreamTime(Soloud * aSoloud, int aVoiceHandle);
int Soloud_getPause(Soloud * aSoloud, int aVoiceHandle);
float Soloud_getVolume(Soloud * aSoloud, int aVoiceHandle);
float Soloud_getPan(Soloud * aSoloud, int aVoiceHandle);
float Soloud_getSamplerate(Soloud * aSoloud, int aVoiceHandle);
int Soloud_getProtectVoice(Soloud * aSoloud, int aVoiceHandle);
int Soloud_getActiveVoiceCount(Soloud * aSoloud);
int Soloud_isValidVoiceHandle(Soloud * aSoloud, int aVoiceHandle);
float Soloud_getRelativePlaySpeed(Soloud * aSoloud, int aVoiceHandle);
float Soloud_getPostClipScaler(Soloud * aSoloud);
float Soloud_getGlobalVolume(Soloud * aSoloud);
void Soloud_setGlobalVolume(Soloud * aSoloud, float aVolume);
void Soloud_setPostClipScaler(Soloud * aSoloud, float aScaler);
void Soloud_setPause(Soloud * aSoloud, int aVoiceHandle, int aPause);
void Soloud_setPauseAll(Soloud * aSoloud, int aPause);
void Soloud_setRelativePlaySpeed(Soloud * aSoloud, int aVoiceHandle, float aSpeed);
void Soloud_setProtectVoice(Soloud * aSoloud, int aVoiceHandle, int aProtect);
void Soloud_setSamplerate(Soloud * aSoloud, int aVoiceHandle, float aSamplerate);
void Soloud_setPan(Soloud * aSoloud, int aVoiceHandle, float aPan);
void Soloud_setPanAbsolute(Soloud * aSoloud, int aVoiceHandle, float aLVolume, float aRVolume);
void Soloud_setVolume(Soloud * aSoloud, int aVoiceHandle, float aVolume);
void Soloud_fadeVolume(Soloud * aSoloud, int aVoiceHandle, float aTo, float aTime);
void Soloud_fadePan(Soloud * aSoloud, int aVoiceHandle, float aTo, float aTime);
void Soloud_fadeRelativePlaySpeed(Soloud * aSoloud, int aVoiceHandle, float aTo, float aTime);
void Soloud_fadeGlobalVolume(Soloud * aSoloud, float aTo, float aTime);
void Soloud_schedulePause(Soloud * aSoloud, int aVoiceHandle, float aTime);
void Soloud_scheduleStop(Soloud * aSoloud, int aVoiceHandle, float aTime);
void Soloud_oscillateVolume(Soloud * aSoloud, int aVoiceHandle, float aFrom, float aTo, float aTime);
void Soloud_oscillatePan(Soloud * aSoloud, int aVoiceHandle, float aFrom, float aTo, float aTime);
void Soloud_oscillateRelativePlaySpeed(Soloud * aSoloud, int aVoiceHandle, float aFrom, float aTo, float aTime);
void Soloud_oscillateGlobalVolume(Soloud * aSoloud, float aFrom, float aTo, float aTime);
void Soloud_setGlobalFilter(Soloud * aSoloud, int aFilterId, Filter * aFilter);
float * Soloud_calcFFT(Soloud * aSoloud);
float * Soloud_getWave(Soloud * aSoloud);
int Soloud_sdl_init(Soloud * aSoloud);
int Soloud_sdl_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 2048 */);
int Soloud_openal_init(Soloud * aSoloud);
int Soloud_openal_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 2048 */);
int Soloud_portaudio_init(Soloud * aSoloud);
int Soloud_portaudio_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 2048 */);
int Soloud_winmm_init(Soloud * aSoloud);
int Soloud_winmm_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 4096 */);
int Soloud_xaudio2_init(Soloud * aSoloud);
int Soloud_xaudio2_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 2048 */);
int Soloud_wasapi_init(Soloud * aSoloud);
int Soloud_wasapi_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 4096 */);
int Soloud_oss_init(Soloud * aSoloud);
int Soloud_oss_initEx(Soloud * aSoloud, int aFlags /* = Soloud::CLIP_ROUNDOFF */, int aSamplerate /* = 44100 */, int aBuffer /* = 2048 */);

/*
 * BiquadResonantFilter
 */
void BiquadResonantFilter_destroy(BiquadResonantFilter * aBiquadResonantFilter);
BiquadResonantFilter * BiquadResonantFilter_create();
void BiquadResonantFilter_setParams(BiquadResonantFilter * aBiquadResonantFilter, int aType, float aSampleRate, float aFrequency, float aResonance);

/*
 * Bus
 */
void Bus_destroy(Bus * aBus);
Bus * Bus_create();
void Bus_setFilter(Bus * aBus, int aFilterId, Filter * aFilter);
int Bus_play(Bus * aBus, AudioSource * aSound);
int Bus_playEx(Bus * aBus, AudioSource * aSound, float aVolume /* = 1.0f */, float aPan /* = 0.0f */, int aPaused /* = 0 */);
void Bus_setLooping(Bus * aBus, int aLoop);

/*
 * EchoFilter
 */
void EchoFilter_destroy(EchoFilter * aEchoFilter);
EchoFilter * EchoFilter_create();
void EchoFilter_setParams(EchoFilter * aEchoFilter, float aDelay, float aDecay);

/*
 * FFTFilter
 */
void FFTFilter_destroy(FFTFilter * aFFTFilter);
FFTFilter * FFTFilter_create();
void FFTFilter_setParameters(FFTFilter * aFFTFilter, int aShift);
void FFTFilter_setParametersEx(FFTFilter * aFFTFilter, int aShift, int aCombine /* = 0 */, float aScale /* = 0.002 */);

/*
 * Speech
 */
void Speech_destroy(Speech * aSpeech);
Speech * Speech_create();
void Speech_setText(Speech * aSpeech, char * aText);
void Speech_setLooping(Speech * aSpeech, int aLoop);
void Speech_setFilter(Speech * aSpeech, int aFilterId, Filter * aFilter);

/*
 * Wav
 */
void Wav_destroy(Wav * aWav);
Wav * Wav_create();
void Wav_load(Wav * aWav, const char * aFilename);
void Wav_loadMem(Wav * aWav, unsigned char * aMem, int aLength);
void Wav_setLooping(Wav * aWav, int aLoop);
void Wav_setFilter(Wav * aWav, int aFilterId, Filter * aFilter);

/*
 * WavStream
 */
void WavStream_destroy(WavStream * aWavStream);
WavStream * WavStream_create();
void WavStream_load(WavStream * aWavStream, const char * aFilename);
void WavStream_setLooping(WavStream * aWavStream, int aLoop);
void WavStream_setFilter(WavStream * aWavStream, int aFilterId, Filter * aFilter);
#ifdef  __cplusplus
} // extern "C"
#endif

#endif // SOLOUD_C_H_INCLUDED

