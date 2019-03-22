//
//  MQAudio.h
//  MapQuest
//  Copyright (c) 2013 MapQuest, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MQAudioDelegate;
@class AVAudioPlayer;
@class AVSpeechSynthesizer;
@class AVSpeechUtterance;

// Navigation Recording
extern NSString* const MQNavRecordingUtteranceNotification;

@interface MQAudio : NSObject

@property (nonatomic, assign) BOOL useHFP;
@property(nonatomic, weak) id<MQAudioDelegate> delegate;

+ (MQAudio *)sharedInstance;

- (void)speakText:(NSString *)text interrupt:(BOOL)interrupt volume:(float)volume;
- (void)setVolume:(float)volume;
- (void)playAudioData:(NSData *)audioData;
- (void)stopAudioAndSpeechPlayback;
- (void)forceStopSession;
- (BOOL)isSpeaking;
- (void)enableVolumeRockerControl;
- (void)startAudioSessionForMovie;
- (BOOL)stopAudioSession;
@end


@protocol MQAudioDelegate <NSObject>

@optional

-(void)didFailInitialization;
-(void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag;
-(void)speechSynthesizer:(AVSpeechSynthesizer *)synthesizer didFinishSpeechUtterance:(AVSpeechUtterance *)utterance;


@end
