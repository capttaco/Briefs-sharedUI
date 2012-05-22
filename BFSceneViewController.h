//
//  SceneViewController.h
//  Briefs
//
//  Created by Rob Rhyne on 7/17/09.
//  Copyright Digital Arch Design, 2009. See LICENSE file for details.
//

#import <UIKit/UIKit.h>
#import "BFSceneManager.h"
#import "BFSceneView.h"

@protocol BFSceneViewDelegate;
@interface BFSceneViewController : UIViewController 
{
    BFSceneManager          *dataManager;
    BFSceneView             *current_scene;
    id<BFSceneViewDelegate> __unsafe_unretained delegate;
}

@property (nonatomic) BFSceneManager    *dataManager;
@property (nonatomic) BFSceneView       *current_scene;
@property (unsafe_unretained) id<BFSceneViewDelegate>      delegate;

- (id)initWithSceneManager:(BFSceneManager*)manager;

// Local Dispatch Methods
- (BOOL)willLoadSceneWithIndex:(int)index;
- (BOOL)willLoadSceneWithIndex:(int)index usingTransition:(NSString *)transition;
- (BOOL)willToggleActorWithIndex:(int)index;
- (BOOL)willResizeActorWithIndex:(int)index toSize:(CGSize)size;
- (BOOL)willMoveActorWithIndex:(int)index toPoint:(CGPoint)point;
- (BOOL)willShowActorWithIndex:(int)index;
- (BOOL)willHideActorWithIndex:(int)index;


// Global Dispatch Methods
- (BOOL)willShowKeyboard:(NSString *)type;
- (void)willStopShowingScene;

// Convenience Methods
- (void)performTransition:(NSString *)transition onEnteringView:(BFSceneView *)entering removingOldView:(BFSceneView *)exiting;

@end


@protocol BFSceneViewDelegate
- (void)sceneView:(BFSceneViewController *)controller shouldDismissView:(BOOL)animated;
@end

