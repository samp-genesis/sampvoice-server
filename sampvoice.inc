#if defined _sampvoice_included
    #endinput
#endif
#define _sampvoice_included

#define SV_VERSION      11

#define NULL            0
#define INFINITY        -1

enum SvOption
{
    OPTION_FREQUENCY = 1,
    OPTION_VOLUME    = 2,
    OPTION_PANNING   = 3,
    OPTION_EAXMIX    = 4,
    OPTION_SRC       = 8
}

#define string:
#define void:

#define SvStream:
#define SvGStream:
#define SvLStream:
#define SvLPstream:
#define SvSLstream:
#define SvDLstream:
#define SvEffect:

native void:SvDebug(bool:mode);
native void:SvInit(bitrate);
native SvGetVersion(playerid);

native bool:SvHasMicro(playerid);
native bool:SvStartRecord(playerid);
native bool:SvStopRecord(playerid);
native bool:SvAddKey(playerid, keyid);
native bool:SvHasKey(playerid, keyid);
native bool:SvRemoveKey(playerid, keyid);
native void:SvRemoveAllKeys(playerid);
native bool:SvMutePlayerStatus(playerid);
native void:SvMutePlayerEnable(playerid);
native void:SvMutePlayerDisable(playerid);

native SvGstream:SvCreateGStream(color = NULL, string:name[] = "");
native SvLPstream:SvCreateSLStreamAtPoint(Float:distance, Float:posx, Float:posy, Float:posz, color = NULL, string:name[] = "");
native SvSLstream:SvCreateSLStreamAtVehicle(Float:distance, vehicleid, color = NULL, string:name[] = "");
native SvSLstream:SvCreateSLStreamAtPlayer(Float:distance, playerid, color = NULL, string:name[] = "");
native SvSLstream:SvCreateSLStreamAtObject(Float:distance, objectid, color = NULL, string:name[] = "");
native SvLPstream:SvCreateDLStreamAtPoint(Float:distance, maxplayers, Float:posx, Float:posy, Float:posz, color = NULL, string:name[] = "");
native SvDLstream:SvCreateDLStreamAtVehicle(Float:distance, maxplayers, vehicleid, color = NULL, string:name[] = "");
native SvDLstream:SvCreateDLStreamAtPlayer(Float:distance, maxplayers, playerid, color = NULL, string:name[] = "");
native SvDLstream:SvCreateDLStreamAtObject(Float:distance, maxplayers, objectid, color = NULL, string:name[] = "");
native void:SvUpdateDistanceForLStream(SvLstream:lstream, Float:distance);
native void:SvUpdatePositionForLPStream(SvLPstream:lpstream, Float:posx, Float:posy, Float:posz);
native bool:SvAttachListenerToStream(SvStream:stream, playerid);
native bool:SvHasListenerInStream(SvStream:stream, playerid);
native bool:SvDetachListenerFromStream(SvStream:stream, playerid);
native void:SvDetachAllListenersFromStream(SvStream:stream);
native bool:SvAttachSpeakerToStream(SvStream:stream, playerid);
native bool:SvHasSpeakerInStream(SvStream:stream, playerid);
native bool:SvDetachSpeakerFromStream(SvStream:stream, playerid);
native void:SvDetachAllSpeakersFromStream(SvStream:stream);
native void:SvStreamParameterSet(SvStream:stream, SvOption:option, Float:value);
native void:SvStreamParameterReset(SvStream:stream, SvOption:option);
native bool:SvStreamParameterHas(SvStream:stream, SvOption:option);
native Float:SvStreamParameterGet(SvStream:stream, SvOption:option);
native void:SvStreamParameterSlideFromTo(SvStream:stream, SvOption:option, Float:startvalue, Float:endvalue, time);
native void:SvStreamParameterSlideTo(SvStream:stream, SvOption:option, Float:endvalue, time);
native void:SvStreamParameterSlide(SvStream:stream, SvOption:option, Float:deltavalue, time);
native void:SvDeleteStream(SvStream:stream);

native SvEffect:SvEffectCreateChorus(priority, Float:wetdrymix, Float:depth, Float:feedback, Float:frequency, waveform, Float:delay, phase);
native SvEffect:SvEffectCreateCompressor(priority, Float:gain, Float:attack, Float:release, Float:threshold, Float:ratio, Float:predelay);
native SvEffect:SvEffectCreateDistortion(priority, Float:gain, Float:edge, Float:posteqcenterfrequency, Float:posteqbandwidth, Float:prelowpasscutoff);
native SvEffect:SvEffectCreateEcho(priority, Float:wetdrymix, Float:feedback, Float:leftdelay, Float:rightdelay, bool:pandelay);
native SvEffect:SvEffectCreateFlanger(priority, Float:wetdrymix, Float:depth, Float:feedback, Float:frequency, waveform, Float:delay, phase);
native SvEffect:SvEffectCreateGargle(priority, ratehz, waveshape);
native SvEffect:SvEffectCreateI3dl2reverb(priority, room, roomhf, Float:roomrollofffactor, Float:decaytime, Float:decayhfratio, reflections, Float:reflectionsdelay, reverb, Float:reverbdelay, Float:diffusion, Float:density, Float:hfreference);
native SvEffect:SvEffectCreateParameq(priority, Float:center, Float:bandwidth, Float:gain);
native SvEffect:SvEffectCreateReverb(priority, Float:ingain, Float:reverbmix, Float:reverbtime, Float:highfreqrtratio);
native void:SvEffectAttachStream(SvEffect:effect, SvStream:stream);
native void:SvEffectDetachStream(SvEffect:effect, SvStream:stream);
native void:SvEffectDelete(SvEffect:effect);

forward void:OnPlayerActivationKeyPress(playerid, keyid);
forward void:OnPlayerActivationKeyRelease(playerid, keyid);
