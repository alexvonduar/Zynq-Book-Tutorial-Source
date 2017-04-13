% Uncomment chosen audio source for playback

%  Original input audio
% player=audioplayer(sampled_audio(:),44100);

% LMS filtered audio
% player=audioplayer(filtered_audio(:),fs);

% Tonal noise corrupted audio
% player=audioplayer(corrupt_audio(:),fs);

% Plat chosen audio source
play(player);