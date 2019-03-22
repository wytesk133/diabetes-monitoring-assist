//
//  MQNavigationManagerPromptDelegate.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

@class MQNavigationManager;
@class MQPrompt;

/**
 The MQNavigationManagerPromptDelegate protocol defines the methods that a delegate of an MQNavigationManager object can implement to handle prompts to speak the upcoming maneuvers
 */
@protocol MQNavigationManagerPromptDelegate <NSObject>

@required

/**
 Called when a prompt advice should be spoken
 
 @param navigationManager Object informing the delegate of this impending event
 @param promptToSpeak Prompt object that should be spoken at the earliest
 @param userInitiated Indicates when the spoken prompt was initiated by the user
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager receivedPrompt:(nonnull MQPrompt *)promptToSpeak userInitiated:(BOOL)userInitiated;

/**
 Called when you should stop any advice being spoken. Happens when the user is off route
 
 @param navigationManager navigationManager object informing the delegate of this impending event
 */
- (void)cancelPromptsForNavigationManager:(nonnull MQNavigationManager *)navigationManager;

@end

