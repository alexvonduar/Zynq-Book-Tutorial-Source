% Input audio file
audio = 'original_speech.wav';
[sampled_audio, fs] = audioread(audio, [1 200000]);

samples = length(sampled_audio);

audio_in.signals.values = sampled_audio(:,1);
audio_in.time =[];